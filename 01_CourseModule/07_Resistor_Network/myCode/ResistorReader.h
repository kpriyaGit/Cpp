/*
 * ResistorReader.h
 *
 *  Created on: 09-Feb-2023
 *      Author: kpriya
 */

#ifndef RESISTORREADER_H_
#define RESISTORREADER_H_

#include<map>
#include<string>
#include "Resistor.h"

class ResistorReader
{
public:
	ResistorReader();
	virtual ~ResistorReader();
	static void read(std::istream& in, std::map<std::string, ResistorPtr>& found);
};

#endif /* RESISTORREADER_H_ */
