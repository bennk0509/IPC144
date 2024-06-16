/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233
Email      : kaknguyen
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define limit 10 


int main(void)
{
	const float minIncome = 500.00;
	const float maxIncome = 400000.00;
	float monthNetIncome = 0;
	int numOfItems = 0;
	int i;
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	printf("\n");

	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%f",&monthNetIncome);
		if (monthNetIncome < 500)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		else if(monthNetIncome > 400000)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}

	} while (!(monthNetIncome >= 500 && monthNetIncome < 400000));
	printf("\n");
	do
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d",&numOfItems);
		if (numOfItems < 1 || numOfItems > 10)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}

	} while (!(numOfItems >= 1 && numOfItems <= 10));
	
	double listCostOfItems[numOfItems];
	int listOfPriority[numOfItems];
	char listOfFinancedOptions[numOfItems];
	double totalCost = 0;
	for(i=0;i<numOfItems;i++)
	{
		printf("Item-%d Details\n",i);
		do
		{
			printf("   Item cost: $");
			scanf("%lf",&listCostOfItems[i]);
			if (listCostOfItems[i] < 100)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (listCostOfItems[i] < 100);
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d",&listOfPriority[i]);
			if (listOfPriority[i] < 1 || listOfPriority[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (listOfPriority[i] < 1 || listOfPriority[i] > 3);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c",&listOfFinancedOptions[i]);
			printf("%c",listOfFinancedOptions[i]);
			if (listOfFinancedOptions[i] != 'y' || listOfFinancedOptions[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
 		} while (listOfFinancedOptions[i] != 'y' || listOfFinancedOptions[i] != 'n');
		
		totalCost+=listCostOfItems[i];
	}

	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i=0;i<numOfItems;i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n",i+1,listOfPriority[i],listOfFinancedOptions[i],listCostOfItems[i]);
		
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n",totalCost);
	printf("Best of luck in all your future endeavours!\n");
    return 0;
}

/*
    HELPER: printf formatting statements....
	=========================================
	
    Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");
		
		printf("%3d  %5d    %5c    %11.2lf\n", ...
		

	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/