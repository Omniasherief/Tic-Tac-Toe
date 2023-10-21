#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define COMPUTER 1 
#define 	YOU 2 
#define SIDE 3 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X'
#include<stdbool.h>
#include "STD_TYPES.h"
typedef struct
{
	int row,col;
	
}move;
void Initialise(sint8 board[][SIDE],sint32 moves[]);
void showInstructions() ;
void print_board(sint8 board[][SIDE]) ;
bool MovesLeft(sint8 board[3][3]); // check if the play is end or there are another places 
sint32 CheckXO(sint8 board[3][3]); //check the winner 
sint32 minimax(sint8 board[3][3], sint32 depth,bool max);// ALG , possible ways the game  returns 
move findBestMove(sint8 board[3][3]) ;// return the best possible move for the player
void Winner(sint32 whoseturn);
sint32 columnCrossed(sint8 board[][SIDE]) ;
sint32 diagonalCrossed(sint8 board[][SIDE]) ;
sint32 rowCrossed(sint8 board[][SIDE]) ; // last three function used later to check game over or not
sint32 gameover(sint8 board[][SIDE]);
void singleplayer(sint32 whoseturn);
void multiplayer();
void Cyan ();
void yellow ();
void reset ();
void red () ;

#endif