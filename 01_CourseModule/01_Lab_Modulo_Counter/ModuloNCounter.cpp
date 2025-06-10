/*
 * ModuloNCounter.cpp
 *
 *  Created on: 27-Oct-2021
 *      Author: kpriya
 */
#include <iostream>
using namespace std;

#include "ModuloNCounter.h"
/*

ModuloNCounter::ModuloNCounter(unsigned short base)
{

	 * Performs a validity check of parameter and copies the value to private data member base
	 * Else a default value is set and an error message is displayed


	if (base==16 or base==10 or base==8 or base==2)
	{
		this->base = base;
	}
	else
	{
		//Safe value
		cout<<"User Input error, taking Decimal(10) as base\n";
		this->base = 10;
	}

	this->count = 0;

}
*/

ModuloNCounter::ModuloNCounter()
{
	this->count = 0;
	this->base = 0;
}

ModuloNCounter::~ModuloNCounter()
{
	// Auto-generated destructor stub
}

bool ModuloNCounter::singleDigitCount()
{
	if (this->count < this->base-1)
		{
			this->count++;
			return 0;
		}
	else
		{
			this->count = 0;
			return 1;
		}

}

unsigned short ModuloNCounter::getSingleDigit()
{
	//cout<<hex<<uppercase<<this->count;
	return this->count;
}


void ModuloNCounter::setbase(const unsigned short &base)
{
	if (base==HEX or base==DEC or base==OCT or base==BIN)
	{
		this->base = base;
	}
	else
	{
		//Safe value
		cout<<"User Input error, taking Decimal(10) as base\n";
		this->base = DEC;
	}
}

unsigned short ModuloNCounter::getbase()
{
	return this->base;
}
