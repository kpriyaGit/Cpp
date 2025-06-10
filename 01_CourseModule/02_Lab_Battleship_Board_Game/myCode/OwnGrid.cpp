/*
 * OwnGrid.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */
#include <algorithm>  //to use set_intersection()
using namespace std;
#include "OwnGrid.h"

OwnGrid::OwnGrid(int rows, int columns)
{
	this->rows=rows;
	this->columns=columns;

	//Map Length of ships to number of ships
	//shipTypePair[Length of ship ]= No. of ships
	//Used to keep count of remaining ships while placing the ships on the grid
	shipTypePair[2]=4;
	shipTypePair[3]=3;
	shipTypePair[4]=2;
	shipTypePair[5]=1;
}

OwnGrid::~OwnGrid()
{

}

int OwnGrid::getColumns() const
{
	return columns;
}

int OwnGrid::getRows() const
{
	return rows;
}

const vector<Ship>& OwnGrid::getShips() const
{
	return ships;
}

Shot::Impact  OwnGrid::takeBlow(const Shot& shot)
{
	Shot shootAt=shot;
	Shot::Impact result = Shot::Impact::NONE;
	shotAt.insert(shootAt.getTargetPostion());
	for (Ship iterShip : ships)
	{
		set<GridPosition> tempOccupiedArea = iterShip.occupiedArea();
		if(tempOccupiedArea.count(shootAt.getTargetPostion()))
		{
			result = Shot::Impact::HIT;

			set<GridPosition> intersection;
			set_intersection(tempOccupiedArea.begin(), tempOccupiedArea.end(),shotAt.begin(), shotAt.end(),
					inserter(intersection, intersection.begin()));

			if((int) intersection.size() == iterShip.length())
			{
				result = Shot::Impact::SUNKEN;
				break;
			}
		}
	}
	return result;
}

const std::set<GridPosition>& OwnGrid::getShotAt() const
{
	return shotAt;
}


bool OwnGrid::getUnallocatedShips()
{
	if(shipTypePair[2]==0 && shipTypePair[3]==0 && shipTypePair[4] == 0 && shipTypePair[5]==0)
		return false;
	else
		return true;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	Ship tempShip = ship;
	bool shipsInStraightLine=false, shipLengthCorrect=false, shipsLeft=false;

	// Condition Check
	// 2. The grid fields occupied by a ship form a straight line
	// 4. Ships must be positioned horizontally or vertically
	if(tempShip.isValid())
	{
		shipsInStraightLine =true;
		shipLengthCorrect=true;
	}
	else
		return false;

	// Condition Check
	// 5. Each player has 10 ships (Ship count doesn't exceed the type count limit)
	if(shipTypePair[tempShip.length()] != 0)
		shipsLeft = true;
	else
		return false;

	if(shipsInStraightLine && shipLengthCorrect && shipsLeft)
	{
		set<GridPosition> tempOccupiedArea = tempShip.occupiedArea();
		set<GridPosition> tempBlockedArea ;
		set<GridPosition> intersection;

		for (Ship iterShip : ships)
		{
			set<GridPosition> tBA = iterShip.blockedArea();
			tempBlockedArea.insert(tBA.begin(),tBA.end());
		}

		set_intersection(tempOccupiedArea.begin(), tempOccupiedArea.end(),
				tempBlockedArea.begin(), tempBlockedArea.end(),
				inserter(intersection, intersection.begin()));

		//Condition check
		// 1. Ships may not touch each other
		if(intersection.empty())
		{
			ships.push_back(tempShip);
			shipTypePair[tempShip.length()] = shipTypePair[tempShip.length()] - 1;
			return true;
		}
		else
			return false;
	}
	return false;
}


