// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <fstream>
// Add more standard header files as required

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "ResistorPart.h"
#include "ResistorConnection.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "ResistorReader.h"

string splitAt(string& remainder, char separator) {
	string::size_type pos = remainder.find(separator);
	if (pos == string::npos) {
		string result = remainder;
		remainder.clear();
		return result;
	}
	string result = remainder.substr(0, pos);
	remainder = remainder.substr(pos + 1);
	return result;
}

// Main program
int main ()
{
	// Add your program code here
	cout << "SoSe2022_Resistor_Nw started." << endl << endl;
	//ResistorPtr R1 (new ResistorPart("R1", 42 , 5 ));
	shared_ptr<Resistor> R1 (new ResistorPart("R1", 42 , 5 ));
	//cout<<R1.get()->toString();
	//cout<<R1->toString() <<endl;

	//Ex1 c, d)
	cout<<R1;
	//Ex1 f, g)
	shared_ptr<Resistor> R3 (new ResistorPart("R3", 1000 , 10 ));
	shared_ptr<Resistor> R4 (new ResistorPart("R4", 4700 , 10 ));
	cout<<R3;
	cout<<R4;
	SerialResistorConnection R2("R2");
	R2+=R3;
	R2+=R4;

	cout<<R2.getName()<<R2.toString();

	//Ex1 h, i)
	shared_ptr<Resistor> R6 (new ResistorPart("R6", 1000 , 10 ));
	shared_ptr<Resistor> R7 (new ResistorPart("R7", 4700 , 10 ));
	ParallelResistorConnection R5("R5");
	R5+=R6;
	R5+=R7;

	cout<<R5.getName()<<R5.toString();

	// Ex 2 a), b), c)
	ofstream outfile;
	string outfilename="data1.txt";
	outfile.open(outfilename); outfile<<R1->getName()<<';';
	R1->write(outfile);
	R3->write(outfile);
	R4->write(outfile);
	R2.write(outfile);
	R6->write(outfile);
	R7->write(outfile);
	R5.write(outfile);
	outfile.close();

	//Ex 2 d-f)
	ifstream infile;
	string infilename="data1.txt";
	std::map<std::string, ResistorPtr> found;
	infile.open(infilename);
	ResistorReader::read(infile,found);

	infile.close();

	for(auto &R: found){
		cout<<R.second->getName()<<R.second->toString()<<endl;
	}

	return 0;
}
