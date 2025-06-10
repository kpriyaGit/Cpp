#include "DuplicateSensorName.h"

using namespace std;

DuplicateSensorName::DuplicateSensorName(std::string sensorName):invalid_argument{sensorName}
{
	//throw invalid_argument(sensorName + " is duplicate.");
}
