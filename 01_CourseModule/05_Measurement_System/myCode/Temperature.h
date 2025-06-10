/*
 * Temperature.h
 *
 *  Created on: 24-Jan-2023
 *      Author: armlp
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include <memory>
#include "Measurement.h"

class Temperature: public Measurement
{
private :
	float temperature;
public:
	Temperature(float temperature, uint16_t timestamp);
	~Temperature();
	float getTemperature() const;
	std::string toString() const;
	static std::shared_ptr<Temperature> fromString(uint16_t timestamp, std::string value);
	static Temperature* toType(Measurement * ptr);
};

#endif /* TEMPERATURE_H_ */
