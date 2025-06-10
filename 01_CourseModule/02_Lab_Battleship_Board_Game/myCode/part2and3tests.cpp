/*
 * part2tests.cpp
 *
 *  Created on: 10-Dec-2021
 *      Author: kpriya
 */

#include <iostream>
#include <string>

using namespace std;
#include "Test.h"


Board TestBoard(10,10);
ConsoleView TestConsole(&TestBoard);


/**
 * part2tests() checks for all arrangement rules
 */
void part2tests () {
    // Test Arrangement rules
	cout<<"Part 2 Testing Arrangement rules..."<<endl;
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("A1"), GridPosition("A2"))),"Ship A1A2 not inserted");
	//invalid pos
	assertTrue(!(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("A3"), GridPosition("C3")))),"Ship A3C3 inserted");

	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("A7"), GridPosition("A9"))),"Ship A7A9 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("C2"), GridPosition("C5"))),"Ship C2C5 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("C7"), GridPosition("C8"))),"Ship C7C8 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("C10"), GridPosition("E10"))),"Ship C10E10 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("E2"), GridPosition("I2"))),"Ship E2I2 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("E4"), GridPosition("E5"))),"Ship E4E5 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("E7"), GridPosition("F7"))),"Ship E7F7 not inserted");
	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("H4"), GridPosition("J4"))),"Ship H4J4 not inserted");
	//invalid Pos
	assertTrue(!(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("F6"), GridPosition("I6")))),"Ship F6I6 inserted");

	assertTrue(TestBoard.getOwnGrid().placeShip(Ship(GridPosition("I7"), GridPosition("I10"))),"Ship I7I10 not inserted");
	cout<<"Part 2 Tests done"<<endl;
	TestConsole.print();
}

/**
 * Test for shots taken by Own player and shot results of Opponent Player
 */
void part3tests () {
    // Test Shots taken by Own Grid
    cout<<"Part 3 Testing Shots taken by Own Grid..."<<endl;

    assertTrue(!(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("E10")))==Shot::Impact::NONE), "Shot E10 is a miss");
	assertTrue(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("C2")))==Shot::Impact::HIT, "Shot C2 not hit");
	assertTrue(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("C3")))==Shot::Impact::HIT, "Shot C3 not hit");
	assertTrue(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("C4")))==Shot::Impact::HIT, "Shot C4 not hit");
	assertTrue(!(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("C1")))==Shot::Impact::SUNKEN), "Shot C1 Sunk the ship");
	assertTrue(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("C5")))==Shot::Impact::SUNKEN, "Shot C5 not hit");
	assertTrue(!(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("G5")))==Shot::Impact::HIT), "Shot G5 hit");
	assertTrue(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("B5")))==Shot::Impact::NONE, "Shot B5 is not a miss");
	assertTrue(TestBoard.getOwnGrid().takeBlow(Shot(GridPosition("J4")))==Shot::Impact::HIT, "Shot J4 not hit");
	TestConsole.print();

	cout<<"Part 3 Testing Results of Shots taken by Opponent Grid..."<<endl;
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("C3")), Shot::Impact::HIT);
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("C2")), Shot::Impact::NONE);
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("C4")), Shot::Impact::HIT);
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("F5")), Shot::Impact::HIT);
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("F6")), Shot::Impact::HIT);
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("F4")), Shot::Impact::NONE);
	TestBoard.getOpponentGrid().shotResult(Shot(GridPosition("F7")), Shot::Impact::SUNKEN);
	TestConsole.print();

}



