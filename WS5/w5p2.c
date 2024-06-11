/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define LOG_DAYS 3

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year = 0;
    int month = 0;
    int i = 0;
    char d = " ";
    float morning_rate_total = 0, evening_rate_total = 0;
    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d",&year,&month);
        if (year<MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while(!(year >= 2012 && year <= 2022 && month >= JAN && month <= DEC));
    
    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");

    for(i=0;i<LOG_DAYS;i++)
    {
        float morning_rate = 0, evening_rate = 0;
        switch (month)
        {
        case 1:
            printf("Log starting date: %d-JAN-%02d\n",year,i+1);
            break;
        case 2:
            printf("Log starting date: %d-FEB-%02d\n",year,i+1);
            break;
        case 3:
            printf("Log starting date: %d-MAR-%02d\n",year,i+1);
            break;
        case 4:
            printf("Log starting date: %d-APR-%02d\n",year,i+1);
            break;
        case 5:
            printf("Log starting date: %d-MAY-%02d\n",year,i+1);
            break;
        case 6:
            printf("Log starting date: %d-JUN-%02d\n",year,i+1);
            break;
        case 7:
            printf("Log starting date: %d-JUL-%02d\n",year,i+1);
            break;
        case 8:
            printf("Log starting date: %d-AUG-%02d\n",year,i+1);
            break;
        case 9:
            printf("Log starting date: %d-SEP-%02d\n",year,i+1);
            break;
        case 10:
            printf("Log starting date: %d-OCT-%02d\n",year,i+1);
            break;
        case 11:
            printf("Log starting date: %d-NOV-%02d\n",year,i+1);
            break;
        case 12:
            printf("Log starting date: %d-DEC-%02d\n",year,i+1);
            break;
        default:
            break;
        }
        do
        {
            printf("Morning rating (0.0-5.0): ");
            scanf("%f",&morning_rate);
            if (morning_rate <0 || morning_rate > 5)
            {
                printf("ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }        
        } while (!(morning_rate>=0 && morning_rate <= 5));

        do
        {
            printf("Evening rating (0.0-5.0): ");
            scanf("%f",&evening_rate);
            if (evening_rate <0 || evening_rate > 5)
            {
                printf("ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (!(evening_rate >= 0 && evening_rate <= 5));
        
        printf("\n");
        morning_rate_total+=morning_rate;
        evening_rate_total+=evening_rate;
    }
    
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %6.3f\n",morning_rate_total);
    printf("Evening total rating: %6.3f\n",evening_rate_total);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3f\n",morning_rate_total+evening_rate_total);
    printf("\n");

    printf("Average morning rating: %.1f\n",morning_rate_total/LOG_DAYS);
    printf("Average evening rating: %.1f\n",evening_rate_total/LOG_DAYS);
    printf("---------------------------\n");
    printf("Average overall rating: %.1f\n",((morning_rate_total+evening_rate_total)/LOG_DAYS)/2);
    
    return 0;
}