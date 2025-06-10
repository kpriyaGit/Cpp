// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
#include <string>
#include <memory>
#include <fstream> //for ofstream

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "Temperature.h"
#include "Measurement.h"
#include "MeasurementDb.h"
#include "Humidity.h"

// Main program
int main ()
{
	// Add your program code here
	string location;
	cout << "WiSe2019_Meas_Sys started." << endl << endl;

	//Temperature measurement1(-3,Measurement::toTimestamp(15,46));
	shared_ptr<Measurement> measurement1 (new Temperature(20,Measurement::toTimestamp(10,5)) );
	//cout << measurement1.toString() <<endl;
	//cout << measurement1.toTimeOfDay(measurement1.getTimestamp());
	//cout << measurement1 <<endl;

	//Humidity measurement2(80,Measurement::toTimestamp(6,0));
	//cout << measurement2.toString() <<endl;
	shared_ptr<Measurement> measurement2 (new Humidity(78.4567,Measurement::toTimestamp(8,0)) );
	shared_ptr<Measurement> measurement3 (new Temperature(22,Measurement::toTimestamp(12,0)) );
	shared_ptr<Measurement> measurement4 (new Temperature(34,Measurement::toTimestamp(9,5)) );

	MeasurementDb mDB;
	mDB.addMeasurement("Bath", measurement2);
	mDB.addMeasurement("Kitchen", measurement1);
	mDB.addMeasurement("Kitchen", measurement3);
	//mDB.addMeasurement("Bath", measurement4);
	mDB.print();


	//Ex 2 a)
	ofstream outfile;
	string filename = "data.txt";
	outfile.open(filename);
	mDB.save(outfile);
	outfile.close();


	//Ex 2 d)
	ifstream infile;
	infile.open("data.txt");
	mDB.load(infile);
	infile.close();
	mDB.print();

	//Ex 3 b)
	shared_ptr<Measurement> pBase;
	mDB.maximumTemperature(location, pBase);
	cout<<" Location " <<location<< " has max temperature of " <<pBase.get()->toString();
	cout<< " at time "<<pBase.get()->toTimeOfDay(pBase.get()->getTimestamp())<<endl;



	return 0;
}
