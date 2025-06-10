/*
 * StudentDb.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */
#include <vector>
#include <fstream>
#include <iostream>
#include "Poco/Net/SocketAddress.h"
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>

#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>

#include "StudentDb.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"
#include "Address.h"
#include "Student.h"
#include "Enrollment.h"

using namespace std;

StudentDb::StudentDb()
{

}

StudentDb::~StudentDb()
{

}


const std::map<int, std::unique_ptr<const Course> >& StudentDb::getCourses() const
{
	return courses;
}


const std::map<int, Student>& StudentDb::getStudents() const
{
	return students;
}

Student& StudentDb::getStudentById(unsigned int matrikelNumber)
{
	return(students.at(matrikelNumber));
}


void StudentDb::setTime(string &time, unsigned int &hr, unsigned int &min){
	unsigned int colonPos=0;
	for(unsigned int it = 0;it<time.length();it++){
		if(time[it]==':')
			colonPos=it;
	}
	hr = stoi(time.substr(0, colonPos));
	min = stoi(time.substr(colonPos+1, time.length()-1));

}

void StudentDb::setDate(string &date,unsigned int &yr,unsigned int &m,unsigned int &d){
	d=0,m=0,yr=0;
	unsigned int slashPos=0;
	for(unsigned int it = 0;it<date.length();it++){

		if(date[it]=='.' && m==0 && d!=0){
			m = stoi(date.substr(slashPos+1, it));
			slashPos = it;
		}
		if(date[it]=='.' && d==0){
			d = stoi(date.substr(0, it));
			slashPos = it;
		}
	}
	yr = stoi(date.substr(slashPos+1,date.length()-1));
}

void StudentDb::addStudent(const Student student)
{
	this->students.emplace(student.getMatrikelNumber(),student);
}

void StudentDb::addCourses(unsigned int &num, std::unique_ptr<Course> &coursename)
{
	this->courses.emplace(num, move(coursename));
}

void StudentDb::write(std::ostream &out)
{
	int totalEnrollmentCount = 0;
	int totalCourses = courses.end()->first;
	out<<totalCourses<<endl;
	for (auto &c : this->getCourses())
	{
		const Course &subject = *c.second.get();
		subject.write(out);
	}

	int totalStudents = students.end()->first;
	out<<totalStudents<<endl;
	for(pair<int, Student> element :this->students)
	{
		out<<element.second.getMatrikelNumber()<<";"<<element.second.getLastName()<<";"<<element.second.getFirstName()<<";";
		out<<element.second.getDateOfBirth().day()<<"."<<element.second.getDateOfBirth().month()<<".";
		out<<element.second.getDateOfBirth().year()<<";";
		out<<element.second.getAddress().getStreet()<<";"<<element.second.getAddress().getPostalCode()<<";";
		out<<element.second.getAddress().getCityName()<<";"<<element.second.getAddress().getAdditionalInfo()<<endl;

		totalEnrollmentCount=totalEnrollmentCount+element.second.getEnrollments().size();
	}
	out<<totalEnrollmentCount<<endl;
	for(pair<int, Student> element :this->students)
	{
		element.second.write(out);
	}
}

void StudentDb::readCourses(std::istream &in, unsigned int &totalCourses)
{
	for(unsigned int iter=0;iter<totalCourses;iter++){
		static unsigned int num=0;
		string coursetitle="NA", major="NA",temp;
		unsigned int courseKey = 0,yr=0,m=0,d=0,hr=0,min=0;
		float creditPoints = 0;
		Poco::DateTime::DaysOfWeek dayOfWeek;
		getline(in,temp,';');
		if(temp=="W")
		{
			getline(in,temp,';');
			courseKey = stoi(temp);
			getline(in,coursetitle,';');
			getline(in,major,';');
			getline(in,temp,';');
			creditPoints = stof(temp);
			getline(in,temp,';');
			dayOfWeek = Poco::DateTime::DaysOfWeek(stoi(temp));
			getline(in,temp,';');
			setTime(temp,hr,min);
			Poco::Data::Time startTime(hr, min, 0);
			getline(in,temp,'\n');
			setTime(temp,hr,min);
			Poco::Data::Time endTime(hr,min, 0);
			unique_ptr<Course> wcourse (new WeeklyCourse(coursetitle,courseKey,major,creditPoints,dayOfWeek,startTime,endTime));
			this->addCourses(num,wcourse); num++;
			cout<<" ------------Weekly course created and added into the DB------------ "<<endl;
		}
		if(temp=="B")
		{
			getline(in,temp,';');
			courseKey = stoi(temp);
			getline(in,coursetitle,';');
			getline(in,major,';');
			getline(in,temp,';');
			creditPoints = stof(temp);
			getline(in,temp,';');
			setDate(temp,yr,m,d);
			Poco::Data::Date startDate(yr,m,d);
			getline(in,temp,';');
			setDate(temp,yr,m,d);
			Poco::Data::Date endDate(yr,m,d);
			getline(in,temp,';');
			setTime(temp,hr,min);
			Poco::Data::Time startTime(hr, min, 0);
			getline(in,temp,'\n');
			setTime(temp,hr,min);
			Poco::Data::Time endTime(hr,min, 0);

			unique_ptr<Course> bcourse(new BlockCourse(coursetitle,courseKey,major,creditPoints,startDate,endDate,startTime,endTime));
			this->addCourses(num,bcourse); num++;
			cout<<" ------------Block course created and added into the DB------------ "<<endl;
		}
	}
}

