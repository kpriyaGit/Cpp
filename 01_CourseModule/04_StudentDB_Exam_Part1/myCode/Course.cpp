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

Course::Course(unsigned int courseKey,std::string title, std::string major,std::string sem, float creditPoints)
{
	this->courseKey = courseKey;
	this->title = title;
	this->creditPoints = creditPoints;

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

	string part1; int year;

	try{
		year = stoi(sem.substr(4, 4));
	}
	catch(const std::exception& e){
		//cerr<<"Invalid year in semester "<<endl;
		cout<< "Standard exception caught with message "<<e.what()<<endl;
	}
	part1 = sem.substr(0,4);

	//this->semester = year-2021;

	if(part1 == "WiSe")
	{
		this->semester = (2 * (year-2021));
	}
	else if(part1 == "SoSe")
	{
		this->semester = (2 * (year-2021)) - 1;
	}
	else
	{
		//throw invalid_argument("Invalid Format for Semester");
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

std::string Course::getSemester() const
{
	 string part1, output ; int year;
	 if(this->semester%2==0) //even means WiSe
	 {
		 part1="WiSe";
		 year = 2021+(this->semester/2);
	 }
	 else{
		 part1="SoSe";
		 year = 2021+((this->semester+1)/2);
	 }
	 output = part1+to_string(year);
	 return(output);
}
