# Reversi Board
Implement a board for playing [Reversi](https://en.wikipedia.org/wiki/Reversi)

Write a class ReversiBoard that represents the state of the board, i.e. which fields are empty, occupied with a piece with player 1’s color up or occupied with player 2’s color up. Use an enumeration to represent the fields' states.
The board class must provide a method for querying any field’s state and a method for setting a field’s state, i.e. putting a new piece on the board. This latter method must check that the move is valid (the piece may be put at the given location) and update the state of the board ("turn over" other pieces as required by the rules).

Write a second class ReversiConsoleView that prints the board on the console. The class receives a pointer to an instance of ReversiBoard as parameter of its constructor. In its print() method, it uses the pointer to obtain the states of the fields and creates the appropriate output.

In the main function, implement a small loop that queries the user where to put the next piece, invokes the method to put the piece on the board and prints the board’s new state.

