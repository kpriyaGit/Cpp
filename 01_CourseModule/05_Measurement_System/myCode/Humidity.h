/*
 * Humidity.h
 *
 *  Created on: 29-Jan-2023
 *      Author: armlp
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include <memory>
#include "Measurement.h"

class Humidity: public Measurement
{
private :
	float humidity;

public:
	Humidity(float humidity, uint16_t timestamp);
	virtual ~Humidity();
	float getHumidity() const;
	std::string toString() const;
	static std::shared_ptr<Humidity> fromString(uint16_t timestamp, std::string value);
	static Humidity* toType(Measurement* ptr);

};

#endif /* HUMIDITY_H_ */
