/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233
Email      : kaknguyen@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    //only 2 integer variables, 1 char variable

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");

    char inputChar;
    int inputNum;
    while(1)
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d",&inputChar,&inputNum);
        while (getchar() != '\n')
            continue;
        switch (inputChar)
        {
        case 'D':
            if(inputNum <3 || inputNum > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            else
            {
                printf("DO-WHILE: ");
                do  
                {
                    printf("D");
                    inputNum--;
                }
                while(inputNum > 0);
                printf("\n");
            }
            break;
        case 'W':
            if(inputNum <3 || inputNum > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            else
            {
                printf("WHILE: ");
                while(inputNum > 0)
                {
                    printf("W");
                    inputNum--;
                }
                printf("\n");
            }
            break;
        case 'F':
            if(inputNum <3 || inputNum > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            else
            {
                printf("FOR: ");
                for(int i=0;i<inputNum;i++)
                {
                    printf("F");
                }
                printf("\n");
            }
            break;
        case 'Q':
            if (inputNum != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
                break;
        default:
            printf("ERROR: Invalid entered value(s)!\n");
        }
        printf("\n");
        if (inputChar == 'Q' && inputNum == 0)
        {
            break;
        }        
    }

    printf("+----------------------+\n");
    printf("Loop application ENDED\n");
    printf("+----------------------+\n");
    return 0;
}