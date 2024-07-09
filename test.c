#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    if(checkBomb == 1)
    {
        gamePath = '!';
    }
    else if (checkTreasure == 1)
    {
        gamePath == '$';
    }
    else if (checkBothBombTreasure == 1)
    {
        gamePath == '&';
    }
    else
    {
        gamePath == '.';
    }
    return 0;
}

// #include <stdio.h>

// int main(void)
// {
//     int minutes;
//     char s;

//     printf("How many minutes left ? ");
//     scanf("%d", &minutes);

//     s = minutes > 1 ? 's' : ' ';    // Conditional Expression

//     printf("%d minute%c left\n", minutes, s);

//     return 0;
// }