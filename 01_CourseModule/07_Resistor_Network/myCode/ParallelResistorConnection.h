/*
 * ParallelResistorConnection.h
 *
 *  Created on: 08-Feb-2023
 *      Author: kpriya
 */

#ifndef PARALLELRESISTORCONNECTION_H_
#define PARALLELRESISTORCONNECTION_H_

#include "ResistorConnection.h"

class ParallelResistorConnection: public ResistorConnection
{
public:
	ParallelResistorConnection(std::string name);
	virtual ~ParallelResistorConnection();
	char separator () const ;
	float nominalValue() const;
	float minimumValue() const;
	float maximumValue() const;
};

#endif /* PARALLELRESISTORCONNECTION_H_ */
