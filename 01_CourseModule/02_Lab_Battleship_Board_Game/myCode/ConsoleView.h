/*
 * ConsoleView.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"

/**
 * This class represents the Game Console that displays necessary info for the players
 */
class ConsoleView
{
private:
	/**
	 * Private Member for storing the address of Board
	 */
	Board* board;
	/**
	 * Private Member for storing the contents of OwnGrid
	 */
	char *pOwnContent;
	/**
	 * Private Member for storing the contents of Opponent Grid
	 */
	char *pOpponentContent;
	/**
	 * Private helper function for getting contents of a particular field in Own/Opponent Grid
	 *  @param array - Own/Opponent content
	 * 	@param row - row number of the field
	 * 	@param col - column number of the field
	 * @returns: char symbol at the field
	 */
	char getContentAt(char* array,char row, int col);
	/**
	 * Private helper function for setting contents of a particular field in Own/Opponent Grid
	 * @param array - Own/Opponent content
	 * @param row - row number of the field
	 * @param col - column number of the field
	 * @param symbol - '#' for Own ship / Sunken ship of opponent
	 * 				   - 'X' for missed shot
	 * 				   - 'O' hit field of ship
	 * 				   - '.' default field notation of own grid and Opponent grid
	 **/
	void setContentAt(char* array, char row, int col ,char symbol);
	/**
	 * Private Helper method for converting row and column into array index
	 * @param row - char type row value of Grid position
	 * @param col - int type col value of the Frid Position
	 * @returns : array index of type int
	 */
	int calcIndex(char row, int col);
	/**
	 * Private Helper method to update the OwnContents array depending upon OwnGrid
	 * (includes Placed ships, hit shots, missed shots, sunken ships)
	 */
	void updateOwnContent();
	/**
	 * Private Helper method to update the OpponentContents array depending upon Opponent Grid
	 * (includes hit shots, missed shots, sunken ships)
	 */
	void updateOpponentContent();
public:
	/**
	 * Parameterized Constructor for pointing to Board
	 * @param: pointer to Board
	 */
	ConsoleView(Board* board);
	/**
	 * Desctructor
	 */
	~ConsoleView();
	/**
	 * Member function for displaying the Grids on the screen
	 */
	void print();

};

#endif /* CONSOLEVIEW_H_ */
