/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233
Email      : kaknguyen@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int applesNeeded = 0, orangesNeeded = 0, pearsNeeded = 0, tomatoesNeeded = 0, cabbagesNeeded = 0;
    int applesPicked = 0, orangesPicked = 0, pearsPicked = 0, tomatoesPicked = 0, cabbagesPicked = 0;
    printf("Grocery Shopping\n");
    printf("================\n");
    
    do
    {
        printf("How many APPLES do you need? : ");
        scanf("%d",&applesNeeded);
        if (applesNeeded <0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }

    } while (applesNeeded<0);

    printf("\n");
    do
    {
        printf("How many ORANGES do you need? : ");
        scanf("%d",&orangesNeeded);
        if (orangesNeeded <0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }

    } while (orangesNeeded<0);
    
    printf("\n");
    do
    {
        printf("How many PEARS do you need? : ");
        scanf("%d",&pearsNeeded);
        if (pearsNeeded <0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }

    } while (pearsNeeded<0);

    printf("\n");
    do
    {
        printf("How many TOMATOES do you need? : ");
        scanf("%d",&tomatoesNeeded);
        if (tomatoesNeeded <0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }

    } while (tomatoesNeeded<0);

    printf("\n");
    do
    {
        printf("How many CABBAGES do you need? : ");
        scanf("%d",&cabbagesNeeded);
        if (cabbagesNeeded <0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }

    } while (cabbagesNeeded < 0);
    printf("\n");
    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n");
    printf("\n");
    
    do
    {
        printf("Pick some APPLES... how many did you pick? : ");
        scanf("%d",&applesPicked);
        if (applesPicked > applesNeeded)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.\n",applesNeeded);
        }
        else if (applesPicked <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if (applesPicked == applesNeeded)
        {
            printf("Great, that's the apples done!\n");
            break;
        }
        else if (applesPicked < applesNeeded)
        {
            applesNeeded = applesNeeded - applesPicked;
            printf("Looks like we still need some APPLES...\n");
        }
        
    } while (applesNeeded > 0);

    do
    {
        printf("Pick some PEARS... how many did you pick? : ");
        scanf("%d",&pearsPicked);
        if (pearsPicked > pearsNeeded)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.\n",applesNeeded);
        }
        else if (pearsPicked <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if (pearsPicked == pearsNeeded)
        {
            printf("Great, that's the apples done!\n");
            break;
        }
        else if (pearsPicked < pearsNeeded)
        {
            pearsNeeded = pearsNeeded - pearsPicked;
            printf("Looks like we still need some APPLES...\n");
        }
        
    } while (pearsNeeded > 0);

    
    return 0;
}