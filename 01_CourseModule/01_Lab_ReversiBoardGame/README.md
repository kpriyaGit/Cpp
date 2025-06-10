# Reversi Board
Implementation of a board for playing [Reversi](https://en.wikipedia.org/wiki/Reversi) using the Model-View-Control programming design pattern

## Model

Class ReversiBoard represents the state of the board, i.e. which fields are empty, occupied with a piece with player 1’s color up or occupied with player 2’s color up. 
The board class provides a method for querying any field’s state and a method for setting a field’s state, i.e. putting a new piece on the board. This latter method checks that the move is valid (the piece may be put at the given location) and updates the state of the board ("turn over" other pieces as required by the rules).

## View

A second class ReversiConsoleView prints the board on the console. The class receives a pointer to an instance of ReversiBoard as parameter of its constructor. In its print() method, it uses the pointer to obtain the states of the fields and creates the appropriate output.

## Control

In the main function, a small loop is implemented that queries the user where to put the next piece, invokes the method to put the piece on the board and prints the board’s new state.

