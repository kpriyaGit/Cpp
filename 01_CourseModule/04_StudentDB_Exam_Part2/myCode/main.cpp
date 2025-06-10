// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

// project's header files
#include "StudentDb.h"
#include "SimpleUI.h"
#include "Address.h"
#include "WeeklyCourse.h"
#include "Student.h"

// Main program
int main (void)
{

	cout << "APT_Lab3_StudentDatabase started." << endl << endl;
	/**
	 * Object for the student database class
	 */
	StudentDb stDB;
	/**
	 * Object for SimpleUI class that takes parameter of type StudentDb
	 */
	//SimpleUI userIf(stDB);
	/**
	 * Start the application
	 */
	//userIf.run();

	//string street = "Bergstrasse",cityName = "Heilbronn", additionalInfo = "landmark";
	//	unsigned short postalCode = 12345; unsigned int num=1;

	//EX 2.1
/*	Address stAdrs(street,postalCode,cityName,additionalInfo);
	//stAdrs.toJson().get()->stringify(cout, 2);
	WeeklyCourse* wcourse = new WeeklyCourse("APT",1122,"Automation",5,
			Poco::DateTime::WEDNESDAY,Poco::Data::Time(12, 30, 0),Poco::Data::Time(14, 00, 0));
	//wcourse->toJson().get()->stringify(cout, 2);
	Enrollment enroll(wcourse, "WiSe2022", 1.7);
	//enroll.toJson().get()->stringify(cout, 2);
	unique_ptr<Course> upwc(wcourse);

	Student st("Neela","Khanna",Poco::Data::Date(1996, 04, 07),stAdrs);
	st.addEnrollments(enroll);
	//st.toJson().get()->stringify(cout, 2);

	stDB.addStudent1(st);
	stDB.addCourses(num, upwc);
	//stDB.toJson().get()->stringify(cout, 2);
	//delete wcourse;
*/
	// EX 2.2 part 1
	/*Address stAdrs(street,postalCode,cityName,additionalInfo);
	Poco::JSON::Object::Ptr data = stAdrs.toJson();
	Address stAdrs2 = Address::fromJson(data);
	cout << stAdrs2.getStreet() << " " << stAdrs2.getCityName() << " " << stAdrs2.getPostalCode() << " " << stAdrs2.getAdditionalInfo() << " " <<endl;
	*/

	// EX 2.2 part 2
	WeeklyCourse* wcourse = new WeeklyCourse("EAA",1122,"Automation",5,
				Poco::DateTime::WEDNESDAY,Poco::Data::Time(12, 30, 0),Poco::Data::Time(14, 00, 0));

	Poco::JSON::Object::Ptr data = wcourse->toJson();
	delete wcourse;
	WeeklyCourse* wc2 = WeeklyCourse::fromJson(data);
	cout<<wc2->getTitle() <<endl;

	delete wc2;


	return 0;
}
