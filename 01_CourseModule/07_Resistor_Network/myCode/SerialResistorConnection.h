/*
 * SerialResistorConnection.h
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */

#ifndef SERIALRESISTORCONNECTION_H_
#define SERIALRESISTORCONNECTION_H_
#include <string>

#include "ResistorConnection.h"

class SerialResistorConnection: public ResistorConnection
{
public:
	SerialResistorConnection(std::string name);
	virtual ~SerialResistorConnection();
	char separator () const ;
	float nominalValue() const;
	float minimumValue() const;
	float maximumValue() const;
};

#endif /* SERIALRESISTORCONNECTION_H_ */
