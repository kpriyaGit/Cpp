/*
 * ResistorConnection.h
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */

#ifndef RESISTORCONNECTION_H_
#define RESISTORCONNECTION_H_

#include <list>
#include <string>
#include "Resistor.h"

class ResistorConnection : public Resistor
{
protected :
	std::list<std::shared_ptr<Resistor>> resistors;
public:
	ResistorConnection(std::string name);
	~ResistorConnection();
	virtual char separator () const ;
	std::string getName () const;

	ResistorConnection& operator+=(const std::shared_ptr<Resistor> &resistor);

	void write(std::ostream& out);
};

#endif /* RESISTORCONNECTION_H_ */
