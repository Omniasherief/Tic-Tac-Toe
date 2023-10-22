#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "STD_TYPES.h"


sint32 main()
{
    sint32 choice;

start:
    system("cls");
	Cyan ();
    printf("\t\t\t Tic-Tac-Toe\n\n");
	reset ();
    printf("\t\t\tChoose game mode:\n");	
    printf("\t\t\t1. Multiplayer\n");
    printf("\t\t\t2. Single player\n");
    printf("\t\t\t3. EXIT\n");

    while (scanf("%d", &choice) == 1)
    {
        if (choice == 1)
        {    Cyan ();
            printf("You chose multiplayer mode.\n");
			 reset ();
            multiplayer();

            sint32 option;
			again:
            printf("\n PLAY AGAIN?\n ENTER 1 FOR YES\n 0 or Other Number FOR NO\n");
         
            if (scanf("%d", &option) != 1)//not vaild
            {    red () ;
                printf("INVALID INPUT\n ");
				 reset ();
                while (getchar() != '\n')
                    ; // Clear input buffer
              
				goto again;
				
            }

            if (option == 1)
            {
			
                goto start;
            }
            else
            {   yellow();
                printf("GOODBYE, See you next time :(\n");
				reset();
                exit(0);
            }
        }
        else if (choice == 2)
        {   Cyan ();
	   
            printf("You chose single player mode.\n");
			here:
			printf("1.EASY\n2.NORMAL\n");
			 reset ();
			sint32 option2;
			
            if (scanf("%d", &option2) != 1)
            {   red () ;
                printf("INVALID INPUT\n");
				reset () ;
                while (getchar() != '\n'); 
				// Clear input buffer
        goto here;
            }
            
            if (option2 == 1)
            {
                singleplayer(YOU);
				while (getchar() != '\n'); 
            }
            else if(option2==2)
            {
                singleplayer(COMPUTER); //computer starts 
				while (getchar() != '\n'); 
            }
			else
			{    red () ;
				printf("\n INVALID INPUT\n ");

				reset () ;
				goto here;
			
			}
            

            sint32 option;
			again2:
            printf("\n PLAY AGAIN?\n ENTER 1 FOR YES\n  0 or Other Number FOR NO\n");

            if (scanf("%d", &option) != 1)
            {   red () ;
                printf("INVALID INPUT\n");
				
				reset () ;
                while (getchar() != '\n'); 
				// Clear input buffer
                goto again2;
            }

            if (option == 1)
            {
                goto start;
            }
            else
            {  yellow ();
                printf("GOODBYE,See you next time:(\n");
				reset ();
                exit(0);
            }
        }
        else if (choice == 3)
        {  yellow ();
            printf("GOODBYE, COME AGAIN :(\n");
			reset ();
            exit(0);
        }
        else
        {    red () ;
            printf("Invalid choice! Try again.\n");
			 reset ();
            printf("\t\t\tChoose game mode:\n");
            printf("\t\t\t1. Multiplayer\n");
            printf("\t\t\t2. Single player\n");
			  printf("\t\t\t3. EXIT\n");
        }
    }
	if((scanf("%d", &choice) != 1))
	{ while (getchar() != '\n') ; 

		goto start;
	}
    return 0;
}
