/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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
#include "w8p2.h"
// ----------------------------------------------------------------------------
// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double* pounds, double* result)
{
    double value = *pounds / KG_TO_LBS;
    if(result != NULL)
	{
		*result = value; 
	}
    return value;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(double *lbs, int *grams) {

    int result = (int)(*lbs * 453.592);

    if (grams != NULL) {
        *grams = result;
    }

    return result;
}

// 10. convert lbs: kg and g
void convertLbs(double* pounds, double* resultToKg , int* resultToG)
{
	convertLbsKg(pounds, resultToKg);
	convertLbsG(pounds,resultToG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(double servingSizeG, double totalGam, double* result)
{
	double value = servingSizeG/totalGam;
	if(result != NULL)
		*result = value;
	return value;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double *productPrice, double *totalServing, double* result)
{
	double value = *productPrice / *totalServing;
	if(result != NULL)
	{
		*result = value;
	}
	return value;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double *productPrice, double * totalServing, int* CaloriesPerServing, double *result)
{
	double totalCalories = * totalServing** CaloriesPerServing;
	double value = *productPrice / totalCalories;
	if(result != NULL)
	{
		*result = value;
	}
	return value;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo product)
{
	struct ReportData report;
	report.product = product;
	convertLbs(&product.weight, &report.weightInKg, &report.weightInG);
    report.totalServing = calculateServings(report.weightInG,NUM_GAMS,NULL);
	report.costPerServing = calculateCostPerServing(&product.price,&report.totalServing,NULL);
    report.costCaloriesPerServing = calculateCostPerCal(&product.price,&report.totalServing,&report.product.caloriesPerServing,NULL);
	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_GAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(int numOfProduct, struct ReportData *report, int cheapestIndex) {
    for (int i = 0; i < numOfProduct; i++) {
        printf("%07d   %8.2lf %10.4lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf %s\n", 
            report[i].product.sku, 
            report[i].product.price, 
            report[i].product.weight, 
            report[i].weightInKg, 
            report[i].weightInG, 
            report[i].product.caloriesPerServing, 
            report[i].totalServing, 
            report[i].costPerServing, 
            report[i].costCaloriesPerServing,
			(i == cheapestIndex) ? "***" : "");
    }
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo *product,int cheapestIndex) {

    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n", 
        product[cheapestIndex].sku, 
        product[cheapestIndex].price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start()
{
	struct CatFoodInfo *listProduct =  (struct CatFoodInfo*)malloc(MAX_PRODUCT*sizeof(struct CatFoodInfo));
	struct ReportData *listReport =  (struct ReportData*)malloc(MAX_PRODUCT*sizeof(struct ReportData));
	int i;
	openingMessage(MAX_PRODUCT,NUM_GAMS);
	printf("\n");
	int indexCheapest = 0;
	for(i=0;i<MAX_PRODUCT;i++)
	{
		listProduct[i] = getCatFoodInfo(i+1);
		printf("\n");
		listReport[i] = calculateReportData(listProduct[i]);
		if(listReport[i].costPerServing < listReport[indexCheapest].costPerServing)
		{
			indexCheapest = i;
		}
	}
	displayCatFoodHeader();
	displayCatFoodData(MAX_PRODUCT,listProduct);
	printf("\n");
	displayReportHeader();
	displayReportData(MAX_PRODUCT,listReport,indexCheapest);
	printf("\n");
	displayFinalAnalysis(listProduct,indexCheapest);
	printf("\nHappy shopping!\n");
	free(listProduct);
	free(listReport);
}
