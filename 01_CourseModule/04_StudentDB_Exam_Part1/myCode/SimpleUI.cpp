/*
 * SimpleUI.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <map>
#include <utility>

#include <Poco/Data/Date.h>
#include <Poco/DateTime.h>
#include <Poco/Data/Time.h>
#include <boost/algorithm/string/find.hpp>

#include "WeeklyCourse.h"
#include "BlockCourse.h"
#include "Address.h"
#include "Student.h"
#include "Enrollment.h"
#include "SimpleUI.h"

using namespace std;

SimpleUI::SimpleUI(StudentDb& db): sdb(&db)
{

}

void SimpleUI::addNewCourse(){

	static unsigned int num=0;
	string coursetitle="NA", major="NA",stime,etime,semester;
	unsigned char courseType = 0;
	unsigned int courseKey = 0,yr=0,m=0,d=0,hr=0,min=0;
	float creditPoints = 0;

	cout<<endl<<"Provide Course Details........."<<endl;
	cout<<" Name of the course : ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, coursetitle);
	cout<<" Course belongs to which major ? (Automation or Communication or Embedded or Power) : ";
	cin>> major;
	cout<<" How many credit points for this course ? Enter 2.5 or 5 : ";
	cin>> semester;
	cout<<" Which semester? : ";
	cin>> creditPoints;
	cout<<" Is it a Weekly or Block Course? Enter W or B : ";
	cin>> courseType;
	cout<<" What is the Course Key? ";
	cin>> courseKey;
	cout<<" Enter the start time (in the FORMAT hr:min) : ";
	cin>>stime;
	this->sdb->setTime(stime,hr,min);
	Poco::Data::Time startTime(hr, min, 0);
	cout<<" Enter the end time (in the FORMAT hr:min) : ";
	cin>>etime;
	this->sdb->setTime(etime,hr,min);
	Poco::Data::Time endTime(hr,min, 0);

	if(courseType=='W'){
		unsigned int dayIndex=0;
		Poco::DateTime::DaysOfWeek dayOfWeek;
		cout<<" On which days of the week is the course held ? Enter 1(MONDAY) to 5(FRIDAY) : ";
		cin>>dayIndex;
		dayOfWeek = Poco::DateTime::DaysOfWeek(dayIndex);

		unique_ptr<Course> wcourse (new WeeklyCourse(coursetitle,courseKey,major,semester,creditPoints,dayOfWeek,startTime,endTime));
		this->sdb->addCourses(num,wcourse); num++;
		cout<<" ------------Weekly course created and added into the DB------------ "<<endl;

	}
	if(courseType=='B')
	{
		string sdate, edate;
		cout<<" Enter the start date of the course (FORMAT dd/mm/year): ";
		cin>>sdate;
		this->sdb->setDate(sdate,yr,m,d);
		Poco::Data::Date startDate(yr,m,d);
		cout<<" Enter the end date of the course (FORMAT dd/mm/year): ";
		cin>>edate;
		this->sdb->setDate(edate,yr,m,d);
		Poco::Data::Date endDate(yr,m,d);

		unique_ptr<Course> bcourse(new BlockCourse(coursetitle,courseKey,major,semester,creditPoints,startDate,endDate,startTime,endTime));
		this->sdb->addCourses(num,bcourse); num++;
		cout<<" ------------Block course created and added into the DB------------ "<<endl;
	}

}

void SimpleUI::listallCourses(){

	cout<<endl<<sdb->getCourses().size()<<" Courses are available..........."<<endl;
	for (auto &c : sdb->getCourses())
	{
		int num = c.first; cout<<num+1<<") ";
		const Course &course = *c.second.get();
		course.print();
	}

}


static void updateAddress(Address &stAdrs){

	string street = " ",cityName = " ", additionalInfo = " ";
	unsigned short postalCode = 0;
	unsigned char additionalInfoNec = 'N';

	cout<<"Enter the street No : ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, street);
	cout<<"Enter the city Name : ";
	cin>>cityName;
	cout<<"Enter the Postal Code : ";
	cin>>postalCode;
	cout<<"Is any additional line necessary ? (Y/N) ";
	cin>>additionalInfoNec;cout<<" ";
	if(additionalInfoNec == 'Y' || additionalInfoNec=='y'){
		cout<<" Enter additional info (if any) : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin,additionalInfo);
	}
	stAdrs = Address(street,postalCode,cityName,additionalInfo);
}

void SimpleUI::addNewStudent(){

	string firstName = ".", lastName = ".",date;
	unsigned int yr=0,m=0,d=0;
	Address stAdrs;

	cout<<endl<<"Provide the Student Details.............."<<endl;
	cout<<"Enter the First Name of the Student : ";
	cin>>firstName;
	cout<<"Enter the Last Name of the Student : ";
	cin>>lastName;
	cout<<"Enter the Date of Birth (FORMAT dd.mm.year): ";
	cin>>date;
	this->sdb->setDate(date,yr,m,d);
	Poco::Data::Date dOB(yr,m,d);
	cout<<"Provide the Student's Address : "<<endl;

	updateAddress(stAdrs);

	Student st(firstName,lastName,dOB,stAdrs);
	this->sdb->addStudent(st);
}

void SimpleUI::addEnrollemnt(){
	unsigned int matrikelNumber = 0, courseKey = 0;
	string semester;
	bool courseFound= false, studentFound = false;
	cout<<endl<<"Provide the Enrollment Details............."<<endl;
	cout<<"Enter the student's Matriculation number : "; cin>>matrikelNumber;

	map<int, Student> stListCopy = sdb->getStudents();
	for(pair<int, Student> element : stListCopy )
	{
		if(matrikelNumber == element.second.getMatrikelNumber())
		{
			studentFound=true;
			cout<<"Enter the semester : "; cin>>semester;
			cout<<"Enter a course Id : "; cin>>courseKey;

			for (auto &c : sdb->getCourses())
			{
				const Course &course = *c.second.get();
				if(courseKey == course.getCourseKey())
				{
					courseFound = true;
					Enrollment enroll(&course, semester);
					bool alreadyPresent = sdb->getStudentById(matrikelNumber).addEnrollments(enroll);
					if(alreadyPresent==true)
						cout<<"!!!WARNING!!!--------!!!Enrollment already Present!!!"<<endl;
					break;
				}
			}
			if(courseFound!=true){
				cout<<"No course available with the given key ID."<<endl;
			}
			break;
		}
	}
	if(studentFound!=true){
		cout<<"No student available with the given MatriklNum."<<endl;
	}
	cout<<"Enrollment added "<<endl;
}

void SimpleUI::printStudentInfo(){

	unsigned int matrikelNumber = 0; int searchCount=0;
	bool studentFound = false;
	cout<<endl<<"Displaying Student Info............"<<endl;
	cout<<"Enter the student's Matriculation number : "; cin>>matrikelNumber;

	map<int, Student> stListCopy = sdb->getStudents();
	if(stListCopy.size()!=0)
	{
		for(pair<int, Student> element : stListCopy )
		{
			searchCount++;
			if(matrikelNumber == element.second.getMatrikelNumber()){

				studentFound=true;
				cout << " Name : "<<element.second.getFirstName()<< " "<<element.second.getLastName()<<endl;
				cout << " Date of Birth : "<<element.second.getDateOfBirth().day()<<"/"<<element.second.getDateOfBirth().month()
											<<"/"<<element.second.getDateOfBirth().year()<<endl;
				cout<< " Enrolled Course Details : "<<endl;
				vector<Enrollment> enrol = element.second.getEnrollments();
				if(enrol.size()!=0){
					for (Enrollment iter : enrol){


						const Course *course = iter.getCourse();
						cout<<"   Course : "<<course->getTitle()<<" ( "<<course->getCourseKey()<<" )"<<endl;
						cout<<"          CreditPoints for the course : "<<course->getCreditPoints()<<endl;
						cout<<"          Semester : "<<iter.getSemester()<<endl;
						cout<<"          Grades Obtained : "<<iter.getGrade()<<endl;
					}
				}
				else{
					cout<<"   No Enrollments available for this student."<<endl<<endl;
				}
				break;
			}
			else {
				// details of all students checked and no student with matching Matrkl.Num found
				if(searchCount==(stListCopy.end()->first) && studentFound!=true)
					cout<<"   No student found with the given Matrikl Number."<<endl<<endl;
			}
		}
	}
	else{
		cout<<"    No Student info available in the DataBase.";
	}
}

void SimpleUI::searchForAStudent(){
	string name;
	bool stFound = false; int searchCount=0;
	cout<<endl<<"Searching for a Student ..........."<<endl;
	cout<<"Enter the name to be looked for : ";
	cin>>name;

	boost::iterator_range<std::string::const_iterator> found_firstname,found_secondname;

	map<int, Student> stListCopy = sdb->getStudents();
	for(pair<int, Student> element : stListCopy )
	{
		searchCount++;
		found_firstname = boost::ifind_first(element.second.getFirstName(), name);
		found_secondname = boost::ifind_first(element.second.getLastName(), name);

		if(found_firstname || found_secondname){

			cout<<" matrikelNumber : "<<element.second.getMatrikelNumber()<<endl;
			cout<<" Name : "<<element.second.getFirstName()<< " "<<element.second.getLastName()<<endl<<endl;
			stFound = true;
		}
		else {
			if((searchCount==(stListCopy.end()->first)) && (stFound!=true))
				cout<< " No data found"<<endl<<endl;
		}
	}
}

void SimpleUI::updateStudentInfo(){

	unsigned int matrikelNumber = 0, choice = 0; bool studentFound; int searchCount=0;
	cout<<endl<<"Update Student Info............"<<endl;
	cout<<"Enter the student's Matriculation number : "; cin>>matrikelNumber;

	map<int, Student> stListCopy = sdb->getStudents();
	for(pair<int, Student> element : stListCopy )
	{
		searchCount++;
		if(matrikelNumber == element.second.getMatrikelNumber()){
			studentFound = true;
			cout<<endl<<"The following can be modified "<<endl;
			cout<<" 1. First Name"<<endl<<" 2. Last Name"<<endl<<" 3. Date of Birth"<<endl;
			cout<<" 4. Address"<<endl<<" 5. Delete an Enrollment"<<endl<<" 6. Enter a Mark"<<endl<<"Enter your choice : ";
			cin>>choice;
			switch(choice)
			{
			case 1:{
				string firstName;
				cout<<endl<<"Enter the correct First Name : "; cin>>firstName;
				sdb->getStudentById(matrikelNumber).setFirstName(firstName);
				break;}
			case 2:{
				string lastName;
				cout<<endl<<"Enter the correct First Name : "; cin>>lastName;
				sdb->getStudentById(matrikelNumber).setLastName(lastName);
				break;}
			case 3:{
				unsigned int yr,m,d;string date;
				cout<<endl<<"Enter the correct Date of Birth (FORMAT dd.mm.yyyy) : ";
				cin>>date;
				this->sdb->setDate(date,yr,m,d);
				Poco::Data::Date dOB(yr,m,d);
				sdb->getStudentById(matrikelNumber).setDateOfBirth(dOB);
				break;}
			case 4:{
				Address newAdrs;
				cout<<endl<<"Enter the new Address"<<endl;
				updateAddress(newAdrs);
				sdb->getStudentById(matrikelNumber).setAddress(newAdrs);
				break;}
			case 5:{
				unsigned int count=0;
				vector<Enrollment> enrol = element.second.getEnrollments();
				cout<<endl<<"The following enrollments are available"<<endl;
				if(enrol.size()!=0){
					for (Enrollment iter : enrol){
						const Course *course = iter.getCourse();
						cout<<count+1 << " "<<course->getTitle()<<" ( "<<course->getCourseKey()<<" )";
						cout<<"   "<<course->getCreditPoints()<<" CP"<<endl;
					}
					cout<<endl<<"Which enrollment count to delete? "; cin>>count;
					enrol.erase(enrol.begin()+count-1);
					sdb->getStudentById(matrikelNumber).updateEnrollments(enrol);
				}
				else{
					cout<<"   No Enrollments available for this student."<<endl<<endl;
				}
				break;}
			case 6:{
				unsigned int count=0; float grade =0;
				vector<Enrollment> enrol = element.second.getEnrollments();
				cout<<endl<<"The following enrollments are available"<<endl;
				if(enrol.size()!=0){
					for (Enrollment iter : enrol){
						const Course *course = iter.getCourse();
						cout<<"	"<<count+1 <<"------> "<<course->getTitle()<<" ( ID "<<course->getCourseKey()<<" )";
						cout<<"   "<<course->getCreditPoints()<<" CP"<<endl;
					}
					cout<<"For which enrollment is the mark to be entered ? "; cin>>count;
					cout<<" Enter the grade : ";cin>>grade;
					enrol[count-1].setGrade(grade);
					sdb->getStudentById(matrikelNumber).updateEnrollments(enrol);
				}
				else{
					cout<<"   No Enrollments available for this student."<<endl<<endl;
				}
				break;}
			default : cout<<"Wrong choice! Try again"<<endl;
			}
			break;
		}
		else{
			if(searchCount==(stListCopy.end()->first) && studentFound!=true)
				cout<<" No student found with the given Matriculation number"<<endl<<endl;
		}
	}
}

void SimpleUI::writeToFile(){
	ofstream outfile;
	string filename;
	cout<<endl<<"Enter the file name to which data is to be written: ";
	cin>>filename;
	outfile.open(filename);
	this->sdb->write(outfile);
	outfile.close();
}

void SimpleUI::readFromFile(){
	ifstream infile;
	string filename;
	cout<<endl<<"Enter the file name from which data is to be read : ";
	cin>>filename;
	infile.open(filename);
	this->sdb->read(infile);
	infile.close();
}

void SimpleUI::run()
{
	unsigned int choice = 0;
	cout<<" Running the database...."<<endl;
	do{
		cout<<endl<<"The following options are available."<<endl;
		cout<<"1. Add new Course"<<endl<<"2. List courses"<<endl<<"3. Add new student"<<endl<<"4. Add enrollment"<<endl;
		cout<<"5. Print student"<<endl<<"6. Search for a student"<<endl<<"7. Update student"<<endl<<"8. Write to a File"<<endl;
		cout<<"9. Read from a File"<<endl<<"10. Get Data from Server"<<endl;
		cout<<"Enter any of the commands to execute(0 to exit): ";
		cin>>choice;
		switch(choice)
		{
		case 0:cout<<"End of session";break;
		case 1:addNewCourse();break;
		case 2:listallCourses();break;
		case 3:addNewStudent();break;
		case 4:addEnrollemnt();break;
		case 5:printStudentInfo();break;
		case 6:searchForAStudent();break;
		case 7:updateStudentInfo();break;
		case 8:writeToFile();break;
		case 9:readFromFile();break;
		case 10:sdb->copyDataFromServer();break;
		default : cout<<"Wrong choice! Try again"<<endl;
		}

	}  while(choice!=0);
}


SimpleUI::~SimpleUI()
{
	// Auto-generated destructor stub
}

