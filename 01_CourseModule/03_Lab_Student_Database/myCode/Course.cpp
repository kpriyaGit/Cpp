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

	unsigned char initAlpha = toupper(major[0]);

	if(majorById.empty()){

		majorById = {{initAlpha, major}};
		this->major=initAlpha;
	}
	else{
		for( pair<unsigned char, string> element : majorById ){

			if(majorById[element.first]==major){
				this->major= element.first;
				break;
			}
			else{
				majorById[initAlpha]= major;
				this->major=initAlpha;
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
