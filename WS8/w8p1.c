/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233 
Email      : kaknguyen@myseneca.ca
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include "stdio.h"
#include "stdlib.h"
// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptr)
{
	int value;
	do
	{
		scanf("%d",&value);
		if(value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);

	if(ptr != NULL)
	{
		*ptr = value; 
	}
	return value;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptr)
{
	double value;
	do
	{
		scanf("%lf",&value);
		if(value <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (value <= 0.0);

	if(ptr != NULL)
	{
		*ptr = value; 
	}
	return value;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(int maxProduct, int numGram)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n",maxProduct);
	printf("NOTE: A 'serving' is %dg\n",numGram);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int iterator)
{
	struct CatFoodInfo product;
	printf("Cat Food Product #%d\n",iterator);
	printf("--------------------\n");
	printf("SKU           : ");
	//scanf("%d",&product.sku);
	product.sku = getIntPositive(&product.sku);
	printf("PRICE         : $");
	//scanf("%lf",&product.price);
	product.price = getDoublePositive(&product.price);
	printf("WEIGHT (LBS)  : ");
	//scanf("%lf",&product.weight);
	product.weight = getDoublePositive(&product.weight);
	printf("CALORIES/SERV.: ");
	//scanf("%d",&product.caloriesPerServing);
	product.caloriesPerServing = getIntPositive(&product.caloriesPerServing);
	return product;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int numOfProduct, struct CatFoodInfo *product)
{
	int i;
	for(i=0;i<numOfProduct;i++)
	{
		printf("%.7d      %.2lf    %7.1lf      %d\n",product[i].sku,product[i].price,product[i].weight,product[i].caloriesPerServing);
	}
}

// 7. Logic entry point
void start()
{
	struct CatFoodInfo *listProduct =  (struct CatFoodInfo*)malloc(MAX_PRODUCT*sizeof(struct CatFoodInfo));
	int i;
	openingMessage(MAX_PRODUCT,NUM_GAMS);
	printf("\n");
	for(i=0;i<MAX_PRODUCT;i++)
	{
		listProduct[i] = getCatFoodInfo(i+1);
		printf("\n");
	}
	displayCatFoodHeader();
	displayCatFoodData(MAX_PRODUCT,listProduct);
	free(listProduct);
}