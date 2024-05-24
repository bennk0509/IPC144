/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    
    float small_shirt_price = 0, medium_shirt_price = 017.96, large_shirt_price = 0;
    int num_shirts_pat_size = 0, num_shirts_sal_size = 0, num_shirts_tom_size = 0;
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
    scanf("%d",&num_shirts_pat_size);

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Sal is buying: ");
    scanf("%d",&num_shirts_tom_size);
    
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sal is buying: ");
    scanf("%d",&num_shirts_sal_size);

    int sub_total_patty  = 0, taxes_patty = 0, total_patty = 0;
    int sub_total_sal  = 0, taxes_sal = 0, total_sal = 0;
    int sub_total_tom  = 0, taxes_tom = 0, total_tom = 0;
    int total = 0, taxes = 0, sub_total = 0;

    sub_total_patty = round_to_nearest_penny(small_shirt_price*num_shirts_pat_size);
    taxes_patty = round_to_nearest_penny(small_shirt_price*num_shirts_pat_size*TAX);
    total_patty = round_to_nearest_penny(small_shirt_price*num_shirts_pat_size*(1+TAX));

    sub_total_sal = round_to_nearest_penny(medium_shirt_price*num_shirts_sal_size);
    taxes_sal = round_to_nearest_penny(medium_shirt_price*num_shirts_sal_size*TAX);
    total_sal = round_to_nearest_penny(medium_shirt_price*num_shirts_sal_size*(1+TAX));

    sub_total_tom = round_to_nearest_penny(large_shirt_price*num_shirts_tom_size);
    taxes_tom = round_to_nearest_penny(large_shirt_price*num_shirts_tom_size*TAX);
    total_tom = round_to_nearest_penny(large_shirt_price*num_shirts_tom_size*(1+TAX));

    total = total_patty + total_sal + total_tom;
    sub_total = sub_total_patty + sub_total_sal + sub_total_tom;
    taxes = taxes_patty + taxes_sal + taxes_tom;


    printf("Customer Size Price Qty Sub-total   Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty   %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",patSize, small_shirt_price, num_shirts_pat_size, (float)sub_total_patty/100, (float)taxes_patty/100, (float)total_patty/100);
    printf("Sally   %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",salSize, medium_shirt_price, num_shirts_sal_size, (float)sub_total_sal/100, (float)taxes_sal/100, (float)total_sal/100);
    printf("Tommy   %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",tomSize, large_shirt_price, num_shirts_tom_size, (float)sub_total_tom/100, (float)taxes_tom/100, (float)total_tom/100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                       %9.4lf %9.4lf %9.4lf\n",(float)sub_total/100, (float)taxes/100, (float)total/100);

    printf("\n");
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    int num_toonnies = sub_total/200;
    int num_loonies = (sub_total%200)/100;
    int num_quarters = (sub_total%100)/25;
    int num_dimes = (sub_total%25)/10;
    int num_nickels = (sub_total%10)/5;
    int num_pennies = sub_total%5;

    //subtotal = 323.5100 - toonies_num*200 = 1.5100 remaining
    int remaining_balance = sub_total - (num_toonnies*200);
    printf("Toonies  %3d %9.4lf\n",num_toonnies,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_loonies*100);
    printf("Loonies  %3d %9.4lf\n",num_loonies,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_quarters*25);
    printf("Quarters %3d %9.4lf\n",num_quarters,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_dimes*10);
    printf("Dimes    %3d %9.4lf\n",num_dimes,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_nickels*5);
    printf("Nickels  %3d %9.4lf\n",num_nickels,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_pennies);
    printf("Pennies  %3d %9.4lf\n",num_pennies,(float)remaining_balance/100);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n",(float)sub_total/100/(num_shirts_pat_size+num_shirts_sal_size+num_shirts_tom_size));
    printf("\n");

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    num_toonnies = total/200;
    num_loonies = (total%200)/100;
    num_quarters = (total%100)/25;
    num_dimes = (total%25)/10;
    num_nickels = (total%10)/5;
    num_pennies = total%5;

    //subtotal = 323.5100 - toonies_num*200 = 1.5100 remaining
    remaining_balance = total - (num_toonnies*200);
    printf("Toonies  %3d %9.4lf\n",num_toonnies,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_loonies*100);
    printf("Loonies  %3d %9.4lf\n",num_loonies,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_quarters*25);
    printf("Quarters %3d %9.4lf\n",num_quarters,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_dimes*10);
    printf("Dimes    %3d %9.4lf\n",num_dimes,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_nickels*5);
    printf("Nickels  %3d %9.4lf\n",num_nickels,(float)remaining_balance/100);
    remaining_balance = remaining_balance - (num_pennies);
    printf("Pennies  %3d %9.4lf\n",num_pennies,(float)remaining_balance/100);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n",(float)total/100/(num_shirts_pat_size+num_shirts_sal_size+num_shirts_tom_size));
    printf("\n");

    //float medium_shirt_price = scanf("&f","Enter the price for a MEDIUM shirt: $\n");
    //float large_shirt_price = scanf("&f","Enter the price for a LARGE shirt: $\n");
    return 0;
}