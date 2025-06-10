/*
 * Humidity.cpp
 *
 *  Created on: 29-Jan-2023
 *      Author: armlp
 */

#include "Humidity.h"

using namespace std;


Humidity::Humidity(float humidity, uint16_t timestamp):Measurement{timestamp},humidity{humidity}
{
}

float Humidity::getHumidity() const
{
	return humidity;
}

Humidity::~Humidity()
{
	// Auto-generated destructor stub
}

string Humidity::toString() const
{
	return ("Humidity: " + to_string(this->getHumidity()) + " %");
}

shared_ptr<Humidity> Humidity::fromString(uint16_t timestamp, string value)
{
	float humidity = stof(value.substr(1,(value.length()-3)));
	shared_ptr<Humidity> Hmeas(new Humidity(humidity, timestamp));
	return Hmeas;
}

Humidity* Humidity::toType(Measurement *ptr)
{
	Humidity* pHum = dynamic_cast<Humidity*>(ptr);
	return pHum;
}
