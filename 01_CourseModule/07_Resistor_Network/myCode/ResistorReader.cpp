/*
 * ResistorReader.cpp
 *
 *  Created on: 09-Feb-2023
 *      Author: kpriya
 */
#include<iostream>
#include "ResistorReader.h"
#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
using namespace std;

ResistorReader::ResistorReader()
{
	// Auto-generated constructor stub

}

ResistorReader::~ResistorReader()
{
	// Auto-generated destructor stub
}

void ResistorReader::read(std::istream &in,
		std::map<std::string, ResistorPtr> &found)
{
	extern string splitAt(string& remainder, char separator);

	string line;
	getline(in, line);
	while(!line.empty()){
		string::size_type pos = line.find('[');
		if(pos!=string::npos)
		{
			cout<<" Resistor Connection found at "<<pos<<endl;
			string connectionName =splitAt(line,';');
			string::size_type separatorpos = connectionName.find('-');
			if(separatorpos!=string::npos) // Serial connection
			{
				string serialCname = splitAt(connectionName,'[');
				SerialResistorConnection sc(serialCname);

				while(!connectionName.empty()){
					string R3 = splitAt(connectionName,'-');
					sc+= found.at(R3);
					found.erase(R3);
					string R4 = splitAt(connectionName,']');
					sc+= found.at(R4);
					found.erase(R4);
				}
				float value = stof(splitAt(line,';'));
				float tolerance = stof(line);
				ResistorPtr R (new ResistorPart(serialCname,value,tolerance));
				found.emplace(serialCname, R);
			}
			else // parallel connection
			{
				string parallelCname = splitAt(connectionName,'[');
				ParallelResistorConnection pc(parallelCname);
				while(!connectionName.empty()){
					string R3 = splitAt(connectionName,'|');
					pc+= found.at(R3);
					found.erase(R3);
					string R4 = splitAt(connectionName,']');
					pc+= found.at(R4);
					found.erase(R4);
				}
				float value = stof(splitAt(line,';'));
				float tolerance = stof(line);
				ResistorPtr R (new ResistorPart(parallelCname,value,tolerance));
				found.emplace(parallelCname, R);

			}
		}
		else
		{
			cout<<" Resistor Part found "<<endl;
			ResistorPtr newResistorPart = ResistorPart::from(line);

			found.emplace(newResistorPart->getName(), newResistorPart);


		}
		line.clear();
		getline(in, line);
	}


}
