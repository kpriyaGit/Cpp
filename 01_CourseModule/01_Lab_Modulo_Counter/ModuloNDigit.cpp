/*
 * ModuloNDigit.cpp
 *
 *  Created on: 27-Oct-2021
 *      Author: kpriya
 */
#include <iostream>
#include <math.h>
using namespace std;
#include "ModuloNDigit.h"


ModuloNDigit::ModuloNDigit(const unsigned short &digits, const unsigned short &base)
{
	if (0 == digits)
	{
		this->digits = 1;
	}
	this->digits = digits;

	//Memory allocation
	this->sdc = new ModuloNCounter [digits];

	//Init the single digit counters
	for (unsigned short i = 0; i < this->digits; i++)
	{
		this->sdc[i].setbase(base);
	}
}

ModuloNDigit::ModuloNDigit(const ModuloNDigit &orig)
{
	digits=orig.digits;
	sdc= new ModuloNCounter [digits];

	for(unsigned short i=0;i<this->digits;i++)
	{
		this->sdc[i]=orig.sdc[i];
	}

}


ModuloNDigit::~ModuloNDigit()
{
	this->digits=0;
	delete [] sdc;
}

void ModuloNDigit::incrementMDC()
{
	for(unsigned short i=0;i<this->digits;i++)
	{
		unsigned short carry = this->sdc[i].singleDigitCount();
		if (0 == carry)
		{
			break;  //no need to tick further
		}
	}
}


ModuloNDigit ModuloNDigit::operator ++(int dummy)
{
	//copy constructor called
	ModuloNDigit result (*this);
		//Copy Assignment called
		//ModuloNDigit result(3,2);
		//result = *this;
	this->incrementMDC();
	//++(*this);
	return result;
}

ModuloNDigit ModuloNDigit::operator ++()
{
	this->incrementMDC();
	return *this;
}


ostream& operator <<(ostream &lhs, ModuloNDigit rhs)
{
	rhs.printCurrentValue();
	return lhs;
}


void ModuloNDigit::printCurrentValue()
{
	for (short i = this->digits - 1; i >= 0; i--)
	{
		cout<<hex<<uppercase<<this->sdc[i].getSingleDigit();
	}
}



ModuloNDigit& ModuloNDigit::operator =(const ModuloNDigit &orig)
{
	delete [] sdc;
	digits=orig.digits;
	this->sdc = new ModuloNCounter [digits];
	for (unsigned short i = 0; i < this->digits; i++)
	{
		sdc[i]= orig.sdc[i];
	}

	return *this;
}


ModuloNDigit::ModuloNDigit(ModuloNDigit &&orig) {
	digits = orig.digits;
	orig.digits = 0;
	sdc = orig.sdc;
	orig.sdc = nullptr;
}


ModuloNDigit& ModuloNDigit::operator =(ModuloNDigit &&orig) {
	//swap(digits, orig.digits);
	//swap(sdc, orig.sdc);
	return *this;
}
