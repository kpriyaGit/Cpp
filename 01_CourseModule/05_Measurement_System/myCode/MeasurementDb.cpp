/*
 * MeasurementDb.cpp
 *
 *  Created on: 29-Jan-2023
 *      Author: armlp
 */
#include <iostream>

#include "MeasurementDb.h"
#include "Temperature.h"
#include "Humidity.h"
using namespace std;

MeasurementDb::MeasurementDb()
{
	// Auto-generated constructor stub

}

MeasurementDb::~MeasurementDb()
{
	// Auto-generated destructor stub
}

void MeasurementDb::addMeasurement(const string &location, shared_ptr<Measurement> measurement)
{
	bool existing_location = false;
	for(auto &c : this->data)
	{
		if(c.first == location){
			c.second.push_back(measurement);  //add new meas to the vector
			existing_location = true;
		}
	}
	if(existing_location == false)
	{
		vector<shared_ptr<Measurement>> v1 {measurement};  //create a new vector of measurements
		this->data.emplace(location, v1);
	}
}

/* Print For EX1 f)
 * void MeasurementDb::print()
{
	cout<<"Content of database:"<<endl;
	for(auto &c : this->data)
	{
		for(auto const &iterM : c.second)
		{
			cout<< c.first << " " << *iterM;
		}
	}
}*/


/* Print for Ex2 a)
 */
void MeasurementDb::print()
{
	cout<<"Content of database:"<<endl;
	for(auto &c : this->data)
	{
		cout<< "["<<c.first << "]" <<endl;
		for(auto const &iterM : c.second)
		{
			cout<< *iterM ;
		}

	}
}

/*const std::map<std::string, std::vector<std::shared_ptr<Measurement> > >& MeasurementDb::getData() const
{
	return data;
}*/

void MeasurementDb::save(std::ostream& to)
{
	for(auto &c : this->data)
	{
		to<< "["<<c.first << "]" <<endl;

		vector<shared_ptr<Measurement>>::iterator it;
		for (it = c.second.begin(); it!=c.second.end(); it++)
		{
			(*it).get()->save(to);
		}
	}
}

void MeasurementDb::load(std::istream &from)
{
	this->data.clear();
	string location, line, type, remainder; uint16_t timestamp;
	while(getline(from, line))
	{
		if(line[0]=='[')
		{location = line.substr(1,line.length()-2); cout<<"location "<<location<<endl;}
		else
		{
			Measurement::parseLine(line, timestamp, type, remainder);
			if(type=="Humidity"){
				shared_ptr<Measurement>Hmeas = Humidity::fromString(timestamp, remainder);
				this->addMeasurement(location, Hmeas);
			}
			else if (type=="Temperature"){
				shared_ptr<Measurement>Tmeas = Temperature::fromString(timestamp, remainder);
				this->addMeasurement(location, Tmeas);
			}
			else{
				//Do nothing
			}
		}
	}

}

bool MeasurementDb::maximumTemperature(string &location, shared_ptr<Measurement> &measurement)
{
	bool max_temp_found = false;float maxTemp = 0;
	for(auto &c : this->data)
	{
		vector<shared_ptr<Measurement>>::iterator it;
		Temperature* pTemp;
		for (it = c.second.begin(); it!=c.second.end(); it++)
		{
			pTemp = Temperature::toType((*it).get());
			if (pTemp != nullptr)
			{
				float temperature = pTemp->getTemperature();
				if(maxTemp< temperature)
				{
					//Measurement* ptempMeas = dynamic_cast<Measurement*>(pTemp);  //base class pointer points to derived class
					//shared_ptr<Measurement> tempMeas(ptempMeas);  // create shared pointer to base class
					//measurement = tempMeas;
					measurement = it->get();  //it is a shared pointer - measurement is also shared_ptr
					location = c.first;

					maxTemp = temperature;
					max_temp_found = true;
				}
			}
		}
	}

	if (max_temp_found==true)
		 return true;
	else
		return false;
}
