#include "Sensor.h"
#include "Adjuster.h"

Sensor::~Sensor() {
}

std::string Sensor::getName() const {
    return name;
}

Sensor::Sensor(const std::string& name, std::shared_ptr<Adjuster> adjuster): name{name},
		adjuster{adjuster}
{

}

float Sensor::reading() const {

	float rawValue = this->rawReading();
	float sensorVal = this->adjuster->adjust(rawValue);
    return sensorVal;
}
