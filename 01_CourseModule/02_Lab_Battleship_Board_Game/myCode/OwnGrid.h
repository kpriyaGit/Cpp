/*
 * OwnGrid.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <vector>
#include <map>
#include <set>
#include "Ship.h"
#include "Shot.h"

/**
 * This class represents the Player's Own Grid
 */
class OwnGrid
{
private:
	/**
	 * Private member that denotes the number of rows of the Own Grid
	 */
	int rows;
	/**
	 * Private member that denotes the number of columns of the Own Grid
	 */
	int columns;
	/**
	 * Private member that stores all 10 ships of Player
	 */
	std::vector<Ship> ships;
	/**
	 * Private attribute denoting the pairs "length"/"number of ships" of the Own Player
	 */
	std::map<int,int> shipTypePair;
	/**
	 * Private attribute that contains all the blocked regions around ships on the OwnPlayer's Grid
	 */
	std::set<GridPosition> blockedGridPositions;
	/**
	 * Private attribute that contains all the positions occupied by Player's ships
	 */
	std::set<GridPosition> occupiedGridPositions;
	/**
	 * Private attribute that contains all the positions on Own Player's Grid that were shot by the opponent player
	 */
	std::set<GridPosition> shotAt;
public:
	/**
	 * Parameterized constructor that initializes the number of row and columns of the Own Player
	 * @param int type row
	 * @param int type column
	 */
	OwnGrid(int rows, int columns);
	/**
	 * Destructor
	 */
	~OwnGrid();
	/**
	 * Getter Function for providing the number of columns in Own Player's Grid
	 * @returns columns
	 */
	int getColumns() const;
	/**
	 * Getter Function for providing the number of rows in Own Player's Grid
	 * @returns rows
	 */
	int getRows() const;
	/**
	 * Getter Method for providing all the ships of OwnPlayer
	 * @returns reference of private attribute ships of type vector
	 */
	const std::vector<Ship>& getShips() const;
	/**
	 * Method for placing the 10 ships on the Own Player's Grid
	 * @param a new Ship object
	 * @returns True if ship was successfully placed after all rules check
	 * 			False if rules are violated(and ship not placed)
	 */
	bool placeShip(const Ship& ship);
	/**
	 * Method to check if all the ships have been placed or not
	 * @return True is ships to be placed are remaining
	 * 			False if all ships are placed
	 */
	bool getUnallocatedShips();
	/**
	 *Method for getting the shot from the Opponent Player
	 *@param Shot that contains target Grid position on the Own Player's Grid
	 *@returns the result of shot - impact that states if the shot hit a ship or a miss or sunk a ship
	 */
	Shot::Impact takeBlow(const Shot& shot);
	/**
	 * Getter function for providing all the positions on Own Player's Grid that were shot by the opponent player
	 * @returns reference to private set type attribute 'shotAt'
	 */
	const std::set<GridPosition>& getShotAt() const;
};

#endif /* OWNGRID_H_ */
