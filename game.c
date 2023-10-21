#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include "functions.h"
#include "STD_TYPES.h"


static sint8 player = 'x', opponent = 'o'; 
void Cyan () {
  printf("\033[0;36m");
}
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void Initialise(sint8 board[][SIDE],sint32 moves[])

{
	//empty
	int i,j;
	for(i=0;i<SIDE;i++)
	{
		for(j=0;j<SIDE;j++)
			board[i][j] = ' '; 
	}
	//fill it  with numbers//////////////////////////////////////
	for(i=0;i<9;i++)
	moves[i]=i;
	
	
	
}


void print_board(sint8 board[][SIDE]) 
{ 
 system("cls");
	sint32  i,j;
	printf("\n");
	printf("\t\t\t %c | %c | %c \n", board[0][0], 
           board[0][1], board[0][2]); 
    printf("\t\t\t---+---+--- \n"); 
    printf("\t\t\t %c | %c | %c \n", board[1][0], 
           board[1][1], board[1][2]); 
    printf("\t\t\t---+---+--- \n");  
    printf("\t\t\t %c | %c | %c \n\n", board[2][0], 
           board[2][1], board[2][2]); 
}
void showInstructions() 
{ 
 
    printf("Choose a cell numbered from 1 to 9 as below "
           "and play\n\n"); 
  
    printf("\t\t\t 1  | 2  | 3 \n"); 
    printf("\t\t\t ---+----+---\n");
    printf("\t\t\t 4  | 5  | 6 \n"); 
    printf("\t\t\t ---+----+--- \n"); 
    printf("\t\t\t 7  | 8  | 9 \n\n"); 
  
} 
bool MovesLeft(sint8 board[3][3]) 
{
	int i,j;
	for( i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(board[i][j]==' ')
				return true;
			return false;
}

sint32 CheckXO(sint8 board[3][3]) //evaluate
{
	sint32 row,col;
	//check x, o row
	for(row=0;row<3;row++){
		if((board[row][0]==board[row][1])&&(board[row][1]==board[row][2]))
		{
			if(board[row][0]==player)
				return 10; //max makes me win
			else if(board[row][0]==opponent)
				return -10;
		}
	}
	//check x, o col
	for(col=0;col<3;col++){
		if((board[0][col]==board[1][col])&&(board[1][col]==board[2][col]))
		{
			if(board[0][col]==player)
				return 10; //max makes me win
			else if(board[0][col]==opponent)
				return -10;
		}
	}
	//check x, o diagonal
	if(board[0][0]==board[1][1] &&board[1][1]==board[2][2])
	{
		if(board[0][0]==player)
			return 10;
		else if(board[0][0]==opponent)
			return -10;
	}
	if(board[0][2]==board[1][1] &&board[1][1]==board[2][0])
	{
		if(board[0][0]==player)
			return 10;
		else if(board[0][0]==opponent)
			return -10;
	}
	return 0;//no one win
	
}
sint32 minimax(sint8 board[3][3], sint32 depth, bool maximizingPlayer)
{
    sint32 score = CheckXO(board); // Assuming you have a function to check the game state
    if (score == 10) // maximizer has won
        return score;
    if (score == -10) // minimizer has won
        return score;
    if (MovesLeft(board) == false)
        return 0;

    if (maximizingPlayer)
    {
        sint32 best = -1000;
        for (sint32 i = 0; i < 3; i++)
        {
            for (sint32 j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = player;
                    sint32 val = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    if (val > best)
                        best = val;
                }
            }
        }
        return best;
    }
    else
    {
        sint32 best = 1000;
        for (sint32 i = 0; i < 3; i++)
        {
            for (sint32 j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = opponent;
                    sint32 val = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    if (val < best)
                        best = val;
                }
            }
        }
        return best;
    }
}

