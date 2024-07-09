/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 1700492333
Email      : kaknguyen@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const int MAX_LENGTH = 70;
const int MIN_LENGTH = 10;
const int DIVIDED_NUM = 5;
struct PlayerInfo
{
    int numOfLives;
    char playerName;
    int numOfTreasures;
    int pastedPositions[70];
};
struct GameInfo
{
    int maxNumOfMoves;
    int numOfPositions;
    int bombsPositions[70];
    int treasuresPositions[70];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c",&player.playerName);
    do
    {
        printf("Set the number of lives: ");
        scanf(" %d",&player.numOfLives);
        if(player.numOfLives < 1 || player.numOfLives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (!(player.numOfLives >= 1 && player.numOfLives <=10));
    
    printf("Player configuration set-up is complete\n\n");
    
    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of %d between 10-70): ",DIVIDED_NUM);
        scanf("%d",&game.numOfPositions);
        if(!(game.numOfPositions % DIVIDED_NUM == 0 && game.numOfPositions >= MIN_LENGTH && game.numOfPositions <= MAX_LENGTH))
        {
            printf("     Must be a multiple of %d and between 10-70!!!\n",DIVIDED_NUM);
        }
    } while (!(game.numOfPositions % DIVIDED_NUM == 0 && game.numOfPositions >= MIN_LENGTH && game.numOfPositions <= MAX_LENGTH));
    
    int minMoves = player.numOfLives;
    int maxMoves = (int)((float)game.numOfPositions*75/100);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d",&game.maxNumOfMoves);
        if(!(game.maxNumOfMoves >= minMoves && game.maxNumOfMoves <= maxMoves))
        {
            printf("    Value must be between %d and %d\n",minMoves,maxMoves);
        }
    } while (!(game.maxNumOfMoves >= minMoves && game.maxNumOfMoves <= maxMoves));
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", DIVIDED_NUM);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.numOfPositions);
    int index = 0;
    int j;
    while(index < game.numOfPositions)
    {
        printf("   Positions [%2d-%2d]: ",index+1,DIVIDED_NUM + index);
        for(j=index;j<DIVIDED_NUM + index;j++)
        {
            scanf("%d",&game.bombsPositions[j]); 
        }
        index+=DIVIDED_NUM;
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", DIVIDED_NUM);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.numOfPositions);
    index = 0;
    while(index < game.numOfPositions)
    {
        printf("   Positions [%2d-%2d]: ",index+1,DIVIDED_NUM + index);
        for(j=index;j<DIVIDED_NUM + index;j++)
        {
            scanf("%d",&game.treasuresPositions[j]); 
        }
        index+=DIVIDED_NUM;
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n",player.playerName);
    printf("   Lives      : %d\n",player.numOfLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n",game.numOfPositions);
    printf("   Bombs      : ");
    for(j=0;j<game.numOfPositions;j++)
    {
        printf("%d",game.bombsPositions[j]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for(j=0;j<game.numOfPositions;j++)
    {
        printf("%d",game.treasuresPositions[j]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    int lastMove = 0;
    int currentMove = 0;
    int i;
    char gamePath[70] = {0};
    if(lastMove == 0)
    {
        printf("\n");
        for(i = 0;i<game.numOfPositions;i++)
        {
            printf("-");
        }
        printf("\n");
    }
    else{
        for(i=0;i<lastMove-1;i++)
        {
            printf(" ");
        }
        printf("%c\n",player.playerName);
    }
    for(i=1;i<=game.numOfPositions;i++)
    {
        if(i%10 == 0)
        {
            printf("%d",i/10);
        }
        else{
            printf("|");
        }
    }
    printf("\n");
    for(i=1;i<=game.numOfPositions;i++)
    {
        printf("%d",i%10);
    }
    printf("+---------------------------------------------------+\n");
    printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d \n",player.numOfLives,player.numOfTreasures,game.maxNumOfMoves);
    printf("+---------------------------------------------------+\n");
    do
    {
        printf("Next Move [1-%d]: ",game.numOfPositions);
        scanf("%d",&currentMove);
        if(!(currentMove > 0 && currentMove <= game.numOfPositions))
        {
            printf("  Out of Range!!!\n");
        }
    } while (!(currentMove > 0 && currentMove <= game.numOfPositions));
    
    //use pastedMove = array 0 and 1
    if(player.pastedPositions[currentMove] == 1)
    {
        printf("===============> Dope! You've been here before!\n");
    }
    else
    {
        if(game.bombsPositions[currentMove] == 1 && game.treasuresPositions[currentMove] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
        }
        else if{
            if(game.bombsPositions[currentMove] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]");
            }
            if(game.treasuresPositions[currentMove] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]");
            }
        }
        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n");
        }
        lastMove = currentMove;
    }

    return 0;
}
