/*
 * Measurement.cpp
 *
 *  Created on: 22-Jan-2023
 *      Author: armlp
 */
#include <iostream>
#include "Measurement.h"
//#include <stdexcept>

using namespace std;

Measurement::Measurement(uint16_t timestamp): timestamp{timestamp}
{
	// Auto-generated constructor stub

}

Measurement::~Measurement()
{
	// Auto-generated destructor stub
}

uint16_t Measurement::toTimestamp( int hour , int minute) {

	if (hour > 23 || minute > 59)
		throw invalid_argument("Invalid Hour or Minute - check the values");
	else
		return ((hour * 60) + minute);
}

string Measurement::toTimeOfDay(uint16_t timestamp){

	string hr, min; int hour, minute;

	hour = timestamp/60;
	minute = timestamp - (hour * 60);

	if(hour < 10)
		hr = "0"+ to_string(hour);
	else
		hr = to_string(hour);

	if(minute < 10)
		min = "0"+ to_string(minute);
	else
		min = to_string(minute);

	return (hr + ":" + min);
}

void Measurement::parseLine(const string &line, uint16_t &timestamp,string &type, string &remainder)
{
	/*ifstream infile;
	string filename, location,temp;
	cout<<endl<<"Enter the file name from which data is to be read: ";
	cin>>filename;
	infile.open(filename);
	getline(infile,location);
	getline(infile, temp, ';');
	timestamp = stoi(temp);
	cout<<"Timestamp "<<timestamp<<endl;
	getline(infile, temp, ':');
	type = temp;
	cout<<"type "<<type<<endl;
	getline(infile,temp);
	remainder = temp;
	cout<<"remainder "<<remainder<<endl;
	infile.close();
*/
	int pos1,pos2;
	pos1=line.find(';');
	pos2 = line.find(':');
	timestamp = stoi(line.substr(0, pos1));
	type = line.substr(pos1+1,pos2-(pos1+1));
	remainder = line.substr(pos2+1,line.length()-1);
}

/* operator<< overloading for Ex1 d)
ostream& operator<<(ostream& lhs, Measurement& rhs)
{
	cout<<Measurement::toTimeOfDay(rhs.getTimestamp())<<";"<<rhs.toString()<<endl;
	return lhs;
}
 */

/* operator<< overloading for Ex2 a) */
ostream& operator<<(ostream& lhs, Measurement& rhs)
{
	cout<<rhs.getTimestamp()<<";"<<rhs.toString()<<endl;
	return lhs;
}


uint16_t Measurement::getTimestamp() const
{
	return timestamp;
}

void Measurement::save(std::ostream &to)
{
	to<<this->getTimestamp() <<";"<<this->toString()<<endl;
}
