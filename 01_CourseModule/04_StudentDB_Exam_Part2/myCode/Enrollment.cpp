/*
 * Enrollment.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#include "Enrollment.h"
using namespace std;

Enrollment::Enrollment(const Course* course,string semester, float grade):course{course},
									semester{semester},grade{grade}
{

}

void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

const Course* Enrollment::getCourse() const
{
	return course;
}

float Enrollment::getGrade() const
{
	return grade;
}

const std::string& Enrollment::getSemester() const
{
	return semester;
}

Poco::JSON::Object::Ptr Enrollment::toJson() const
{
	Poco::JSON::Object::Ptr padrs = new Poco::JSON::Object(Poco::JSON_PRESERVE_KEY_ORDER);

	padrs->set("courseKey", course->getCourseKey());
	padrs->set("grade", this->grade);

	return padrs;
}
