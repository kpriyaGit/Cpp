/*
 * ModuloNDigit.h
 *
 *  Created on: 27-Oct-2021
 *      Author: kpriya
 */
#include "ModuloNCounter.h"

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_
/**
 * Class that represents a Multiple digit counter
 */
class ModuloNDigit
{
private:
	/**
	 * Number of digits in the counter whose value is obtained from the main function()
	 */
	unsigned short digits;
	/**
	 * A Multiple digit counter is composed of one or more single digit counters
	 */
	ModuloNCounter* sdc;

public:
	/**
	 * Parameterized Constructor for initialization & dynamic memory allocation of member variables
	 * @param: digits - number of digits in the counter
	 * 		   base   - type of number system that needs to be initialized in the single digit counter class member
	 * 		   Parameters are passed by reference from the main() function during object creation
	 * 		   Value remains constant through out the program execution
	 */
	ModuloNDigit(const unsigned short &digits, const unsigned short &base);


	/**
	 * Destructor for releasing the memory
	 */
	~ModuloNDigit();

	/**
	 *User defined Copy constructor for copying the instance of ModuloNDigit
	 *@param : Orig - instance of ModuloNDigit class type that is to be copied
	 */
	ModuloNDigit(const ModuloNDigit& orig);

	/**
	 * Member function for incrementing the counter value
	 * Invokes the singleDigitCount() for every digit stating from the LSB to MSB
	 * depending on carry flag state from singleDigitCount()
	 */
	void incrementMDC();
	/**
	 * Member function for displaying the value of counter which in-turn invokes
	 * the display method of Single digit counter member variable.
	 */
	void printCurrentValue();

	/**
	 * Method for overloading post increment operator ++
	 */
	ModuloNDigit operator++();

	/**
	 * Method for overloading pre increment operator ++
	 */
	ModuloNDigit operator++(int );

	/**
	 * Method for displaying count value of type SingleDC by overloading << operator
	 *
	 */
	friend ostream& operator <<(ostream &lhs, ModuloNDigit rhs);

	/**
	 * Overloaded Copy assignment operator
	 * @param : Orig - instance of ModuloNDigit class type that is to be copied
	 */
	ModuloNDigit& operator=(const ModuloNDigit &orig);

	/**
	 * Move constructor to satisfy rule of five
	 */
	ModuloNDigit(ModuloNDigit &&orig);
	/**
	 * Move assignment to satisfy rule of five
	 */
	ModuloNDigit& operator =(ModuloNDigit &&orig);

};


#endif /* MULTIDC_H_ */
