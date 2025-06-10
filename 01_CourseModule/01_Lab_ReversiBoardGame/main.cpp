// Standard (system) header files
#include <iostream>
#include <stdlib.h>

// Add more standard header files as required

using namespace std;

// Project's header files here
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

// Main program
int main (void)
{
	/**
	 * Variable declarations, initializations and instance creations
	 */
	int row, col = 0, Player=0,Fieldstatus=0,Gamestatus=0, Player1score=0,Player2score=0;
	unsigned char Player1Symbol = 'x', Player2Symbol = 'o';

	cout << "Ex_1_Board_Reversi started." << endl << endl;

	ReversiBoard pMyBoard(8,8,Player1Symbol,Player2Symbol);
	ReversiConsoleView console(pMyBoard);

	console.print();

	/**
	 * Play the game
	 */

	do
	{
		cout<<"Player"<<Player+1<<" Please enter row column (8 8 to stop the game): ";
		cin >>row >> col ;
		if(row>7||col>7) break;

		//Set the coin(Player Symbol)
		if(Player==0)
			Fieldstatus=pMyBoard.setFieldState(row,col,Player1Symbol);
		else
			Fieldstatus=pMyBoard.setFieldState(row,col,Player2Symbol);

		if(Fieldstatus==0){
			cout<<"Player "<<Player+1<<"Replay"<<endl;  //Repeat the player turn
		}
		else{
			Player++;
		}
		Player = Player%2; // Alternate between the players
		console.print();

		Gamestatus=pMyBoard.checkIfGameOver();  //If no empty space left on the board, end the game

	} while (Gamestatus!=0);


	/**
	 * Count the score
	 */


	cout<<endl<<"Game Finished"<<endl;
	for(row = 0;row<8;row++){
		for (col=0;col<8;col++){
			if(pMyBoard.getFieldState(row,col)==Player1Symbol)
				Player1score++;
			if(pMyBoard.getFieldState(row,col)==Player2Symbol)
				Player2score++;
		}
	}

	cout<<"Player1 scored(Black coins) "<<Player1score<<" points"<<endl;
	cout<<"Player2 scored(White coins) "<<Player2score<<" points"<<endl;
	if(Player2score==Player1score)
		cout<<"Game Draw.No Winner"<<endl;
	if(Player2score>Player1score)
		cout<<"Player 2 is the Winner"<<endl;
	if(Player1score>Player2score)
		cout<<"Player 1 is the Winner"<<endl;

	return 0;
}
