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
