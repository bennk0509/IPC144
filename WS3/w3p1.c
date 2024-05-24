/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233
Email      : kaknguyen@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    int productID1 = 111, productID2 = 222, productID3 = 111;
    double price1 = 111.49, price2 = 222.99, price3 = 334.49;
    char tax1 = 'Y', tax2 = 'N', tax3 = 'N';
    double avgPrice;
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n",productID1);
    printf("   Taxed: %c\n",tax1);
    printf("   Price: %.4lf\n",price1);
    printf("\n");
    printf("Product-2 (ID:%d)\n",productID2);
    printf("   Taxed: %c\n",tax2);
    printf("   Price: %.4lf\n",price2);
    printf("\n");
    printf("Product-3 (ID:%d)\n",productID3);
    printf("   Taxed: %c\n",tax3);
    printf("   Price: %.4lf\n",price3);
    printf("\n");
    avgPrice = (price1 + price2 + price3) / 3;
    printf("Average Price: %.4lf\n",avgPrice);
    printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("=========================================\n");
    printf("1. There expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n",tax1 == 'Y');
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable? -> %d\n",tax2 == 'N' && tax3 == 'N');
    printf("\n");
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n",testValue,price3 < testValue);
    printf("\n");
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n",price3 > price1 + price2);
    printf("\n");
    printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2? -> %d (price difference: $%.2lf)",price1 >= price3 - price2,price3 - price2);
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n",price2 >= avgPrice);
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n",productID1!= productID2 && productID1 != productID3);
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n",productID2!= productID1 && productID2 != productID3);
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n",productID3!= productID2 && productID3 != productID1);
    printf("\n");
    return 0;
}