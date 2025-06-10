#include <iostream>
#include <cstdlib>
#include <memory>
#include <math.h>

using namespace std;

#include "TestSensor.h"
#include "LinearAdjuster.h"
#include "TableBasedAdjuster.h"
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
	if (!condition) {
		cout << failedMessage << endl;
	}
}

/**
 * Tests for the adjustor classes. (12 points)
 */
void adjusterTests() {


	// * Values for subsequent tests.

	float testValues[] = { -10, -1, 0, 1, 10 };


	// * (1) Using the test values given above as samples, assert that a
	// * NullAdjustor's adjust method returns the argument's value
	// * unchanged.
	
	// Add your Code here
	NullAdjuster nAdj;
	for (auto iter:testValues){
		assertTrue((iter == nAdj.adjust(iter)),"NullAdjustor's Test failed");
		assertTrue((iter != nAdj.adjust(iter)),"NullAdjustor's Test Passed");
	}

	// * (2) Using the test values given above as samples, assert that a
	// * TableBasedAdjustor with a single breakpoint (0,0) returns
	// * the same values as a NullAdjustor.

	// Add your Code here
	TableBasedAdjuster tAdj;
	tAdj.addBreakpoint(0, 0);
	for (auto iter:testValues){
		assertTrue((iter == tAdj.adjust(iter)),"TableBasedAdjustor's Test failed");
		assertTrue((iter != tAdj.adjust(iter)),"TableBasedAdjustor's Test Passed");
	}


	// * (3) Using the test values given above as samples, assert that a
	// * TableBasedAdjustor with breakpoints (-100,-110), (0,0)
	// * and (100,90) returns the given expected values.
	// *
	// * Remember (from your basic C/C++ courses) that floating
	// * point calculations do not always yield exact results
	// * (rounding errors due to using the binary system).
	// * Take this into account when checking the result.

	float expected[] = { -11, -1.1, 0, 0.9, 9 };
	TableBasedAdjuster t2Adj;
	t2Adj.addBreakpoint(-100, -110);
	t2Adj.addBreakpoint(0, 0);
	t2Adj.addBreakpoint(100, 90);
	int i=0;
	for (auto iter:testValues){
		float adjVal = round( 10 * t2Adj.adjust(iter))/10;  // otherwise -1.1 test case fails
		assertTrue(( adjVal == expected[i]),"TableBasedAdjustor 2's Test failed");
		assertTrue(( adjVal != expected[i]),"TableBasedAdjustor 2's Test Passed");
		i++;
	}
}


/**
 * Tests for the sensor classes. (12 points)
 */
void sensorTests () {


	//	 * Values for subsequent tests.

	float testValues[] = { -10, -1, 0, 1, 10 };


	//	 * (1) Using a TestSensor and the test values given above as samples,
	//	 * assert that a (test) sensor with a NullAdjustor returns the raw
	//	 * readings of a sensor as readings.

	// Add your Code here
	string nametS1 = "tS1";
	shared_ptr<Adjuster> adj1 (new NullAdjuster());
	//shared_ptr<Adjuster> adj1 = make_shared<NullAdjuster>();
	TestSensor tS1(nametS1, adj1);
	for (auto item:testValues){
		tS1.setRawReading(item);
		assertTrue((item == tS1.reading()),"TestSensor with NullAdjustor Test failed");
		assertTrue((item != tS1.reading()),"TestSensor with NullAdjustor Test Passed");
	}


	//	 * (2) Using a TestSensor and the test values given above as samples,
	//	 * assert that a (test) sensor with a LinearAdjustor returns the
	//	 * expected readings. Test with 10 differently configured
	//	 * LinearAdjustors for each test value for exhaustive testing
	//	 * (50 "assertTrue" invocations in total).

	// Add your Code here

	string nametS2 = "tS2";
	shared_ptr<Adjuster> adj2 (new LinearAdjuster());
	//shared_ptr<Adjuster> adj1 = make_shared<NullAdjuster>();
	TestSensor tS2(nametS2, adj2);
	for (auto item:testValues){
		tS2.setRawReading(item);
		assertTrue((item == tS2.reading()),"TestSensor with LinearAdjustor Test1 failed");
		assertTrue((item != tS2.reading()),"TestSensor with LinearAdjustor Test1 Passed");
	}

	string nametS3 = "tS3";
	shared_ptr<Adjuster> adj3 (new LinearAdjuster(-2));
	//shared_ptr<Adjuster> adj1 = make_shared<NullAdjuster>();
	TestSensor tS3(nametS3, adj3);
	for (auto item:testValues){
		tS3.setRawReading(item);
		assertTrue(((-2*item) == tS3.reading()),"TestSensor with LinearAdjustor Test2 failed");
		assertTrue(((-2*item) != tS3.reading()),"TestSensor with LinearAdjustor Test2 Passed");
	}

	string nametS4 = "tS4";
	shared_ptr<Adjuster> adj4 (new LinearAdjuster(0.2,-5));
	//shared_ptr<Adjuster> adj1 = make_shared<NullAdjuster>();
	TestSensor tS4(nametS4, adj4);
	for (auto item:testValues){
		float expectedVal = -5 + round (0.2 * item * 10)/10;
		tS4.setRawReading(item);
		assertTrue((expectedVal == tS4.reading()),"TestSensor with LinearAdjustor Test3 failed");
		assertTrue((expectedVal != tS4.reading()),"TestSensor with LinearAdjustor Test3 Passed");
	}
}

/**
 * Tests for the sensor network. (16 points)
 */
void networkTests() {
	/*
	 * Create a sensor network with 10 TestSensors named
	 * "Thermometer n" (with n being the number of the thermometer)
	 * that have their readings set to values 20 + n * 0.05.
	 */
	SensorNetwork sNW;
	for (int num = 1; num <11; num++){

		string sensorName = "Thermometer " + to_string(num);
		shared_ptr<Adjuster> adj = make_shared<LinearAdjuster>(0.05 * num , 20);
		unique_ptr<Sensor> tempSensor (new TestSensor(sensorName, adj));
		assertTrue((&sNW.add(move(tempSensor))==NULL),sensorName + " added to network");
		/* try{
			sNW.add(move(tempSensor));
			assertTrue(false,sensorName + " added to network");
		}
		catch (std::invalid_argument const& ex){ // catch invalid argument
			std::cout<<" Inside networkTests"<<std::endl;
			assertTrue(false, ex.what());
		}*/

	}


	/*
	 * (1) Assert that adding a sensor with a name that is already
	 * used by a sensor in the network throws a DuplicateSensorName
	 * exception with the sensor's name as "what".
	 */
	// Add your Code here
	int num = 4;
	string sensorName1 = "Thermometer " + to_string(num);
	shared_ptr<Adjuster> adj1 = make_shared<LinearAdjuster>(0.05 , 20+num);
	unique_ptr<Sensor> tempSensor1 (new TestSensor(sensorName1, adj1));
	try{
		sNW.add(move(tempSensor1));
		assertTrue(false,sensorName1 + " added to network");
	}
	catch (std::invalid_argument const& ex){ // catch invalid argument
		assertTrue(sensorName1!= ex.what(), sensorName1 + " not added to network (duplicate name)");
	}
//	catch (char const* ex){  // catch char const*
//		assertTrue(sensorName1!= ex, sensorName1 + " not added to network (duplicate name)");
//	}
}

void allTests() {
	adjusterTests();
	sensorTests();
	networkTests();
}
