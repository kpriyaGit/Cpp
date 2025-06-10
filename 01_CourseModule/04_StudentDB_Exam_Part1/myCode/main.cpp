// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required

using namespace std;

// project's header files
#include "StudentDb.h"
#include "SimpleUI.h"

#include "WeeklyCourse.h"
#include "BlockCourse.h"

inline void assertTrue(bool condition, string failedMessage){
	if (!condition) {
	        cout << failedMessage << endl;
	    }
	else
	{
		cout<<"ALL OK"<<endl;
	}
}


// Main program
int main ()
{
	// Add your program code here
	cout << "WiSe2021_Part1 started." << endl << endl;
	/**
	 * Object for the student database class
	 */
	//StudentDb stDB;
	/**
	 * Object for SimpleUI class that takes parameter of type StudentDb
	 */
	//SimpleUI userIf(stDB);
	/**
	 * Start the application
	 */
	//userIf.run();
	string coursetitle="NA", major="NA";
	unsigned int courseKey =1234,yr=2022,m=10,d=20,hr=16,min=30,dayIndex=4;;
	float creditPoints = 0;
	Poco::Data::Date startDate(yr,m,d);
	Poco::Data::Date endDate(yr,m,d);
	Poco::Data::Time startTime(hr, min, 0);
	Poco::Data::Time endTime(hr,min, 0);
	Poco::DateTime::DaysOfWeek dayOfWeek= Poco::DateTime::DaysOfWeek(dayIndex);

	string semester = "SoSe2021";
	//string semester = "Some2022";
	//string semester = "WiSe20/21";
	//string semester = "Wise2024";
	//string semester = "SOSE2019";

	WeeklyCourse wcourse(coursetitle,courseKey,major,semester,creditPoints,dayOfWeek,startTime,endTime);
	//BlockCourse bcourse{coursetitle,courseKey,major,semester,creditPoints,startDate,endDate,startTime,endTime};

	assertTrue(wcourse.getSemester() == semester, " Semester incorrect! ");

	return 0;
}
