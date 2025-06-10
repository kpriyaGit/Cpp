/*
 * BlockCourse.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */
#include<iostream>
#include <fstream>
#include "BlockCourse.h"
using namespace std;

BlockCourse::BlockCourse(std::string title,unsigned int key, std::string major,float creditPoints,
		Poco::Data::Date startDate, Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime) : Course {key,title,major,creditPoints}
{
			this->startDate = startDate;
			this->endDate = endDate;
			this->startTime = startTime;
			this->endTime = endTime;
}

BlockCourse::~BlockCourse()
{

}

const Poco::Data::Date& BlockCourse::getEndDate() const
{
	return endDate;
}

const Poco::Data::Time& BlockCourse::getEndTime() const
{
	return endTime;
}

const Poco::Data::Date& BlockCourse::getStartDate() const
{
	return startDate;
}

const Poco::Data::Time& BlockCourse::getStartTime() const
{
	return startTime;
}


void BlockCourse::print() const{
	cout<<"Block course"<<endl;
	cout<<"ID : "<<courseKey<<endl<<"Title : "<<title<<endl;
	cout<<"CreditPoints : "<<creditPoints<<endl<<"Major : "<<getMajor()<<endl;
	cout<<"Start Date : "<<startDate.day()<<"/"<<startDate.month()<<"/"<<startDate.year()<<endl;
	cout<<"End Date : "<<endDate.day()<<"/"<<endDate.month()<<"/"<<endDate.year()<<endl;
	cout<<"Start Time : "<<startTime.hour()<<":"<<startTime.minute()<<" Hours"<<endl;
	cout<<"End Time : "<<endTime.hour()<<":"<<endTime.minute()<<" Hours"<<endl<<endl;
}

void BlockCourse::write(std::ostream &out) const
{
	out<<"B;";
	Course::write(out);
	out<<startDate.day()<<"."<<startDate.month()<<"."<<startDate.year()<<";";
	out<<endDate.day()<<"."<<endDate.month()<<"."<<endDate.year()<<";";
	out<<startTime.hour()<<":"<<startTime.minute()<<";";
	out<<endTime.hour()<<":"<<endTime.minute()<<endl;
}

Poco::JSON::Object::Ptr BlockCourse::toJson() const
{
	Poco::JSON::Object::Ptr padrs = Course::toJson();


	padrs->set("startTime",toString(this->startTime));
	padrs->set("endTime",toString(this->endTime));
	padrs->set("startDate",toString(this->startDate));
	padrs->set("endDate",toString(this->endDate));

	return padrs;

}
