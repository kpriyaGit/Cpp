/*
 * BlockCourse.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include "Course.h"
#include <Poco/Data/Date.h>
#include <Poco/DateTime.h>
#include <Poco/Data/Time.h>
/**
 * A class that represents a course that happens everyday continuously from one date to another
 * It is publicly derived class from the base class Course
 */
class BlockCourse: public Course
{
private:
	/**
	 * Private member that stores the start date of the course
	 */
	Poco::Data::Date startDate;
	/**
	 * Private member that stores the end date of the course
	 */
	Poco::Data::Date endDate;
	/**
	 * Private member that stores the start time of the course
	 */
	Poco::Data::Time startTime;
	/**
	 * Private member that stores the end time of the course
	 */
	Poco::Data::Time endTime;

public:
	/**
	 * Parameterized constructor that initializes all the attributes of the block course object
	 * @params - course title, course key , major, and credit points : from the base class course
	 * 			startDate, endDate,startTime,endTime : own class attributes
	 */
	BlockCourse(std::string title,unsigned int key, std::string major,float creditPoints,
			Poco::Data::Date startDate,Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);
	/**
	 * Destructor
	 */
	~BlockCourse();
	/**
	 * Member function to print the contents of the course on the console
	 */
	void print()const;
	/**
	 * Method that provides End Date of the course to the caller
	 */
	const Poco::Data::Date& getEndDate() const;
	/**
	 * Method that provides start Date of the course to the caller
	 */
	const Poco::Data::Time& getEndTime() const;
	/**
	 * Method that provides start time of the course to the caller
	 */
	const Poco::Data::Date& getStartDate() const;
	/**
	 * Method that provides end time of the course to the caller
	 */
	const Poco::Data::Time& getStartTime() const;
	/**
	 * Member function to write details of the block course onto an ostream object
	 */
	void write(std::ostream& out) const;
};

#endif /* BLOCKCOURSE_H_ */
