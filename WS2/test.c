#include <stdio.h>

int main()
{
    int result, money = 2031;
    //why .2lf result is 0

    printf("1. $%.2lf\n", money / 100);
    printf("1. $%f\n", money / 100);
    printf("2. $%d\n", money / 100);
    printf("3. $%.2lf\n", (double)money / 100);
    printf("4. $%d\n", (double)money / 100);

    return 0;
}