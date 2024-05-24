/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

#include <stdio.h>
#include <math.h>

int round_to_nearest_penny(double value) {
    int cents = value*100;
    int fractional_part = (int)(value*100*100) % 100;
     if (fractional_part >= 50) {
        cents = cents + 1;
    }
    return cents;
}


int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    float small_shirt_price = 0, medium_shirt_price = 017.96, large_shirt_price = 0;
    int num_shirts = 0;
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f",&small_shirt_price);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f",&medium_shirt_price);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f",&large_shirt_price);
    printf("\n");
    printf("Shirt Store Price List \n======================\n");
    printf("SMALL : $%.2f \n",small_shirt_price);
    printf("MEDIUM : $%.2f \n",medium_shirt_price);
    printf("LARGE : $%.2f \n",large_shirt_price);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d",&num_shirts);

    int sub_total  = 0, taxes = 0, total = 0;

    // sub_total = round(small_shirt_price*num_shirts*100+0.50);
    // taxes = round(small_shirt_price*num_shirts*TAX*100+0.50);
    // total = round((small_shirt_price*num_shirts*(TAX+1))*100+0.50);
    sub_total = round_to_nearest_penny(small_shirt_price*num_shirts);
    taxes = round_to_nearest_penny(small_shirt_price*num_shirts*TAX);
    total = round_to_nearest_penny(small_shirt_price*num_shirts*(1+TAX));
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n",num_shirts);
    printf("Sub-total: $%8.4f\n",(float)sub_total/100);
    printf("Taxes : $ %8.4f\n",(float)taxes/100);
    printf("Total : $%8.4f\n",(float)total/100);

    //float medium_shirt_price = scanf("&f","Enter the price for a MEDIUM shirt: $\n");
    //float large_shirt_price = scanf("&f","Enter the price for a LARGE shirt: $\n");
    return 0;
}