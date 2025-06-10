/*
 * Course.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */
#include <map>
#include <iostream>
#include <fstream>
#include "Course.h"
using namespace std;

map<unsigned char, string> Course::majorById ;

Course::Course(unsigned int courseKey,std::string title, std::string major, float creditPoints)
{
	this->courseKey = courseKey;
	this->title = title;
	this->creditPoints = creditPoints;

	this->setMajor(major);

}


Course::Course(Poco::JSON::Object::Ptr data)
{

	this->title = data->get("title").toString();
	this->setMajor(data->get("major").toString());
	this->creditPoints = data->get("creditPoints").convert<float>();
	this->courseKey = data->get("courseKey").convert<int>();

}

void Course::setMajor(string major)
{
	char firstAlpha = toupper(major[0]);

	if(this->majorById.empty() == true){
		this->majorById[firstAlpha] = major;
		this->major = firstAlpha;
	}
	else{
		for(auto& element: this->majorById ){
			if(element.second == major){
				this->major = element.first;
			break;
			}
			else{
				this->majorById[firstAlpha] = major;
				this->major = firstAlpha;
			}
		}
	}
}

Course::~Course(){

}
string Course::getMajor() const
{
	return majorById[this->major];
}

unsigned int Course::getCourseKey() const
{
	return courseKey;
}

float Course::getCreditPoints() const
{
	return creditPoints;
}

const std::string& Course::getTitle() const
{
	return title;
}

void Course::write(std::ostream &out) const
{
	out<<this->courseKey<<";"<<this->title<<";"<<this->getMajor()<<";"<<this->creditPoints<<";";

}

string Course::toString(Poco::Data::Time time)
{
	/*string temp = to_string(time.hour()) + ":" + to_string(time.minute());
	return temp;*/
	Poco::DateTime tempTime(1,1,1,time.hour(),time.minute(),time.second());
	string format = "%H:%M";

	string outTime = Poco::DateTimeFormatter::format(tempTime, format);
	return outTime;
}

string Course::toString(Poco::Data::Date date)
{
	/*string temp = to_string(date.day()) + "." + to_string(date.month()) + "." + to_string(date.year());
	return temp;*/
	Poco::DateTime tempDate(date.year(),date.month(),date.day());
	string format = "%Y:%m:%d";

	string outDate = Poco::DateTimeFormatter::format(tempDate, format);
	return outDate;

}

Poco::Data::Time Course::timeFromString(std::string time)
{
	unsigned int colonPos=0, hr=0,min=0;

	colonPos = time.find(':');
	hr = stoi(time.substr(0, colonPos));
	min = stoi(time.substr(colonPos+1, time.length()-1));

	Poco::Data::Time output(hr,min, 0);
	return (output);
}

Poco::Data::Date Course::dateFromString(std::string date)
{
	unsigned int d=0,m=0,yr=0;
	int found1 = date.find('.');
	d = stoi(date.substr(0, found1));
	int found2 = date.find('.',found1);
	m = stoi(date.substr(found1+1, found2));
	yr = stoi(date.substr(found2+1,date.length()-1));

	Poco::Data::Date output(yr, m, d);

	return output;
}

Poco::JSON::Object::Ptr Course::toJson() const
{
	Poco::JSON::Object::Ptr padrs = new Poco::JSON::Object(Poco::JSON_PRESERVE_KEY_ORDER);

		padrs->set("courseKey", to_string(this->getCourseKey()));
		padrs->set("creditPoints",to_string(this->getCreditPoints()));
		padrs->set("major", this->getMajor());
		padrs->set("title", this->getTitle());

	return padrs;

}

