/*
 * Temperature.cpp
 *
 *  Created on: 24-Jan-2023
 *      Author: armlp
 */

#include "Temperature.h"
using namespace std;

Temperature::Temperature(float temperature, uint16_t timestamp):Measurement{timestamp}, temperature{temperature}
{
	// Auto-generated constructor stub

}

float Temperature::getTemperature() const
{
	return temperature;
}

Temperature::~Temperature()
{
	// Auto-generated destructor stub
}

std::string Temperature::toString() const
{
	return ("Temperature: " + to_string(this->getTemperature()) + " °C");
}

shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp,string value)
{
	float temperature = stof(value.substr(1,(value.length()-4)));
	shared_ptr<Temperature> Tmeas(new Temperature(temperature, timestamp));
	return Tmeas;

}

Temperature* Temperature::toType(Measurement *ptr)
{
	Temperature* pTemp = dynamic_cast<Temperature*>(ptr);
	return pTemp;
}