move findBestMove(sint8 board[3][3])
{
    sint32 bestVal = -1000;
    move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (sint32 i = 0; i < 3; i++)
    {
        for (sint32 j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                sint32 moveVal = minimax(board, 0, false);
                board[i][j] = ' ';

                if (moveVal > bestVal)
                {
                    bestVal = moveVal;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }

    return bestMove;
}
void Winner(sint32  whoseturn)
{
	
	if(whoseturn==COMPUTER)
		printf("COMPUTER HAS WON");
	if(whoseturn==YOU)
		printf("YOU HAS WON");
	
	
}
sint32 columnCrossed(sint8 board[][SIDE])
{
	
	    for (sint32 i = 0; i < SIDE; i++) { 
        if (board[0][i] == board[1][i] 
            && board[1][i] == board[2][i] 
            && board[0][i] != ' ') 
            return 1; 
    } 
    return 0;
	
	
} 
sint32 diagonalCrossed(sint8 board[][SIDE]) {
	
	
	  if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
        || (board[0][2] == board[1][1] 
            && board[1][1] == board[2][0] 
            && board[0][2] != ' ')) 
        return 1; 
  
    return 0; 
	
	
}
sint32 rowCrossed(sint8 board[][SIDE]) {
	
	    for (sint32 i = 0; i < SIDE; i++) { 
        if (board[i][0] == board[i][1] 
            && board[i][1] == board[i][2] 
            && board[i][0] != ' ') 
            return 1; 
    } 
    return 0;
	
}
sint32 gameover(sint8 board[][SIDE]){
	
	   return (rowCrossed(board) || columnCrossed(board) 
            || diagonalCrossed(board));
	
}
void singleplayer(sint32 whoseturn)
{
    sint8 board[3][3];
    sint32 moves[9];
    Initialise(board, moves);
    showInstructions();
    sint32 moveIndex = 0, x, y;
    while (!gameover(board) && moveIndex != 9)
    {
        if (whoseturn == COMPUTER)
        {
            sint8 tempBoard[3][3];
            for (sint32 i = 0; i < 3; i++)
            {
                for (sint32 j = 0; j < 3; j++)
                {
                    if (board[i][j] == 'X')
                    {
                        tempBoard[i][j] = 'x';
                    }
                    else if (board[i][j] == 'O')
                    {
                        tempBoard[i][j] = 'o';
                    }
                    else
                    {
                        tempBoard[i][j] = ' ';
                    }
                }
            }
            move thisMove = findBestMove(tempBoard);
            x = thisMove.row;
            y = thisMove.col;

            board[x][y] = COMPUTERMOVE;
            printf("COMPUTER has put a %c in cell %d %d\n", COMPUTERMOVE, x, y);
            print_board(board);
            moveIndex++;
            whoseturn = YOU;
        }
        else if (whoseturn == YOU)
        {
            sint32 move;
            printf("Enter your move (1-9): ");
            if (scanf("%d", &move) != 1)
            {
                printf("NOT VALID\n");
                while (getchar() != '\n')
                    ; // Clear input buffer
                continue;
            }
            if (move < 1 || move > 9)
            {
                printf("Invalid input! Please enter a number between 1 and 9.\n");
                continue;
            }
            // calculating index
            x = (move - 1) / 3;
            y = (move - 1) % 3; // col

            if (board[x][y] == ' ')
            {
                board[x][y] = HUMANMOVE;
                print_board(board);
                moveIndex++;
                if (gameover(board))
                {
                    Winner(YOU);
                    return;
                }
                whoseturn = COMPUTER;
            }
            else
            {
                printf("Cell %d is occupied. Try again.\n", move);
            }
        }
    }

    if (!gameover(board) && moveIndex == 9)
	{printf("TIE \n");
	    printf("NO ONE HAS WON :)");
	}
    else
    {
        // Toggling the user
        if (whoseturn == COMPUTER)
            whoseturn = YOU;
        else if (whoseturn == YOU)
            whoseturn = COMPUTER;

        Winner(whoseturn);
    }
}
void multiplayer()
{   sint32 moveIndex=0,x,y;
    sint8 board[3][3];
	sint32 moves[SIDE * SIDE]; 
  
    // Initialise the game 
    Initialise(board, moves); 
  
    // Show the instructions before playing 
    showInstructions(); 

	sint8 player1[15], player2[15];
	 
    printf("Enter Player 1's name: ");
    scanf("%s",player1);
    printf("Enter Player 2's name: ");
     scanf("%s",player2);
  while (!gameover(board) && moveIndex != SIDE * SIDE) 
  { 
        if (moveIndex % 2 == 0) 
		{ 
            printf("\n%s's turn (X)\n", player1);
            sint32 move; 
         
          printf("Enter your move (1-9): "); 
           if (scanf("%d", &move) != 1) 
		   { printf("NOT VAILD\n");
	        while (getchar() != '\n'); // Clear input buffer
                continue;
	   
	       }
		 else{
            if (move < 1 || move > 9) { 
                printf("Invalid input! Please enter a "
                       "number between 1 and 9.\n"); 
                continue; 
            } 
            x = (move - 1) / SIDE; 
            y = (move - 1) % SIDE; 
            if (board[x][y] == ' ') 
			{ 
                board[x][y] = 'X'; 
                print_board(board); 
                moveIndex++; 
                if (gameover(board)) 
				{ 
                   printf("%s has won (X)\n",player1) ; // Player 1 wins
                    return; 
                } 
            } 
              else 
			    { 
                printf("Cell %d is already occupied. Try "
                       "again.", move); 
					   
                } 
          } 
		}
        else 
		{ printf("%s 's turn (O)\n", player2);
            sint32 move; 
          
           printf("Enter your move (1-9): ");
           if (scanf("%d", &move) != 1) 
		   { printf("NOT VALID\n");
	     while (getchar() != '\n'); // Clear input buffer
                continue;
	   
	       }
           else{   
           if (move < 1 || move > 9) {
               printf("Invalid input! Please enter a number between 1 and 9.\n");
               continue;
            }
           x = (move - 1) / SIDE;
           y = (move - 1) % SIDE;
           if (board[x][y] == ' ') {
               board[x][y] = 'O';
               print_board(board);
               moveIndex++;
               if (gameover(board)) {
                   printf("%s has  won (O)\n", player2); // Player 2 wins
                   return;
               }
              //validInput = true; // Set validInput to true to exit the loop
           } else {
               printf("Cell %d is already occupied. Try again.\n", move);
           }
             }
		}
         
  
    
    if (!gameover(board) && moveIndex == 9) 
        printf("TIE\n NO ONE HAS WON :)"); 
  
	
  
   }
}

 
