/* 
Gabe Volheim
Bgvolhe
ECE 2220
Project 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function declarations
void displayGame(int *, int, int);
bool changeGame(int *, int, int *);
void generateValues(int *);
int checkGame(int *,int *,int *);

int main(void)
{
    int game[4][4],c = 0,flag = 0,score = 0,highscore = 0;
    char c1,c2,c3,userChoice; 

    // Initializing array to zero
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            game[i][j] = 0; 
        }
    }

    // Generates 2 values
    generateValues((int*) game);
    generateValues((int*) game);

    // Intro Message
    printf("Welcome to 2048! This game has 6 total input thats can be done when prompted. They are the following: \n");
    printf("The up arrow key : Which is displayed in the terminal as ^[[A\nThe down arrow key : Which is displayed in the terminal as ^[[B\n");
    printf("The right arrow key : Which is displayed in the terminal as ^[[C\nThe left arrow key: Which is displayed in the terminal as ^[[D\n");
    printf("Either q or Q to quit the game\n");
    printf("Note: After each key is pressed, Enter will also have to be pressed in order for the program to recieve input. For the case of q, enter will have to be pressed 3 times\n");
    printf("This is the last time this message will be displayed, Enjoy playing!\n");
    // Repeats until user quits
    do{

    // Displays the board each turn
    displayGame((int *)game,score,highscore);

        flag = 0;
        // Getting user input
        printf("Please input the intended move: ");
        scanf("%c%c%c",&c1, &c2, &c3); // User will always have to put in 3 inputs
        while ((c = getchar()) != '\n' && c != EOF) {} // Eats Whitespace
        if(c1 == 'q' || c1 == 'Q')
        {
            printf("Exiting now, thank you for playing!\n");
            return 0;
        }
        // Checking to make sure that user inputs proper value
        if(c1 != 27) flag = 1;
        if(c2 != 91) flag = 1;
        if(c3 != 'A' && c3 != 'B' && c3 != 'C' && c3 != 'D') flag = 1;

        while(flag)
        {
            flag = 0;
            printf("Error invalid input\n");
            scanf("%c%c%c",&c1, &c2, &c3); 
            while ((c = getchar()) != '\n' && c != EOF) {} 
            if(c3 != 'A' && c3 != 'B' && c3 != 'C' && c3 != 'D') flag = 1;
            if(c1 != 27) flag = 1;
            if(c2 != 91) flag = 1;
        }

    // Changing the board and also generating new values if the input was true
    if(changeGame((int *)game, c3, &score) == true) generateValues((int*)game);
    // Checking if user can still make a move
    if(checkGame((int *)game, &score, &highscore) == 0)
    {
        displayGame((int *)game,score,highscore);
        printf("You won!\n");
        printf("Do you wish to play again? Yes or No: ");
        userChoice = getchar();
        while ((c = getchar()) != '\n' && c != EOF) {}
        if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N' ) flag = 1;

        // Running if user did not input correct response
        while (flag)
        {
            flag = 0;
            printf("Error invalid input. Please input your choice, either Yes or No: \n");
            userChoice = getchar();
            while ((c = getchar()) != '\n' && c != EOF) {}
            if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N' ) flag = 1;
        }

        // Will quit if user does not want to continue
        if (userChoice == 'N' || userChoice == 'n')
        {
            printf("Exiting now, Thanks for playing! \n");
            return 0;
        }
        else // Resets board and makes two new values
        {
            score = 0;
            printf("Okay, making a new board.\n");
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    game[i][j] = 0; 
                }
            }
            generateValues((int*) game);
            generateValues((int*) game);
        }
        
    }

    else if((checkGame((int *)game, &score, &highscore) == 1))
    {
        displayGame((int *)game,score,highscore);
        printf("You Lost!\n");
        printf("Do you wish to play again? Yes or No: ");
        userChoice = getchar();
        while ((c = getchar()) != '\n' && c != EOF) {}
        if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N' ) flag = 1;

        // Running if user did not input correct response
        while (flag)
        {
            flag = 0;
            printf("Error invalid input. Please input your choice, either Yes or No: ");
            userChoice = getchar();
            while ((c = getchar()) != '\n' && c != EOF) {}
            if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N' ) flag = 1;
        }
         // Will quit if user does not want to continue
        if (userChoice == 'N' || userChoice == 'n')
        {
            printf("Exiting now, Thanks for playing! \n");
            return 0;
        }
        else // Resets board and makes two new values
        {
            score = 0;
            printf("Okay, making a new board.\n");
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    game[i][j] = 0; 
                }
            }
            generateValues((int*) game);
            generateValues((int*) game);
        }
    }
    }while(c1 != 'Q' || c1 != 'q');

    return 0;
}


// Function that displays the user input based off of input
void displayGame(int *game, int score, int highscore)
{
    printf("*** Score = %d, High Score = %d *** \n",score,highscore);
    printf("-----------------------------\n");
    printf("| %4.0d | %4.0d | %4.0d | %4.0d |\n",*((game+0*4)+0),*((game+0*4)+1),*((game+0*4)+2),*((game+0*4)+3));
    printf("-----------------------------\n");
    printf("| %4.0d | %4.0d | %4.0d | %4.0d |\n",*((game+1*4)+0),*((game+1*4)+1),*((game+1*4)+2),*((game+1*4)+3));
    printf("-----------------------------\n");
    printf("| %4.0d | %4.0d | %4.0d | %4.0d |\n",*((game+2*4)+0),*((game+2*4)+1),*((game+2*4)+2),*((game+2*4)+3));
    printf("-----------------------------\n");
    printf("| %4.0d | %4.0d | %4.0d | %4.0d |\n",*((game+3*4)+0),*((game+3*4)+1),*((game+3*4)+2),*((game+3*4)+3));
    printf("-----------------------------\n");
    return;
}

// Function that generates random values and intserts them into the board
void generateValues(int *game)
{
    int number[10] = {2,2,2,2,2,2,2,2,2,4};
    int num = 0;
    int i = 0,k = 0;
    int flag;
    srand(time(NULL));
    do
    {
        flag = 0;
        num = number[rand() % 10 ];
        i = rand() % 4;
        k = rand() % 4;
        if(*((game + i * 4) + k) == 0)
        {
            *((game + i * 4) + k) = num;
        }
        else
        {
            flag = 1;
        }
    }while(flag == 1);
}

// Function that takes user input and manipulates the board
bool changeGame(int *game, int move, int *score)
{
    int change = 0;
    switch(move)
    {
        case('A'):
            for(int i = 0;i < 4;i++)
            {
                for(int j = 0;j < 4;j++)
                {
                    for(int k = i+1; k < 4; k++)
                    {
                       if(*((game + (k) * 4) + j) != 0)
                       {
                           if(*((game + (k) * 4) + j) == *((game + (i) * 4) + j))
                           {
                               *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                               *((game + (k) * 4) + j) = 0;
                               *score = *score + *((game + (i) * 4) + j);
                               change = 1;
                               break;
                           }
                           else if(*((game + (i) * 4) + j) == 0)
                           {
                            *((game + (i) * 4) + j) = *((game + (k) * 4) + j);
                            *((game + (k) * 4) + j) = 0;
                            for(int l = k; l < 4;l++)
                            {
                                if(*((game + (l) * 4) + j) != 0)
                                {
                                    if(*((game + (l) * 4) + j) == *((game + (i) * 4) + j))
                                    {
                                        *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                                        *((game + (l) * 4) + j) = 0;
                                        *score = *score + *((game + (i) * 4) + j);
                                        break;
                                    }
                                    else break;
                                }
        
                            }
                            change = 1;
                              break;
                           }
                           else break;
                       }
                    }
                }
            }
        break;

        case('B'):
        for(int i = 3;i > -1;i--)
            {
                for(int j = 3;j > -1;j--)
                {
                    for(int k = i-1; k > -1; k--)
                    {
                       if(*((game + (k) * 4) + j) != 0)
                       {
                            if(*((game + (k) * 4) + j) == *((game + (i) * 4) + j))
                           {
                               *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                               *((game + (k) * 4) + j) = 0;
                               change = 1;
                               *score = *score + *((game + (i) * 4) + j);
                               break;
                           }
                           else if(*((game + (i) * 4) + j) == 0)
                           {
                              *((game + (i) * 4) + j) = *((game + (k) * 4) + j);
                              *((game + (k) * 4) + j) = 0;
                              for(int l = k; l > -1;l--)
                            {
                                if(*((game + (l) * 4) + j) != 0)
                                {
                                    if(*((game + (l) * 4) + j) == *((game + (i) * 4) + j))
                                    {
                                        *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                                        *((game + (l) * 4) + j) = 0;
                                        *score = *score + *((game + (i) * 4) + j);
                                        break;
                                    }
                                    else break;
                                }
                            }
                              change = 1;
                              break;
                           }
                        else break;
                       }
                    }
                }
            }
        break;
        case('C'):
        for(int i = 3;i > -1;i--)
            {
                for(int j = 3;j > -1;j--)
                {
                    for(int k = j-1; k > -1; k--)
                    {
                       if(*((game + (i) * 4) + k) != 0)
                       {
                            if(*((game + (i) * 4) + k) == *((game + (i) * 4) + j))
                           {
                               *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                               *((game + (i) * 4) + k) = 0;
                               *score = *score + *((game + (i) * 4) + j);
                               change = 1;
                               break;
                           }
                           else if(*((game + (i) * 4) + j) == 0)
                           {
                              *((game + (i) * 4) + j) = *((game + (i) * 4) + k);
                              *((game + (i) * 4) + k) = 0;
                              for(int l = k; l > -1;l--)
                            {
                                if(*((game + (i) * 4) + l) != 0)
                                {
                                    if(*((game + (i) * 4) + l) == *((game + (i) * 4) + j))
                                    {
                                        *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                                        *((game + (i) * 4) + l) = 0;
                                        *score = *score + *((game + (i) * 4) + j);
                                        break;
                                    }
                                    else break;
                                }
                            }
                            change = 1;
                            break;
                           }
                        else break;
                       }
                    }
                }
            }
        break;

        case('D'):
        {
            for(int i = 0;i < 4;i++)
            {
                for(int j = 0;j < 4;j++)
                {
                    for(int k = j+1; k < 4; k++)
                    {
                       if(*((game + (i) * 4) + k) != 0)
                       {
                           if(*((game + (i) * 4) + k) == *((game + (i) * 4) + j))
                           {
                               *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                               *((game + (i) * 4) + k) = 0;
                               *score = *score + *((game + (i) * 4) + j);
                               change = 1;
                               break;
                           }
                           else if(*((game + (i) * 4) + j) == 0)
                           {
                            *((game + (i) * 4) + j) = *((game + (i) * 4) + k);
                            *((game + (i) * 4) + k) = 0;
                            for(int l = k; l < 4;l++)
                            {
                                if(*((game + (i) * 4) + l) != 0)
                                {
                                    if(*((game + (i) * 4) + l) == *((game + (i) * 4) + j))
                                    {
                                        *((game + (i) * 4) + j) = *((game + (i) * 4) + j)*2;
                                        *((game + (i) * 4) + l) = 0;
                                        *score = *score + *((game + (i) * 4) + j);
                                        break;
                                    }
                                    else break;
                                }
        
                            }
                            change = 1;
                              break;
                           }
                           else break;
                       }
                    }
                }
            }
        }
    }
    if (change == 0) return false;
    else return true;
}

// Function that checks if user can still make a move, has won, or has lost, and also calculates the highscore
int checkGame(int *game, int *score, int *highscore)
{
    for (int i = 0; i < 4; i++ )
    {
        for (int j = 0;j < 4; j++)
        {
            if(*((game + i * 4) + j) == 2048) 
            {
                if(*score > *highscore)
                {
                    *highscore = *score;
                }
                return 0;
            }
        } 
    }
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            // Checking to see if user can still make a move
            if(i != 3)
            {
                if( *((game + (i+1) * 4) + j) == *((game + (i) * 4) + j) || *((game + (i+1) * 4) + j) == 0)
                {
                    if(*score > *highscore)
                    {
                        *highscore = *score;
                    }
                    return 2;
                    
                }
            }
            if(j != 3)
            {
                if( *((game + (i) * 4) + j) == *((game + (i) * 4) + (j+1)) || *((game + (i) * 4) + (j+1)) == 0)
                {
                    if(*score > *highscore)
                    {
                        *highscore = *score;
                    }
                    return 2;
                }
                if (*((game + (i) * 4) + j) == 0)
                {
                    if(*score > *highscore)
                    {
                        *highscore = *score;
                    }
                    return 2;
                }
            }
        }
    }
    
    if(*score > *highscore)
    {
        *highscore = *score;
    }
    return 1;
}
