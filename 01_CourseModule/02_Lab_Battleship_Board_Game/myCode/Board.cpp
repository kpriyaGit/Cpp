/*
 * Board.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#include "Board.h"

Board::Board(int rows, int columns):
opponentGrid{OpponentGrid(rows,columns)},ownGrid{OwnGrid(rows,columns)}
{


}

Board::~Board()
{

}

OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}

OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

int Board::getRows() const
{
	return false;
}

int Board::getColumns() const
{
	return false;
}


