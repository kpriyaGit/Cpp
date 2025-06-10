/*
 * ReversiConsoleView.h
 *
 *  Created on: 07-Nov-2021
 *      Author: kpriya
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * Class that just separates the output display of the Board game
 */
class ReversiConsoleView
{
private:
	/**
	 * Member variable m_board that represents the board of the class  ReversiBoard
	 */
	ReversiBoard m_board;

public:
	/**
	 * Parameterized constructor
	 * @params: Address of instance of class ReversiBoard
	 */
	ReversiConsoleView(ReversiBoard& board);
	ReversiConsoleView();
	~ReversiConsoleView();
	/**
	 * Method print that displays the board on the console
	 */
	void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */
