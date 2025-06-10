#include <iostream>
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"


SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor> &&sensor)
{
	std::string newSensorName = sensor->getName();
	bool newSensorValid = false;

	if(this->sensors.empty()){
		newSensorValid = true;
	}
	else{
		for(auto &item:this->sensors)
		{
			if(newSensorName == item.get()->getName()) {

				//implementation 1 :
				throw DuplicateSensorName(newSensorName);


				// Implementation 2 : catching the exception and
				//  re-throwing it to tests.cpp
				/* try{
					DuplicateSensorName dup(newSensorName);
				}
				catch (std::invalid_argument const& ex)
				{
					// throw a char const* or invalid argument again. Just implement the catch
					// block in tests.cpp accordingly
					throw ex.what();
				}*/
			}
			else{
				newSensorValid = true;
			}
		}
	}
	if (newSensorValid==true){
		//std::cout<<newSensorName << " is added"<<std::endl;
		this->sensors.push_back(move(sensor));
	}

	return *this;
}
