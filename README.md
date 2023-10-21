# Tic-Tac-Toe

## Features 
Multiplayer mode: Two players play against each other.

Single-player mode: User plays against an implemented smart algorithm that tries to win the game. This mode has two levels:

Normal level: if the program starts first.

Easy level: if the user starts first.
## Inputs
The game should only accept the following inputs:

1- In the beginning the Exist option is option number 3.

2- Input to select between the two modes.

3- Input with the position of where to place your sign on the tic tac toe board using the NUMPAD.
## Algorithm

Single player mode is implemented by using minimax algorithm.

The minimax algorithm is a decision-making algorithm that is commonly used in two-player games. It is a recursive algorithm that considers all possible moves and their outcomes to determine the best move for a player.

In the case of Tic-Tac-Toe, the minimax algorithm works as follows:

1. The algorithm considers all possible moves that the AI player can make.
2. For each possible move, the algorithm simulates the game and determines the outcome of the game assuming both players play optimally.
3. The algorithm assigns a score to each possible move based on the outcome of the game.

The score assigned to each move is determined as follows:

- If the AI player wins, the score is -10.
- If the human player wins, the score is +10.
- If the game is a tie, the score is 0.

The algorithm assumes that both players play optimally, meaning that they will always make the best move available to them.
