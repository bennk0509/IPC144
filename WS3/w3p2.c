/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char type1, type2, type3;
    int weight1, weight2, weight3;
    char isCream1, isCream2, isCream3;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &isCream1);

    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &isCream2);

    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &isCream3);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+-------+--------+-------+------+--------+-------+\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",type1 == 'L' || type1 == 'l', type1 == 'M' || type1 == 'm', type1 == 'R' || type1 == 'r', weight1, weight1 / GRAMS_IN_LBS, isCream1 == 'Y' || isCream1 == 'y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",type2 == 'L' || type2 == 'l', type2 == 'M' || type2 == 'm', type2 == 'R' || type2 == 'r', weight2, weight2 / GRAMS_IN_LBS, isCream2 == 'Y' || isCream2 == 'y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",type3 == 'L' || type3 == 'l', type3 == 'M' || type3 == 'm', type3 == 'R' || type3 == 'r', weight3, weight3 / GRAMS_IN_LBS, isCream3 == 'Y' || isCream3 == 'y');

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/