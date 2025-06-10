/*
 * Measurement.h
 *
 *  Created on: 22-Jan-2023
 *      Author: armlp
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <cstdlib>
#include <string>


class Measurement
{
private:
	std::uint16_t timestamp;

public:
	Measurement(std::uint16_t timestamp);
	virtual ~Measurement();
	static uint16_t toTimestamp( int hour , int minute);
	static std::string toTimeOfDay(std::uint16_t timestamp);
	std::uint16_t getTimestamp() const;
	virtual std::string toString() const = 0 ;
	void save(std::ostream& to);
	static void parseLine(const std::string &line, uint16_t &timestamp, std::string &type, std::string &remainder);
	friend std::ostream& operator<<(std::ostream& lhs, Measurement& rhs);
};




#endif /* MEASUREMENT_H_ */
