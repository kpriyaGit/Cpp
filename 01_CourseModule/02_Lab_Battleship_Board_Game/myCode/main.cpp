// Standard (system) header files
#include <iostream>
#include <stdlib.h>

#include <string>
#include <map>

using namespace std;

//project header files here
#include "Board.h"
#include "ConsoleView.h"
#include "Test.h"

// Main program
int main (void)
{

	/**
	 * part1tests() Tests the basic GridPosition class
	 */
	part1tests();
	/**
	 * Test for ships correctly placed at
	 * shipEND1 = {"A1","A7","C2","C7","C10","E2","E4","E7","H4","I7"};
	 * shipEND2 = {"A2","A9","C5","C8","E10","I2","E5","F7","J4","I10"};
	 */
	part2tests();
	/**
	 * Test for shots taken by Own player and shot results of Opponent Player
	 * The following symbol notations used :
	 *   '#' for Own SHIP / HIT part of ship
	 *   'X' for MISSED shot both owngrid and opponent grid (also blocked area of Opponent Grid once ship has sunk)
	 *   'O' SUNKEN SHIP
	 * 	 '.' DEFAULT field notation of own grid and Opponent grid
	 */
	part3tests();

	return 0;
}
