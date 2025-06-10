/*
 * ParallelResistorConnection.cpp
 *
 *  Created on: 08-Feb-2023
 *      Author: kpriya
 */

#include "ParallelResistorConnection.h"


ParallelResistorConnection::ParallelResistorConnection(std::string name): ResistorConnection{name}
{

}

ParallelResistorConnection::~ParallelResistorConnection()
{
	// Auto-generated destructor stub
}

char ParallelResistorConnection::separator() const
{
	return ('|');
}

float ParallelResistorConnection::nominalValue() const
{
	float nomVal=0;
		for (auto &c : this->resistors){
			nomVal = nomVal + (1/c->nominalValue());
		}
		return (1/nomVal);
}

float ParallelResistorConnection::minimumValue() const
{
	float minVal=0;
		for (auto &c : this->resistors){
			minVal = minVal + (1/c->minimumValue());
		}
		return (1/minVal);
}

float ParallelResistorConnection::maximumValue() const
{
	float maxVal=0;
		for (auto &c : this->resistors){
			maxVal = maxVal + (1/c->maximumValue());
		}
		return (1/maxVal);
}
