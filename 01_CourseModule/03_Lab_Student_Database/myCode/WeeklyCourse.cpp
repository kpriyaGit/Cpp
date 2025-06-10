/*
 * WeeklyCourse.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */
#include<iostream>
#include <fstream>
#include "WeeklyCourse.h"

using namespace std;

WeeklyCourse::WeeklyCourse(string title, unsigned int key, string major,float creditPoints,
		Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime, Poco::Data::Time endTime) :
		Course {key,title,major,creditPoints} {

			this->dayOfWeek=dayOfWeek;
			this->startTime=startTime;
			this->endTime = endTime;
}

WeeklyCourse::~WeeklyCourse()
{
	// Auto-generated destructor stub
}


void WeeklyCourse::print() const {
	cout<<"Weekly Course"<<endl;
	//Course::print();
	cout<<"ID : "<<courseKey<<endl<<"Title : "<<title<<endl;
	cout<<"CreditPoints : "<<creditPoints<<endl<<"Major : "<<getMajor()<<endl;
	cout<<"Days Of Week "<<dayOfWeek<<endl;
	cout<<"Start Time : "<<startTime.hour()<<":"<<startTime.minute()<<" Hours"<<endl;
	cout<<"End Time : "<<endTime.hour()<<":"<<endTime.minute()<<" Hours"<<endl<<endl;

}


Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return dayOfWeek;
}

const Poco::Data::Time& WeeklyCourse::getEndTime() const
{
	return endTime;
}

const Poco::Data::Time& WeeklyCourse::getStartTime() const
{
	return startTime;
}

void WeeklyCourse::write(std::ostream &out) const
{
	out<<"W;";
	Course::write(out);
	out<<this->dayOfWeek<<";";
	out<<startTime.hour()<<":"<<startTime.minute()<<";";
	out<<endTime.hour()<<":"<<endTime.minute()<<endl;
}
