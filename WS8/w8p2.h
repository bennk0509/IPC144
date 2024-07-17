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


// ----------------------------------------------------------------------------
// defines/macros
#ifndef W8P2_H
#define W8P2_H

#define MAX_PRODUCT 3
#define NUM_GAMS 64
#define KG_TO_LBS 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int caloriesPerServing;
    double weight;
};

struct ReportData
{
    struct CatFoodInfo product;
    double weightInKg;
    int weightInG;
    double totalServing;
    double costPerServing;
    double costCaloriesPerServing;

};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* ptr);
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* ptr);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(int maxProduct, int numGram);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo();

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData();

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(double* pounds, double* resultToKg);

// 9. convert lbs: g
int convertLbsG(double *lbs, int *grams);

// 10. convert lbs: kg / g
void convertLbs(double* pounds, double* resultToKg , int* resultToG);

// 11. calculate: servings based on gPerServ
double calculateServings(double servingSizeG, double totalGam, double* result);

// 12. calculate: cost per serving
double calculateCostPerServing(double *productPrice, double *totalServing, double*result);

// 13. calculate: cost per calorie
double calculateCostPerCal(double *productPrice, double * totalServing, int* CaloriesPerServing, double *result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData();

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(int numOfProduct, struct ReportData *report, int cheapestIndex);

// 17. Display the findings (cheapest)
void displayFinalAnalysis();

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();

#endif