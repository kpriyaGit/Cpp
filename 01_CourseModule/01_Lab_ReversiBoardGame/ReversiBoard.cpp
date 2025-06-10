/*
 * ReversiBoard.cpp
 *
 *  Created on: 07-Nov-2021
 *      Author: kpriya
 */

#define TRUE 1
#define FALSE 0
#define WRONGINDEX -1


#include<iostream>
using namespace std;

#include "ReversiBoard.h"

ReversiBoard::ReversiBoard()
{

}
ReversiBoard::ReversiBoard(unsigned short rowSize, unsigned short colSize, unsigned char Player1Symbol, unsigned char Player2Symbol)
{
	this->rowSize=rowSize;
	this->colSize=colSize;

	this->pcontent = new unsigned char [this->rowSize * this->colSize];
	for(unsigned short index=0;index<rowSize*colSize;index++)
	{
		this->pcontent[index]=' ';
	}

	this->pcontent[this->calcIndex(3,3)]=Player1Symbol;
	this->pcontent[this->calcIndex(4,4)]=Player1Symbol;
	this->pcontent[this->calcIndex(3,4)]=Player2Symbol;
	this->pcontent[this->calcIndex(4,3)]=Player2Symbol;

	cout<<this->rowSize<<"X"<<this->colSize<<" Game board created"<<endl;
}

ReversiBoard::~ReversiBoard()
{
	delete [] pcontent;
	this->rowSize=0;
	this->colSize=0;
}


short ReversiBoard::calcIndex(unsigned short row, unsigned short col)
{
	unsigned short result = 0;

	if (row >= this->rowSize || col >= this->colSize )
	{
		result = WRONGINDEX;
	}
	else
	{
		result = row * this->colSize + col;
	}

	return result;
}



char ReversiBoard::getFieldState(unsigned short row, unsigned short col)
{
	return (this->pcontent[this->calcIndex(row,col)]);
}



bool ReversiBoard::setFieldState(unsigned short row, unsigned short col, unsigned char coin)
{
	short index = this->calcIndex(row,col);
	short moveValidityStatus = FALSE;
	std::vector<int> flippableindices;


	if (WRONGINDEX == index)
	{
		cout<<"OOPS...Index out of range"<<endl;
		return FALSE;
	}

	moveValidityStatus = this->checkMoveValidity(row,col,coin,flippableindices);

	if(FALSE==moveValidityStatus)
	{
		cout<<"OOPS...Invalid move..Choose a valid spot"<<endl;
		return FALSE;
	}
	if(WRONGINDEX==moveValidityStatus)
		{
			cout<<"OOPS...Place already occupied..Choose a valid spot"<<endl;
			return FALSE;
		}

	//Correct position
	if(TRUE==moveValidityStatus)
	{
		this->pcontent[index] = coin;
		cout<<"Move is valid...Flipping Opponent player's coin"<<endl;
		return this->flipCoin(flippableindices,coin);

	}
	return TRUE;
}



bool ReversiBoard::flipCoin(std::vector<int> &flippableindices,char coin){
	for (unsigned short idx=0;idx<flippableindices.size();idx++)
	{
		this->pcontent[flippableindices[idx]]=coin;
		//cout<<"Turning opponent's coins.."<<flippableindices[idx]<<endl;
	}
	return TRUE;
}



bool ReversiBoard::checkIfGameOver()
{
	for (unsigned short row=0;row<this->rowSize;row++)
	{
		for(unsigned short col=0;col<this->colSize;col++)
		{
			if(this->getFieldState(row,col)==' ')
				return TRUE;
		}
	}
	return FALSE;
}


short ReversiBoard::checkMoveValidity(unsigned short row, unsigned short col, unsigned char coin, std::vector<int>& flippableindices)
{
    const unsigned char othercoin = (coin == 'x') ? 'o' : 'x';

    if (this->pcontent[this->calcIndex(row, col)] != ' ')
        return WRONGINDEX;

    // 8 directions: N, NE, E, SE, S, SW, W, NW
    const int directions[8][2] = {
        {-1,  0}, {-1,  1}, {0,  1}, {1,  1},
        { 1,  0}, { 1, -1}, {0, -1}, {-1, -1}
    };

    bool valid = false;

    for (const auto& dir : directions) {
        int r = row + dir[0];
        int c = col + dir[1];

        std::vector<int> tempFlips;

        // First step must be opponent's coin
        if (r >= 0 && r < 8 && c >= 0 && c < 8 && this->pcontent[this->calcIndex(r, c)] == othercoin) {
            // Continue in same direction
            while (true) {
                tempFlips.push_back(this->calcIndex(r, c));
                r += dir[0];
                c += dir[1];

                if (r < 0 || r >= 8 || c < 0 || c >= 8)
                    break;

                char current = this->pcontent[this->calcIndex(r, c)];

                if (current == ' ')
                    break;
                if (current == coin) {
                    flippableindices.insert(flippableindices.end(), tempFlips.begin(), tempFlips.end());
                    valid = true;
                    break;
                }
                // else: keep looping
            }
        }
    }

    return valid ? TRUE : FALSE;
}
