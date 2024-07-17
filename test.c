#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define KG_TO_LBS 2.20462
#define TEST_LBSKG  2.20462
double convertLbsKg(double* pounds, double* result);
double convertLbsG(double* pounds, double* resultToG);
void convertLbs(double* pounds, double* resultToKg , double* resultToG);

int main(void)
{
    double lbs = 150;
	double dblA = 0,dblB = 0.0;
	dblA = convertLbsKg(lbs, NULL);
    dblB = convertLbsG(lbs, NULL);
	printf("%lf %lf\n",dblA,dblB);
    double lbs2 = 200;
    convertLbs(&lbs2,&dblA,&dblB);
    printf("%lf %lf\n",dblA,dblB);
    return 0;
}

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
double convertLbsG(double* pounds, double* resultToG)
{
    double value = convertLbsKg(pounds,NULL)*1000;
    if(resultToG != NULL)
	{
		*resultToG = value; 
	}
    return value;
}

// 10. convert lbs: kg and g
void convertLbs(double* pounds, double* resultToKg , double* resultToG)
{
	convertLbsKg(pounds, resultToKg);
	convertLbsG(pounds,resultToG);
}