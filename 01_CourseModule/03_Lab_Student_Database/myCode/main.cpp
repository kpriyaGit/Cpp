// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

// project's header files
#include "StudentDb.h"
#include "SimpleUI.h"

// Main program
int main (void)
{

	cout << "APT_Lab3_StudentDatabase started." << endl << endl;
	/**
	 * Object for the student database class
	 */
	StudentDb stDB;
	/**
	 * Object for SimpleUI class that takes parameter of type StudentDb
	 */
	SimpleUI userIf(stDB);
	/**
	 * Start the application
	 */
	userIf.run();

	return 0;
}
