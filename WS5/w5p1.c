/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year = 0;
    int month = 0;
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

    switch (month)
    {
    case 1:
        printf("Log starting date: %d-JAN-01",year);
        break;
    case 2:
        printf("Log starting date: %d-FEB-01",year);
        break;
    case 3:
        printf("Log starting date: %d-MAR-01",year);
        break;
    case 4:
        printf("Log starting date: %d-APR-01",year);
        break;
    case 5:
        printf("Log starting date: %d-MAY-01",year);
        break;
    case 6:
        printf("Log starting date: %d-JUN-01",year);
        break;
    case 7:
        printf("Log starting date: %d-JUL-01",year);
        break;
    case 8:
        printf("Log starting date: %d-AUG-01",year);
        break;
    case 9:
        printf("Log starting date: %d-SEP-01",year);
        break;
    case 10:
        printf("Log starting date: %d-OCT-01",year);
        break;
    case 11:
        printf("Log starting date: %d-NOV-01",year);
        break;
    case 12:
        printf("Log starting date: %d-DEC-01",year);
        break;
    default:
        break;
    }
    return 0;
}