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

Poco::JSON::Object::Ptr Address::toJson() const
{
	Poco::JSON::Object::Ptr padrs = new Poco::JSON::Object(Poco::JSON_PRESERVE_KEY_ORDER);

	padrs->set("additionalInfo", this->additionalInfo);
	padrs->set("CityName",this->cityName);
	padrs->set("postalCode",this->postalCode);
	padrs->set("street",this->street);

	return padrs;
}

Address Address::fromJson(Poco::JSON::Object::Ptr data)
{
	cout<<" Function entered "<<endl;
	string street = " ",cityName = " ", additionalInfo = " ";
	unsigned int postalCode = 0;

	street = data->get("street").toString();
	if(data->has("cityName"))
		cityName = data->get("cityName").toString();
	else
		cityName = data->get("CityName").toString();
	additionalInfo = data->get("additionalInfo").toString();
	postalCode = data->get("postalCode").convert<int>();

	Address stAdrs(street,postalCode,cityName,additionalInfo);
	return stAdrs;

}
