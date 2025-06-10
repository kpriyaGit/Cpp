/*
 * ReversiBoard.h
 *
 *  Created on: 07-Nov-2021
 *      Author: kpriya
 */

#include <vector>

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/*
 * Class that denotes the Board of game Reversi
 */
class ReversiBoard
{
private:
	/*
	 * Member variable rowSize that denotes number of rows of the Reversi game which is 8 in this game
	 */
	unsigned short rowSize;
	/*
	 * Member variable colSize that denotes number of columns of the Reversi game which is 8 in this game
	 */
	unsigned short colSize;
	/*
	 * Member variable pcontent that denotes the coin that is placed in every position on the board.
	 */
	unsigned char* pcontent;

public:
	/**
	 * Default constructor
	 */
	ReversiBoard();
	/**
	 * Parameterised constructor
	 * @params: Row size  of the board
	 *          Column size of the board
	 */
	ReversiBoard(unsigned short rowSize,unsigned short colSize,unsigned char Player1Symbol, unsigned char Player2Symbol);
	/**
	 * Destructor
	 */
	~ReversiBoard();
	/**
	 * Member function for converting the given position on the board to an index for the array of contents
	 * @params: row and column for which index is to be calculated
	 */
	short calcIndex(unsigned short row, unsigned short col);
	/**
	 * Member function to get which coin is placed at a given position of the board
	 * @params: row and column
	 * @returns : The coin type (black(x) or white(o)
	 */
	char getFieldState(unsigned short row, unsigned short col);
	/**
	 * Method for setting the coin by the player during the game.
	 * @params: row number, column number and coin
	 * @returns: True if coin was properly placed and flips were performed successfully
	 * 			 False if wrong inputs were provided by the Player
	 */
	bool setFieldState(unsigned short row, unsigned short col, unsigned char coin);
	/**
	 * Method for checking if the position for placing coin is a valid move or not
	 *  @params: row number, column number
	 *           reference to a vector to store all possible indices that can be turned over in case of a possible move
	 *  @returns : True if requested Move is valid
	 *  		   False if coin cannot be placed at the requested position
	 */
	short checkMoveValidity(unsigned short row, unsigned short col, unsigned char coin, std::vector<int> &flippableindices);
	/**
	 * Member function for flipping the coins in case of a Valid move
	 * @params : reference to a vector to store all possible indices that can be turned over
	 * 			 coin that wins and replaces the opposite player's coins
	 * @returns: True if all ok
	 * 		   : False in case turning of opponents coins not possible
	 * 		   : -1 in case spot is already occupied
   	 */
	bool flipCoin(std::vector<int> &flippableindices,char coin);

	/**
	 * Method to check if all the empty rows and columns of the board are filled
	 * @returns : True if no free spaces left
	 * 			: False if there are still empty slots
	 */
	bool checkIfGameOver();

};


#endif /* REVERSIBOARD_H_ */
