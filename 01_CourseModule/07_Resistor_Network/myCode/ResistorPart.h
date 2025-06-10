/*
 * ResistorPart.h
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */

#ifndef RESISTORPART_H_
#define RESISTORPART_H_

#include "Resistor.h"

class ResistorPart : public Resistor
{
private:
	float value;
	float tolerance;
public:
	//ResistorPart();
	ResistorPart(std::string name, float value, float tolerance);
	virtual ~ResistorPart();
	float nominalValue() const;
	float minimumValue() const;
	float maximumValue() const;
	static ResistorPtr from(std::string line);
};

#endif /* RESISTORPART_H_ */
