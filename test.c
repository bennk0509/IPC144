/* Fibonacci Series */
#include <stdio.h>

void clearInputBuffer(void) 
{ 
    // Discard all remaining char's from the standard input buffer: 
    while (getchar() != '\n') 
    { 
        ; // do nothing! 
    } 
} 
 
// Wait for user to input the "enter" key to continue 
void suspend(void) 
{ 
    printf("<ENTER> to continue..."); 
    clearInputBuffer(); 
    putchar('\n'); 
}

char inputCharOption(char stringOfCharacter[])
{
    int i;
    char inputChar;
    int check = 0;
    while(1)
    {
        scanf("%c",&inputChar);
        for(i=0;stringOfCharacter[i] != '\0';i++)
        {
            if(inputChar == stringOfCharacter[i])
            {
                check = 1;
            }
        }
        clearInputBuffer();
        if(check == 1)
        {
            break;
        }
    }
    return inputChar;
}

int main() {
    char inputChar[];
    scanf("%s",&inputChar);
    char* result = &inputChar;
    printf("inputted string: ",*inputChar);
    return 0;
}