/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233
Email      : kaknguyen@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	const float minIncome = 500.00;
	const float maxIncome = 400000.00;
	double monthNetIncome = 0;
	int numOfItems = 0;
	int i;
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	printf("\n");

	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf",&monthNetIncome);
		if (monthNetIncome < minIncome)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		else if(monthNetIncome > maxIncome)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}
		printf("\n");

	} while (!(monthNetIncome >= 500 && monthNetIncome < 400000));
	
	do
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d",&numOfItems);
		if (numOfItems < 1 || numOfItems > 10)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}

	} while (!(numOfItems >= 1 && numOfItems <= 10));
	
	printf("\n");	
	double listCostOfItems[numOfItems];
	int listOfPriority[numOfItems];
	char listOfFinancedOptions[numOfItems];
	double totalCost = 0;
    double totalPriorityItems[3] = {0,0,0};
	int finanOptionPriority[3] = {0,0,0};
	int totalPriorityOption = 0;
	for(i=0;i<numOfItems;i++)
	{
		printf("Item-%d Details:\n",i+1);
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
			if (listOfFinancedOptions[i] != 'y' && listOfFinancedOptions[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
 		} while (listOfFinancedOptions[i] != 'y' && listOfFinancedOptions[i] != 'n');

		if (listOfPriority[i] == 1 && listOfFinancedOptions[i] == 'y')
        {
            finanOptionPriority[0] = 1; 
        }
        else if (listOfPriority[i] == 2 && listOfFinancedOptions[i] == 'y')
        {
            finanOptionPriority[1] = 1; 
        }
        else if (listOfPriority[i] == 3 && listOfFinancedOptions[i] == 'y')
        {
            finanOptionPriority[2] = 1; 
        }

		printf("\n");	
		totalCost+=listCostOfItems[i];
        totalPriorityItems[listOfPriority[i]-1] += listCostOfItems[i];
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i=0;i<numOfItems;i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n",i+1,listOfPriority[i],listOfFinancedOptions[i],listCostOfItems[i]);
		
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n",totalCost);
	
    totalPriorityOption = finanOptionPriority[0] + finanOptionPriority[1] + finanOptionPriority[2];
	int menuExit = 1;
    while(menuExit)
    {
        int selection;
		int month;
        printf("How do you want to forecast your wish list?\n");
        printf("1. All items (no filter)\n");
        printf("2. By priority\n");
        printf("0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d",&selection);
        printf("\n");
        if (selection == 1)
        {   
            month = (int)totalCost/monthNetIncome+1;
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n",totalCost);
            printf("Forecast: %d years, %d months\n",month/12,month%12);
			if (totalPriorityOption != 0)
			{
				printf("NOTE: Financing options are available on some items.\n");
            	printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
            printf("\n");
        }
        else if(selection == 2)
        {
			int priorSelection;
			do
			{
            	printf("What priority do you want to filter by? [1-3]: ");
            	scanf("%d",&priorSelection);
			} while (priorSelection < 1 || priorSelection > 3);
			printf("\n");
			switch (priorSelection)
			{
			case 1:
				month = (int)totalPriorityItems[0]/monthNetIncome+1;
				printf("====================================================\n");
				printf("Filter:   by priority (1)\n");
				printf("Amount:   $%.2lf\n",totalPriorityItems[0]);
				printf("Forecast: %d years, %d months\n",month/12,month%12);
				if (finanOptionPriority[0] == 1)
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");
	
				break;
			case 2:
				month = (int)totalPriorityItems[1]/monthNetIncome+1;
				printf("====================================================\n");
				printf("Filter:   by priority (2)\n");
				printf("Amount:   $%.2lf\n",totalPriorityItems[1]);
				printf("Forecast: %d years, %d months\n",month/12,month%12);
				if (finanOptionPriority[1] == 1)
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");
				break;
			case 3:
				month = (int)totalPriorityItems[2]/monthNetIncome+1;
				printf("====================================================\n");
				printf("Filter:   by priority (1)\n");
				printf("Amount:   $%.2lf\n",totalPriorityItems[2]);
				printf("Forecast: %d years, %d months\n",month/12,month%12);
				if (finanOptionPriority[2] == 1)
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
				}
				printf("====================================================\n");
				break;
			default:
				break;
			}
			printf("\n");
        }
        else if(selection == 0)
        {
            menuExit = 0;
        }
		else
		{
			printf("ERROR: Invalid menu selection.\n");
			printf("\n");
		}
    }
    
    printf("Best of luck in all your future endeavours!\n");

    return 0;


}