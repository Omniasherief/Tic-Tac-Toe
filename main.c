#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "STD_TYPES.h"
sint32 main()
{
    sint32 choice;

start:
    system("cls");
    printf("\t\t\t Tic-Tac-Toe\n\n");
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
			
            printf("\n PLAY AGAIN?\n ENTER 1 FOR YES, 0 FOR NO\n");
         
            if (scanf("%d", &option) != 1)
            {    red () ;
                printf("INVALID INPUT\n");
				 reset ();
                while (getchar() != '\n')
                    ; // Clear input buffer
                continue;
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
			printf("1.EASY\n2.NORMAL");
			 reset ();
			sint32 option2;
            if (scanf("%d", &option2) != 1)
            {   red () ;
                printf("INVALID INPUT\n");
				reset () ;
                while (getchar() != '\n'); 
				// Clear input buffer
                continue;
            }

            if (option2 == 1)
            {
                singleplayer(YOU);
            }
            else
            {
                singleplayer(COMPUTER); //computer starts 
            }
            

            sint32 option;
            printf("\n PLAY AGAIN?\n ENTER 1 FOR YES, 0 FOR NO\n");

            if (scanf("%d", &option) != 1)
            {   red () ;
                printf("INVALID INPUT\n");
				reset () ;
                while (getchar() != '\n'); 
				// Clear input buffer
                continue;
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
        {
            printf("Invalid choice! Try again.\n");
            printf("\t\t\tChoose game mode:\n");
            printf("\t\t\t1. Multiplayer\n");
            printf("\t\t\t2. Single player\n");
	    printf("\t\t\t3. EXIT\n");

        }
    }
	if((scanf("%d", &choice) != 1))
		goto start;

    return 0;
}
