/*
 * Resistor.cpp
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */
#include<iostream>

#include "Resistor.h"

using namespace std;

Resistor::Resistor(string name): name{name}
{
}

Resistor::~Resistor()
{
	// Auto-generated destructor stub
}


const string Resistor::getName() const
{
	//cout<<endl<<" GetName in Resistor.cpp "<<endl;
	return name;
}

string Resistor::toString() const
{
	//string output = this->getName() + " = " + to_string(this->nominalValue()) + " Ohm";
	string output = " = " + to_string(this->nominalValue()) + " Ohm" + '\n';
	return output;
}

ostream& operator<< (ostream &lhs, shared_ptr<Resistor> &rhs){

	lhs<<rhs->getName()<<rhs->toString();
	return lhs;
}

void Resistor::write(std::ostream &out)
{
	//out<<this->getName()<<";"<<to_string(this->nominalValue())<<";"<<to_string(this->maximumValue()-this->nominalValue())<<endl;
	out<<to_string(this->nominalValue())<<";"<<to_string(this->maximumValue()-this->nominalValue())<<endl;
}
