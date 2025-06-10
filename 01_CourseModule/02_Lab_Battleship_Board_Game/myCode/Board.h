/*
 * Board.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * This Class represents the entire Game sheet that include sheets of both the players
 */
class Board
{
private :
	/**
	 * Private Member for storing the contents of Opponent Player
	 */
	OpponentGrid opponentGrid;
	/**
	 * Private Member for storing the contents of Own Player
	 */
	OwnGrid ownGrid;

public:
	/**
	 * Parameterized Constructor that creates Grid Objects for both the Players
	 *  @param  row- Number of rows of the Grid
	 * 	@param  columns - Number of columns of the Grid
	 */
	Board(int rows, int columns);
	/**
	 * Destructor
	 */
	~Board();
	/**
	 * Member function that provides value of the row of Opponent/Own Grid
	 * @returns: row
	 */
	int getRows() const;
	/**
	 * Member function that provides value of the row of Opponent/Own Grid
	 * @returns: columns
	 */
	int getColumns() const;
	/**
	 * Member function for accessing contents of Opponent grid
	 * @returns : Address of Opponent Grid Object
	 */
	OpponentGrid& getOpponentGrid();
	/**
	 * Member function for accessing contents of Own grid
	 * @returns : Address of Own Grid Object
	 */
	OwnGrid& getOwnGrid();
};

#endif /* BOARD_H_ */
