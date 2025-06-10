/*
 * Address.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: kpriya
 */

#include "Address.h"
using namespace std;

Address::Address()
{
	this->postalCode = 0;
}


Address::Address(string street, unsigned short postalCode,string cityName, string additionalInfo) :
		street{street}, postalCode{postalCode}, cityName{cityName}, additionalInfo{additionalInfo}
{

}

Address::~Address()
{
	this->postalCode = 0;
}

const std::string& Address::getStreet() const
{
	return street;
}


unsigned short Address::getPostalCode() const
{
	return postalCode;
}

const std::string& Address::getCityName() const
{
	return cityName;
}

const std::string& Address::getAdditionalInfo() const
{
	return additionalInfo;
}

