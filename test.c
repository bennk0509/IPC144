#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int i, one=0,total=0,two=0;
    total = scanf("%d %d",&two,&one);
    for (i=0;i<3;i++)
    {
        if (i%two)
        {
            total +=one*two;
        }
        else
        {
            total-=one*two;
        }
    }
    printf("%d",total);
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