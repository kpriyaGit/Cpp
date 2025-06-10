/*
 * Student.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */
#include <fstream>
#include <iostream>
#include "Poco/JSON/Array.h"
#include "Student.h"
using namespace std;

/**
 * Initialize the static member nextMatrikelNumber for the first student to be entered in the DB
 */
unsigned int Student::nextMatrikelNumber = 100000;

Student::Student()
{
	this->matrikelNumber=0;
}

Student::Student(std::string firstName,std::string lastName,Poco::Data::Date dateOfBirth, Address address):
						firstName{firstName}, lastName{lastName}, dateOfBirth{dateOfBirth}
{
	this->matrikelNumber=nextMatrikelNumber++;
	this->address = address;
}

Student::~Student()
{
	// Auto-generated destructor stub
}

unsigned int Student::getMatrikelNumber() const
{
	return matrikelNumber;
}

const std::string& Student::getFirstName() const
{
	return firstName;
}

const std::string& Student::getLastName() const
{
	return lastName;
}


const Address& Student::getAddress() const
{
	return address;
}

const Poco::Data::Date& Student::getDateOfBirth() const
{
	return dateOfBirth;
}

const std::vector<Enrollment>& Student::getEnrollments() const
{
	return enrollments;
}

void Student::setAddress(const Address &address)
{
	this->address = address;
}

bool Student::addEnrollments(Enrollment &enrollment)
{
	if(this->enrollments.empty())
		this->enrollments.push_back(enrollment); //if its empty add the first enrollment
	else{
		for(auto it = begin(this->enrollments); it != end(this->enrollments); ++it)
		{
			cout<<"For loop";
			if (it->getCourse()->getCourseKey() == enrollment.getCourse()->getCourseKey())
			{
				return true; //element already present
			}
			else{
				this->enrollments.push_back(enrollment); //new enrollment
				return false;
			}
		}
	}
	return false;
}


void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

void Student::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void Student::updateEnrollments(const std::vector<Enrollment> &enrollments)
{
	this->enrollments.clear(); // replace the entire student enrollments by the new one
	this->enrollments = enrollments;
}

void Student::write(std::ostream &out)
{
	if(enrollments.size()!=0)
	{
		out<<matrikelNumber<<";";
		for (Enrollment iter : enrollments)
		{
			const Course *crs = iter.getCourse();
			out<<crs->getCourseKey()<<";";
			out<<iter.getSemester()<<";"<<iter.getGrade()<<endl;
		}
	}
}

Poco::JSON::Object::Ptr Student::toJson() const
{
	Poco::JSON::Object::Ptr padrs = this->address.toJson();
	Poco::JSON::Object::Ptr pstudent = new Poco::JSON::Object;

	pstudent->set("firstName", this->firstName);
	pstudent->set("lastName", this->lastName);
	pstudent->set("matrikelNumber", this->matrikelNumber);
	pstudent->set("address", padrs);

	Poco::JSON::Array array_enrol;
	for (auto &e : this->enrollments){
		Poco::JSON::Object::Ptr penrol = e.toJson();
		array_enrol.add(penrol);
	}

	pstudent->set("enrollments ", array_enrol);


	return pstudent;
}
