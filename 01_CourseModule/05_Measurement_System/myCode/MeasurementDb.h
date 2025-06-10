/*
 * MeasurementDb.h
 *
 *  Created on: 29-Jan-2023
 *      Author: armlp
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_
#include "Measurement.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

class MeasurementDb
{
private:
	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;
public:
	MeasurementDb();
	~MeasurementDb();
	void addMeasurement(const std::string& location, std::shared_ptr<Measurement> measurement);
	void print();
	void save(std::ostream& to);
	void load(std::istream& from);
	//const std::map<std::string, std::vector<std::shared_ptr<Measurement> > >& getData() const;
	bool maximumTemperature(std::string& location, std::shared_ptr<Measurement>& measurement);
};

#endif /* MEASUREMENTDB_H_ */
