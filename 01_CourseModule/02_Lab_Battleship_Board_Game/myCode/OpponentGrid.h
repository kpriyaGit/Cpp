/*
 * OpponentGrid.h
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
#include<vector>
#include<map>
#include "Ship.h"
#include "Shot.h"

/**
 * This class represents Opponent Player's Grid
 */
class OpponentGrid
{
private:
	/**
	 * Private member that denotes the number of rows of the Opponent Player's Grid
	 */
	int rows;
	/**
	 * Private member that denotes the number of columns of the Opponent Player's Grid
	 */
	int columns;
	/**
	 * Private member that represents all the sunken ships of Opponent Player
	 */
	std::vector<Ship> sunkenShips;

	/**
	 * Private member that contains a mapping of the shots at a Grid position and its result(hit/miss/sunken)
	 */
	std::map<GridPosition,Shot::Impact> shots;
public:
	/**
	 * Parameterized constructor that initializes the number of row and columns of the Opponent Player
	 * @param int type row
	 * @param int type column
	 */
	OpponentGrid(int rows, int columns);
	/**
	 * Destructor
	 */
	~OpponentGrid();
	/**
	 * Getter Function for providing the number of rows in Opponent Player's Grid
	 * @returns rows
	 */
	int getRows() const;
	/**
	 * Getter Function for providing the number of columns in Opponent Player's Grid
	 * @returns columns
	 */
	int getColumns() const;
	/**
	 * Member function that updates the result of Player shooting onto Opponenet's Grid
	 * @param shot that contains the target grid position
	 * @param impact that states if the shot hit a ship or a miss or sunk a ship
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);
	/**
	 * Getter function for providing the list of mapping of Shots and their impact
	 * @returns address of private member shots of type map
	 */
	const std::map<GridPosition,Shot::Impact>& getShotsAt() const;
	/**
	 * Method to update the sunken ships of Opponent Player
	 * @param end1- bow/stern of the ship
	 * @param end2- stern/bow of the ship
	 */
	void addSunkenShips(GridPosition end1, GridPosition end2);
	/**
	 * Getter Method for providing all the sunken ships
	 * @returns reference of private attribute sunkenShips of type vector
	 */
	const std::vector<Ship>& getSunkenShips() const;
};

#endif /* OPPONENTGRID_H_ */
