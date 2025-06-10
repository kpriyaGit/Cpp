/*
 * WeeklyCourse.h
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include "Course.h"

/**
 * A class that represents a course that happens one day every week
 * It is publicly derived class from the base class Course
 */
class WeeklyCourse: public Course
{
private:
	/**
	 * Private member that stores which day of the week the course takes place
	 * 1(MONDAY) ... 5(FRIDAY)
	 */
	Poco::DateTime::DaysOfWeek dayOfWeek;
	/**
	 * Private member that stores the start time of the course
	 */
	Poco::Data::Time startTime;
	/**
	 * Private member that stores the end time of the course
	 */
	Poco::Data::Time endTime;

protected :
	WeeklyCourse(Poco::JSON::Object::Ptr data);

public:
	/**
	 * Parameterized constructor that initializes all the attributes of the weekly course object
	 * @params - course title, course key , major, and credit points : from the base class course
	 * 			dayOfWeek,startTime,endTime : own class attributes
	 */
	WeeklyCourse(std::string title,unsigned int key, std::string major,float creditPoints,
			Poco::DateTime::DaysOfWeek dayOfWeek,Poco::Data::Time startTime,Poco::Data::Time endTime);
	/**
	 * Destructor
	 */
	~WeeklyCourse();
	/**
	 * Member function to print the contents of the course on the console
	 */
	void print()const ;
	/**
	 * Method that provides day number in which course is held
	 */
	Poco::DateTime::DaysOfWeek getDayOfWeek() const;
	/**
	 * Method that provides End time of the course
	 */
	const Poco::Data::Time& getEndTime() const;
	/**
	 * Method that provides start time of the course
	 */
	const Poco::Data::Time& getStartTime() const;
	/**
	 * Member function to write details of the weekly course onto an ostream object
	 */
	void write(std::ostream& out) const;

	virtual Poco::JSON::Object::Ptr toJson() const;

	static WeeklyCourse* fromJson(Poco::JSON::Object::Ptr data);
};

#endif /* WEEKLYCOURSE_H_ */
