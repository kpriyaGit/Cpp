/*
 * Enrollment.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_
#include <string>
#include "Course.h"

/**
 * A class that represents an enrollment of a student.
 */
class Enrollment
{
private:
	/**
	 * Private attribute for pointing to the course enrolled
	 */
	const Course* course;
	/**
	 * Private attribute for storing the enrolled semester of the student
	 */
	std::string semester;
	/**
	 * Private member for storing the grade obtained by student in the course pointed in enrollment
	 */
	float grade;

public:
	/**
	 * Parametrized cosntructor for initializing the attributes of an enrollment object
	 * @param *course - pointer to a course class object
	 * @param semester - string type attribute
	 * @param grade - float type attribute that has default value of -1
	 */
	Enrollment(const Course* course, std::string semester, float grade=-1);
	//Enrollment is created in Student class and hence will be deleted there
	//course has aggregation relationship with enrollment - no effect
	//~Enrollment();

	/**
	 * Member function for updating the grade obtained by the student
	 */
	void setGrade(float grade);
	/**
	 * Member function for providing the course pointed by the enrollment
	 */
	const Course* getCourse() const;
	/**
	 * Member function for providing the grade obtained by the student
	 */
	float getGrade() const;
	/**
	 * Member function for providing the enrolled semester of the student
	 */
	const std::string& getSemester() const;
};

#endif /* ENROLLMENT_H_ */
