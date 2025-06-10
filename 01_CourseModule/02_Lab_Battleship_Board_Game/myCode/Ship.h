/*
 * Ship.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef SHIP_H_
#define SHIP_H_
#include <set>
#include "GridPosition.h"
/**
 * This Class represents a ship in the game
 */
class Ship
{
private:
	/**
	 * Private attribute that represents the front end of the ship(Bow)
	 */
	GridPosition bow;
	/**
	 * Private attribute that represents the back end of the ship(Stern)
	 */
	GridPosition stern;
public:
	/**
	 * Parameterized constructor for creating the ship
	 * @param Grid position of bow of ship
	 * @param Grid position of stern of ship
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);
	/**
	 * Destructor
	 */
	~Ship();
	/**
	 * Method to check the correctness of the Grid position of the ship
	 * Checks for the length of ship and its placement on the grid (horizontal/vertical)
	 * @returns True if Ship has valid positions
	 * 			False in case rules are violated
	 */
	bool isValid() const;
	/**
	 * Getter function that provides the Grid position of Bow of ship
	 * @returns reference to bow
	 */
	const GridPosition& getBow() const;
	/**
	 * Getter function that provides the Grid position of Stern of ship
	 * @returns reference to Stern
	 */
	const GridPosition& getStern() const;
	/**
	 * Member function to compute the length of the ship
	 * @returns integer type lengtht (min-2 / max-5)
	 */
	int length() const;
	/**
	 * Method to get the positions occupied by a ship on the Grid
	 */
	const std::set<GridPosition> occupiedArea() const;
	/**
	 * Method to get the positions that are blocked for occupancy by a ship on the Grid
	 * (region surrounding the occupied Area is a blocked region)
	 */
	const std::set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */
