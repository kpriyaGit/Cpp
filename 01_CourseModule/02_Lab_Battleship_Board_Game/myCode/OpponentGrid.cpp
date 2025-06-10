/*
 * OpponentGrid.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */

#include "OpponentGrid.h"


OpponentGrid::OpponentGrid(int rows, int columns)
{
	this->rows=rows;
	this->columns=columns;
}


OpponentGrid::~OpponentGrid()
{

}


int OpponentGrid::getRows() const
{
	return rows;
}

int OpponentGrid::getColumns() const
{
	return columns;
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
	return shots;
}

const std::vector<Ship>& OpponentGrid::getSunkenShips() const
{
	return sunkenShips;
}

void OpponentGrid::addSunkenShips(GridPosition end1, GridPosition end2)
{
	// Find the correct bow and stern ( bow Position is always < stern Position )
	if (end1 < end2)
		sunkenShips.push_back(Ship(end1,end2));
	else
		sunkenShips.push_back(Ship(end2,end1));
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	shots[shot.getTargetPostion()] = impact;

	if(impact == Shot::Impact::SUNKEN)
	{
		GridPosition sinkPoint =  shot.getTargetPostion();
		char sunkenRow = shot.getTargetPostion().getRow();
		int sunkenCol = shot.getTargetPostion().getColumn();
		for(char row = sunkenRow-1; row < sunkenRow+2; row++)
		{
			for (int col = sunkenCol-1;col<sunkenCol+2;col++)
			{
				if(shots[GridPosition(row,col)] == Shot::Impact::HIT)
				{
					GridPosition tempStern = GridPosition(row,col);
					if(tempStern.getRow()==sunkenRow){
						if(tempStern< sinkPoint )
						{
							for(int c=col;c>0;c--)
							{
								if(shots.count(GridPosition(sunkenRow,c)) == 0)
									break;
								if(shots[GridPosition(sunkenRow,c)] == Shot::Impact::HIT)
								{
									tempStern = GridPosition(sunkenRow,c);
									continue;
								}
							}
							addSunkenShips(sinkPoint,tempStern);
						}
						else
						{
							for(int c=col;c<11;c++)
							{
								if(shots.count(GridPosition(sunkenRow,c)) == 0)
									break;
								if(shots[GridPosition(sunkenRow,c)] == Shot::Impact::HIT)
								{
									tempStern = GridPosition(sunkenRow,c);
									continue;
								}
							}
							addSunkenShips(sinkPoint,tempStern);
						}

					}


					if(tempStern.getColumn()==sunkenCol){
						if(tempStern<sinkPoint)
						{
							for(char r=row;r>='A';r--)
							{
								if(shots.count(GridPosition(r,sunkenCol)) == 0)
									break;
								if(shots[GridPosition(r,sunkenCol)] == Shot::Impact::HIT)
								{
									tempStern = GridPosition(r,sunkenCol);
									continue;
								}
							}
							addSunkenShips(sinkPoint,tempStern);
						}
						else
						{
							for(char r=row;r<='J';r--)
							{
								if(shots.count(GridPosition(r,sunkenCol)) == 0)
									break;
								if(shots[GridPosition(r,sunkenCol)] == Shot::Impact::HIT)
								{
									tempStern = GridPosition(r,sunkenCol);
									continue;
								}
							}
							addSunkenShips(sinkPoint,tempStern);
						}
					}
				}
			}
		}
	}
}

