/*
 * GridPosition.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include<string>

/**
 * This Class represents the a single Grid Position on the Grids in the Game.
 */
class GridPosition
{
private:
	/**
	 * Private member that denotes the row of the Grid
	 * Value ranges from A to Z
	 */
	char row;
	/**
	 * Private member that denotes the column of the Grid
	 * Value ranges from 1 to 10
	 */
	int column;
public:
	/**
	 * Parameterized constructor for creating a Grid Postion
	 * @param row - char type row
	 * @param col- integer type column
	 */
	GridPosition(char row,int col);
	/**
	 * Parameterized constructor for creating a Grid Postion
	 * @param string type position that contains a character denoting row of Grid and an integer denoting column of Grid
	 */
	GridPosition(std::string position);
	/**
	 * Desctructor
	 */
	~GridPosition();
	/**
	 * Overloaded cast to string that returns the concatenation of the row and the column
	 */
	operator std::string() const;
	/**
	 * Overloaded Assignment operator to check if 2 Grid Positions are same or not
	 */
	bool operator==(GridPosition other) const;
	/**
	 * Overloaded Less Than operator to check if one Grid Positions is lesser than the other
	 */
	bool operator<(GridPosition other) const;
	/**
	 * Member function to check validity of row and column values
	 * @returns True if row and column are valid
	 * @returns false in case of invalid values
	 */
	bool isValid() const;
	/**
	 * Getter function for providing the Column Value
	 */
	int getColumn() const;
	/**
	 * Getter function for providing the row Value
	 */
	char getRow() const;
};

#endif /* GRIDPOSITION_H_ */
