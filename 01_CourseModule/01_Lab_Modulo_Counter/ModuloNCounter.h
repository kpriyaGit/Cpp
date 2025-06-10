/*
 * ModuloNCounter.h
 *
 *  Created on: 27-Oct-2021
 *      Author: kpriya
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

typedef enum{
	    BIN = 2,
		OCT = 8,
	    DEC = 10,
	    HEX = 16
	} baseValues;

/**
 * Class that represents a single digit counter
 */

class ModuloNCounter
{
private:
	/**
	 * base represents the type of number system (Binary or Octal or Decimal or Hex)
	 */
	unsigned short base;

	/**
	 * Current value of the single digit counter
	 */
	unsigned short count;

public:
	/**
	 * Parameterized constructor for initializing private members of the class with user defined values
	 * @param : base - type of number system that needs to be initialized
	 * 		   		 - value is obtained from the main function()
	 * NOTE: THIS CONSTRUCTOR WAS INITIALLY CREATED EXCLUSIVELY FOR THE TEST OF ModuloNCounter CLASS
	 *       AND IS NOT INVOKED CURRENTLY FROM ANYWHERE IN THIS PROGRAM
	 */
	       //ModuloNCounter(unsigned short base);

	/**
	 * Default constructor to initialize private members of the class
	 */
	ModuloNCounter();

	/**
	 * Destructor
	 */
	~ModuloNCounter();

	/**
	 * Member function for incrementing the single counter
	 * @return : Returns 1 if single digit counter has reached its maximum value
	 *           else returns 0
	 */
	bool singleDigitCount();

	/**
	 * Member function for displaying value of count
	 */
	unsigned short getSingleDigit();

	/**
	 * Setter function for assigning user defined value to private member base
	 * during dynamic memory allocation of single digit counters from constructor of MultiDC class
	 * @param : base - not to be modified within the function
	 */
	void setbase(const unsigned short &base);

	/**
	 * Getter function for private member base
	 * @param : base - not to be modified within the function
	 */
	unsigned short getbase();
};

#endif /* MODULONCOUNTER_H_ */
