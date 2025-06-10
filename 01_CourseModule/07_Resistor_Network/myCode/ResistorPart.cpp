/*
 * ResistorPart.cpp
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */

#include "ResistorPart.h"

using namespace std;

/*
ResistorPart::ResistorPart(){

}
*/

ResistorPart::ResistorPart(string name, float value, float tolerance): Resistor{name}, value{value}, tolerance{tolerance/100}
{
}

ResistorPart::~ResistorPart()
{
	// Auto-generated destructor stub
}

float ResistorPart::nominalValue() const
{
	return value;
}

float ResistorPart::minimumValue() const
{
	return (value - tolerance);
}

float ResistorPart::maximumValue() const
{
	return (value + tolerance);
}



ResistorPtr ResistorPart::from(string line)
{
	extern string splitAt(string& remainder, char separator);

	string name = splitAt(line,';');
	float value = stof(splitAt(line,';'));
	float tolerance = stof(line);
	ResistorPtr R (new ResistorPart(name,value,tolerance));
	return R;

}
