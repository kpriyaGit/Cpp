// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

// Project's header files here
#include "ModuloNCounter.h"
#include "ModuloNDigit.h"

// Main program
int main (void)
{
    cout << "Ex_2_MultiCounter started." << endl << endl;
    /**
     * Variable declarations & initializations
     */
    unsigned short baseType = 16 ,numOfDigits = 3, numOfTimes = 20, i = 0;

	/**
	 * TEST FOR POST INCREMENT OPERATOR OVERLOADING
	 */
	ModuloNDigit counter1(numOfDigits, baseType);
	cout<<endl<<"Counter of type "<<dec<< baseType<<" initialized to value "<<counter1<<endl;
	cout<<"TEST FOR POST INCREMENT OPERATOR OVERLOADING"<<endl;
	for(i=0;i<numOfTimes;i++)
	{
	cout << counter1++ << endl;
	}

	/**
	 * TEST FOR PRE INCREMENT OPERATOR OVERLOADING
	 */

	ModuloNDigit counter2(numOfDigits, baseType);
	cout<<endl<<"Counter of type "<<dec<< baseType<<" initialized to value "<<counter2<<endl;
	cout<<"TEST FOR PRE INCREMENT OPERATOR OVERLOADING"<<endl;
	for(i=0;i<numOfTimes;i++)
	{
	cout << ++counter2<<endl;
	}

	return 0;
}
