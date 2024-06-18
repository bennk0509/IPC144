#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    double totalprice = 1206575.55;
    double income = 6225.88;

    int month = (int)totalprice/income+1;
    printf("%d\n",month/12);
    printf("%d",month%12);
    return 0;
}
// #include <stdio.h>

// int main(void)
// {
//     int minutes;
//     char s;

//     printf("How many minutes left ? ");
//     scanf("%d", &minutes);

//     s = minutes > 1 ? 's' : ' ';    // Conditional Expression

//     printf("%d minute%c left\n", minutes, s);

//     return 0;
// }