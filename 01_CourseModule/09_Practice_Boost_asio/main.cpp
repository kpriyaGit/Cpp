// Standard (system) header files
#include <iostream>
#include <stdlib.h>
// Add more standard header files as required

#include <boost/asio.hpp>

using namespace std;

// Add your project's header files here

// Main program
int main (void)
{
    // Add your program code here
	cout << "Boost-Demo started." << endl << endl;

	boost::asio::ip::tcp::iostream stream;
	stream.connect("time-c-g.nist.gov", "37");

	if (!stream) {
		cout << "Cannot connect." << endl;
		return 0;
	}

	char bytes[4];
	stream.read(bytes, 4);
	if (stream.fail()) {
		cout << "Read failed." << endl;
		return 0;
	}

	long secs = 0;
	for (int i = 0; i < 4; i++) {
		secs = secs << 8;
		secs += (unsigned char)bytes[i];
		cout << (int)bytes[i] << endl;
	}
	
	cout <<"Total seconds since 1900" <<endl;
	cout << secs << endl;        // Total seconds since 1900
	
	cout << secs % 60 << endl;   // Seconds
	secs /= 60;
	cout << secs % 60 << endl;   // Minutes
	secs /= 60;
	cout << secs % 24 << endl;   // Hours
	secs /= 24;
	cout << secs / 365 << endl;  // Years since 1900


	return 0;
}
