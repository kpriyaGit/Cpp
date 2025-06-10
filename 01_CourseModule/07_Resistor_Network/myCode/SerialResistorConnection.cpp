/*
 * SerialResistorConnection.cpp
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */

#include "SerialResistorConnection.h"
#include <iostream>

SerialResistorConnection::SerialResistorConnection(std::string name):ResistorConnection{name}
{

}

SerialResistorConnection::~SerialResistorConnection()
{
	// Auto-generated destructor stub
}

char SerialResistorConnection::separator() const
{
	return ('-');
}

float SerialResistorConnection::nominalValue() const
{
	float nomVal=0;
	for (auto &c : this->resistors){
		nomVal = nomVal + c->nominalValue();
	}
	return nomVal;
}

float SerialResistorConnection::minimumValue() const
{
	float minVal=0;
		for (auto &c : this->resistors){
			minVal = minVal + c->minimumValue();
		}
		return minVal;
}

float SerialResistorConnection::maximumValue() const
{
	float maxVal=0;
		for (auto &c : this->resistors){;
			maxVal = maxVal + c->maximumValue();
		}
		return maxVal;
}