void StudentDb::read(std::istream &in)
{
	this->students.clear();
	this->courses.clear();

	string courseCount , studentCount , enrollmentsCount,w1;
	unsigned int totalEnrollments = 0,totalCourses = 0, totalStudents =0;
	getline(in,courseCount);
	totalCourses = stoi(courseCount);
	readCourses(in, totalCourses);

	getline(in,studentCount);
	totalStudents= stoi(studentCount);
	for(unsigned int iter=0;iter<totalStudents;iter++){
		string firstName = ".", lastName = ".",temp,street = " ",cityName = " ", additionalInfo = " ";
		unsigned int yr=0,m=0,d=0; unsigned short postalCode = 0;
		getline(in,temp,';'); // Matriculation number - ignore
		getline(in,lastName,';');
		getline(in,firstName,';');
		getline(in,temp,';');
		setDate(temp,yr,m,d);
		Poco::Data::Date dOB(yr,m,d);
		getline(in,street,';');
		getline(in,temp,';');
		postalCode = stoi(temp);
		getline(in,cityName,';');
		getline(in,additionalInfo,'\n');
		Student st(firstName,lastName,dOB,Address(street,postalCode,cityName,additionalInfo));
		this->addStudent(st);
	}

	getline(in,enrollmentsCount);
	totalEnrollments= stoi(enrollmentsCount);
	for(unsigned int iter=0;iter<totalEnrollments;iter++){
		unsigned int matrikelNumber = 0, courseKey = 0;
		string semester,temp; float grade;
		getline(in,temp,';');
		matrikelNumber = stoi(temp);
		getline(in,temp,';');
		courseKey = stoi(temp);
		getline(in,semester,';');
		getline(in,temp,'\n');
		grade=stof(temp);
		for (auto &c : this->getCourses())
		{
			const Course &course = *c.second.get();
			if(courseKey == course.getCourseKey())
			{
				Enrollment enroll(&course, semester,grade);
				this->getStudentById(matrikelNumber).addEnrollments(enroll);
				break;
			}
		}
	}
}

void StudentDb::copyDataFromServer()
{
	unsigned int stCount = 0;
	vector <string> completeData;

	cout<<"Enter the number of students data to be retrieved from Server : ";
	cin>> stCount;

	try{
		for(unsigned int count =0; count<stCount;count++)
		{
			cout<<"For fetching Student "<<count+1<<" data...."<<endl;
			string jsonString, studentData;
			Poco::Net::SocketAddress sa("mnl.de", 4242); //stores an IPv4 or IPv6 host address
			Poco::Net::StreamSocket socket(sa);  //used for creating a TCP connection to a server.
			cout << "Connecting to Server...." << endl;
			Poco::Net::SocketStream str(socket); //provides an I/O streams interface to a StreamSocket.
			str<<"generate\n";
			str.flush();
			Poco::StreamCopier::copyToString(str, jsonString);
			str<<"quit\n";
			str.flush();

			istringstream issOject(jsonString);
			while(issOject)
			{
				getline(issOject,studentData,'\n');
				if(studentData[0]=='{') //Indicator of start of actual JSON Data
				{
					cout<<endl<<"Real Data to be processed obtained "<<endl<<studentData<<endl;
					completeData.push_back(studentData);
					break;
				}
			}
			str.close();
			socket.close();

		}
		if(completeData.size()!=0)
			serverToDB(completeData); // ADD to the Database
		else
			cerr<<"Data could not be retrieved... Some server problem...Try again later..."<<endl;

	}catch (Poco::Exception &e)
	{
		cerr << e.name() <<" caught. Problem message is - " <<e.message() <<endl;
	}

}

bool StudentDb::serverToDB(std::vector<std::string> & completeData)
{
	for(string studentData : completeData)
	{
		string firstName = ".", lastName = ".",temp,street = " ",cityName = " ", additionalInfo = " ";
		unsigned int yr=0,m=0,d=0; unsigned short postalCode = 0;

		Poco::JSON::Parser json_parser;
		Poco::Dynamic::Var result = json_parser.parse(studentData);
		Poco::JSON::Object::Ptr pObject = result.extract<Poco::JSON::Object::Ptr>();

		Poco::JSON::Object::Ptr nameObj = pObject->getObject("name");
		firstName = nameObj->get("firstName").toString();
		lastName = nameObj->get("lastName").toString();

		Poco::JSON::Object::Ptr dobObj = pObject->getObject("dateOfBirth");
		d = dobObj->get("date").convert<int>();
		m = dobObj->get("month").convert<int>();
		yr = dobObj->get("year").convert<int>();
		Poco::Data::Date dOB(yr,m,d);

		Poco::JSON::Object::Ptr adrsObj = pObject->getObject("location");
		cityName=adrsObj->get("city").toString();
		street=adrsObj->get("street").toString();
		additionalInfo=adrsObj->get("state").toString();
		//try{
		postalCode=adrsObj->get("postCode").convert<int>();
		//	}
		//	catch (Poco::Exception &e)
		//	{
		//		cerr << e.name() <<" caught. MESSAGE is - " <<e.message() <<endl;
		//		//return false;
		//		continue;
		//	}
		Student st(firstName,lastName,dOB,Address(street,postalCode,cityName,additionalInfo));
		this->addStudent(st);
	}
	cout<<endl<<"Student data added to DB "<<endl;
	return true;
}
