/*
 * ConsoleView.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */
#include <iostream>
#include <algorithm> // for set_intersection
#include <utility> // for pair<>

using namespace std;
#include "ConsoleView.h"

ConsoleView::ConsoleView(Board* board)
{
	//copy the address of board
	this->board=board;

	//Create an char array to store Own Grid Contents
	pOwnContent = new char [board->getOwnGrid().getRows() * board->getOwnGrid().getColumns()];
	//Initialize all the fields of OwnGrid to '.'
	for(unsigned short index=0;index<board->getOwnGrid().getRows() * board->getOwnGrid().getColumns();index++)
	{
		this->pOwnContent[index]='.';
	}

	//Create an char array to store Opponent Grid Contents
	pOpponentContent = new char [board->getOpponentGrid().getRows() * board->getOpponentGrid().getColumns()];
	//Initialize all the fields of Opponent Grid to '~'
	for(unsigned short index=0;index<board->getOpponentGrid().getRows() * board->getOpponentGrid().getColumns();index++)
	{
		this->pOpponentContent[index]='.';
	}

}

ConsoleView::~ConsoleView()
{
delete [] pOwnContent;
delete [] pOpponentContent;

}

void ConsoleView::updateOwnContent()
{
	/**
	 * Show the ships
	 */
	for (Ship iterShip : board->getOwnGrid().getShips())
	{
		for(GridPosition iterPos : iterShip.occupiedArea())
		{
			setContentAt(pOwnContent, iterPos.getRow(),iterPos.getColumn()-1, '#');
		}
	}

	/*
	 * Show all shots as ^
	 */
	set<GridPosition> ownShotslist = board->getOwnGrid().getShotAt();
	for(GridPosition iterPos : ownShotslist )
	{
		setContentAt(pOwnContent, iterPos.getRow(),iterPos.getColumn()-1, 'X');
	}
	/*
	 * Show the hits as O and the blocked area around sunken ships as 'X'
	 */
	for (Ship iterShip : board->getOwnGrid().getShips())
	{
		set<GridPosition> tempOccupiedArea = iterShip.occupiedArea();

		set<GridPosition> intersection;
		set_intersection(tempOccupiedArea.begin(), tempOccupiedArea.end(),
				ownShotslist.begin(), ownShotslist.end(),
				inserter(intersection, intersection.begin()));
		if(!intersection.empty())
		{
			for (GridPosition itinter: intersection)
			{
				setContentAt(pOwnContent, itinter.getRow(),itinter.getColumn()-1, 'O');
			}
		}
	}
}

void ConsoleView::updateOpponentContent()
{
	/*
	 * Update Hits as '#' and missed shots as 'X'
	 */
	std::map<GridPosition,Shot::Impact> shots = board->getOpponentGrid().getShotsAt();
	for( pair<GridPosition,Shot::Impact> element : shots )
	{
		if(shots[element.first]==Shot::Impact::NONE)
			setContentAt(pOpponentContent,element.first.getRow(),element.first.getColumn()-1, 'X');
		else
			setContentAt(pOpponentContent,element.first.getRow(),element.first.getColumn()-1, '#');
	}

	/**
	 * show sunken ships as 'O'
	 */
	for (Ship iterShip : board->getOpponentGrid().getSunkenShips())
	{
		for(GridPosition iterPos: iterShip.blockedArea())
			setContentAt(pOpponentContent, iterPos.getRow(),iterPos.getColumn()-1, 'X');
		for(GridPosition iterPos: iterShip.occupiedArea())
			setContentAt(pOpponentContent, iterPos.getRow(),iterPos.getColumn()-1, 'O');
	}
}

void ConsoleView::print()
{
	updateOwnContent();
	updateOpponentContent();

	cout<<endl<<"                   Own Grid";
	cout<< "                                                    ";
	cout<<"Opponent Grid";
	cout<<endl <<"   ";
	for (int col = 0; col < board->getOwnGrid().getColumns(); col++)
	{
		cout<<"  "<<col+1<<"  ";
	}

	cout<<"       ";
	for (int col = 0; col < board->getOpponentGrid().getColumns(); col++)
	{
		cout<<"  "<<col+1<<"  ";
	}

	cout<<endl;
	cout<<"  +--------------------------------------------------+";
	cout<<"      ";
	cout<<"+--------------------------------------------------+"<<endl;

	for (int row = 0; row < board->getOwnGrid().getRows(); row++)
	{
		cout<<char(row + 65)<<" |";
		for (int col = 0; col < board->getOwnGrid().getColumns(); col++)
		{
			cout<<"  ";
			cout<<getContentAt(pOwnContent,row+65,col);
			cout<<"  ";
		}
		cout<<"|    ";
		cout<<char(row + 'A')<<" |";
		for (int col = 0; col < board->getOpponentGrid().getColumns(); col++)
		{
			cout<<"  ";
			cout<<getContentAt(pOpponentContent,row+65,col);
			cout<<"  ";
		}
		cout<<"|";
		if(row==9)
			break;
		cout<<endl<<endl;
	}
	cout<<endl<<"  +--------------------------------------------------+";
	cout<<"      ";
	cout<<"+--------------------------------------------------+"<<endl;
}

char ConsoleView::getContentAt(char* array, char row, int col)
{
	return array[calcIndex(row,col)];
}

void ConsoleView::setContentAt(char* array, char row, int col, char symbol)
{

	array[calcIndex(row,col)] = symbol;
}

int ConsoleView::calcIndex(char row, int col)
{
	int result = 0;
	row = (int)row - 'A';
	result = (int)row * (this->board->getOwnGrid().getColumns()) + col;
	return result;
}
