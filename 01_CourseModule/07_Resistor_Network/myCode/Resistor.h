/*
 * Resistor.h
 *
 *  Created on: 05-Feb-2023
 *      Author: kpriya
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_

#include <string>
#include <memory>
//#include <iostream>

class Resistor
{
private:
	std::string name;
public:
	Resistor(std::string name);
	virtual ~Resistor();
	const std::string getName() const;

	virtual float nominalValue() const = 0;
	virtual float minimumValue() const = 0;
	virtual float maximumValue() const = 0;

	std::string toString() const;

	friend std::ostream& operator<< (std::ostream &lhs, std::shared_ptr<Resistor> &rhs);

	void write(std::ostream& out);
};

typedef std::shared_ptr<Resistor> ResistorPtr;

#endif /* RESISTOR_H_ */
