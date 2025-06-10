/*
 * ResistorConnection.cpp
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */
#include <iostream>
#include "ResistorConnection.h"
using namespace std;

ResistorConnection::ResistorConnection(std::string name):Resistor{name}
{

}

ResistorConnection::~ResistorConnection()
{
	// Auto-generated destructor stub
}

char ResistorConnection::separator() const
{
	return (',');
}

std::string ResistorConnection::getName() const
{

	//cout<<endl<<" GetName in Resistor connection "<<endl;
	string output = this->Resistor::getName() + "[";
	for( auto &c: this->resistors){
		output = output + c->getName() + this->separator();
	}

	output[output.length()-1] = ']';  // replace the last separator by ]
	//cout<< output;
	return output;
}

ResistorConnection& ResistorConnection::operator +=(const std::shared_ptr<Resistor> &resistor)
{
	//cout<<endl<<" Adding ..... "<<resistor->getName()<<endl;
	this->resistors.push_back(resistor);
	/*cout<<" available list of resistors  "<<endl;
	for (auto &c :this->resistors)
	{
		cout<<c->getName()<<endl;
	}*/
	return (*this);
}

void ResistorConnection::write(std::ostream &out)
{
	for (auto &c :this->resistors)
	{
		out<<c->getName()<<";";
		c->write(out);
	}

	out<<this->getName()<<";"<<this->nominalValue()<<";";
	out<<(this->maximumValue()-this->nominalValue())<<endl;
}
