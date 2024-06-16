#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // char hello[5+1] = "HELLO";
    // int arr[10] = {1,2,3,4,5,6};
    // int i;
    // // for (i=0;i<6;i++)
    // // {
    // //     printf("%c",hello[i]);
    // // }
    // printf("%d",arr[7]);
    
    // // int i, one=0,total=0,two=0;
    // // total = scanf("%d %d",&two,&one);
    // // for (i=0;i<3;i++)
    // // {
    // //     if (i%two)
    // //     {
    // //         total +=one*two;
    // //     }
    // //     else
    // //     {
    // //         total -=one*two;
    // //     }
    // // }
    // // printf("%d",total);
    // // return 0;
    char str[] = "hello"; // 'h', 'e', 'l', 'l', 'o', '\0'
    int ar[7] = {0};
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("String: %s\n", str); // Output: hello
    
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