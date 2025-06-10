/*
 * OwnGrid.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef TEST_H_
#define TEST_H_

#include "Board.h"
#include "ConsoleView.h"

//static Board TestBoard(10,10);
//static ConsoleView TestConsole(&TestBoard);

void part1tests ();
void part2tests ();
void part3tests ();

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
inline void assertTrue(bool condition, string failedMessage){
	if (!condition) {
	        cout << failedMessage << endl;
	    }
}

#endif /* TEST_H_*/
