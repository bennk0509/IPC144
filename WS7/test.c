#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
struct PlayerInfo
{
    int numOfLives;
    char playerName;
    int numOfTreasures;
    int pastedPositions[70];
};

int main(void)
{
    struct PlayerInfo playerTest;
    playerTest.playerName = 'V';
    int lastMove = 0;
    int i;
    if(lastMove == 0)
    {
        printf("\n");
        for(i = 0;i<35;i++)
        {
            printf("-");
        }
    }
    else{
        for(i=0;i<lastMove-1;i++)
        {
            printf(" ");
        }
        printf("%c",playerTest.playerName);
    }
    return 0;
}