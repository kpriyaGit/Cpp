/*
 * Ship.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */
#define MAX_LEN_SHIP 5
#define MIN_LEN_SHIP 2

using namespace std;
#include "Ship.h"

Ship::Ship(const GridPosition& bow, const GridPosition& stern):bow{bow},stern{stern}
{

}

Ship::~Ship()
{

}

const GridPosition& Ship::getBow() const
{
	return bow;
}

const GridPosition& Ship::getStern() const
{
	return stern;
}

int Ship::length() const
{
	unsigned short len=0;
	if(stern.getRow() == bow.getRow())
		len = stern.getColumn() - bow.getColumn() + 1;

	if(stern.getColumn() == bow.getColumn())
		len = stern.getRow() - bow.getRow() + 1;

	return len;
}

bool Ship::isValid() const
{
	if((length() >= MIN_LEN_SHIP) && (length() <= MAX_LEN_SHIP) &&
			((stern.getRow() == bow.getRow()) || (stern.getColumn() == bow.getColumn())) &&
			bow.isValid() && stern.isValid())
		return true;
	else
		return false;
}


const set<GridPosition> Ship::occupiedArea() const
{
	set<GridPosition> oAset;
	if(stern.getRow() == bow.getRow())  // for Horizontally placed ships
	{
		for(unsigned short col = bow.getColumn();col<=stern.getColumn();col++)
		{
			GridPosition temp(bow.getRow(),col);
			oAset.insert(temp);
		}

	}
	if(stern.getColumn() == bow.getColumn())  // for Vertically placed ships
	{
		for(unsigned short row = bow.getRow();row<=stern.getRow() ;row++)
		{
			GridPosition tempoA(row,bow.getColumn());
			oAset.insert(tempoA);
		}

	}

	return oAset;

}

const set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> bAset;

	for(GridPosition field : occupiedArea())
	{
		for(int row=field.getRow()-1;row<=field.getRow()+1;row++)
		{
			for(int col=field.getColumn()-1;col<=field.getColumn()+1;col++)
			{
				GridPosition tempbA(row,col);
				if(tempbA.isValid())
					bAset.insert(tempbA);
			}
		}
	}

	return bAset;
}
