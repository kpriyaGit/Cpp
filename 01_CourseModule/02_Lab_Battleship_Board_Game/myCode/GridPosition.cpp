/*
 * GridPosition.cpp
 *
 *  Created on: 07-Dec-2021
 *      Author: kpriya
 */
#include "GridPosition.h"
using namespace std;

GridPosition::GridPosition(char row,int col)
{
	this->row=row;
	this->column=col;
}

GridPosition::GridPosition(std::string position)
{
	//The first element is a character
	this->row = position[0];

	//Convert the remaining part of string to integer( 1 or 2 characters depending on the value of column)
	this->column = stoi(position.substr(1, (position.length()-1)));
}

GridPosition::operator std::string() const
{
	string pos = row + to_string(column);
	return pos;
}

bool GridPosition::operator ==(GridPosition other) const
{
	if((this->row == other.row) && (this->column == other.column))
		return true;
	else
		return false;
}

bool GridPosition::operator <(GridPosition other) const
{
	if(this->row < other.row)
		return true;
	if((this->row == other.row) && (this->column < other.column))
		return true;
	else
		return false;
}


bool GridPosition::isValid() const
{
	if(row>='A' && row<='Z' && column>0 && column <11)
		return true;
	else
		return false;
}

char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

GridPosition::~GridPosition()
{

}

