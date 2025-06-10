/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 07-Nov-2021
 *      Author: kpriya
 */

#include<iostream>
using namespace std;
#include "ReversiConsoleView.h"

ReversiConsoleView::ReversiConsoleView()
{

}

ReversiConsoleView::ReversiConsoleView(ReversiBoard& board)
{
	m_board = board;
	cout<<"ReversiConsoleView initialized"<<endl;
}

ReversiConsoleView::~ReversiConsoleView()
{
	// Auto-generated destructor stub
}

void ReversiConsoleView::print()
{
	//m_board.printboard();

	cout<<"    ";
	for (unsigned int col = 0; col < 8; col++)
	{
		cout<<" "<<col<<"  ";
	}
	cout<<endl<<"   ---------------------------------"<<endl;
	for (unsigned int row = 0; row < 8; row++)
	{
		cout<<row<<"  ";
		for (unsigned int col = 0; col < 8; col++)
		{
			cout<<"| "<< m_board.getFieldState(row,col) <<" ";
		}
		cout<<"|"<<endl<<"   ---------------------------------"<<endl;

	}

}
