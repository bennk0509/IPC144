#include <stdio.h>
#include "core.h"

// As demonstrated in the course notes:  
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer  
// Clear the standard input buffer 
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

//Get valid integer from the keyboard
int inputInt()
{
    char newLine = 'x';
    int value = 0;
    do
    {
        scanf("%d%c",&value,&newLine);
        if(newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (newLine != '\n');
    return value;
}

int inputIntPositive()
{
    int value = 0;
    do
    {
        value = inputInt();
        if(value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value  <= 0);
    return value;
}

int inputIntRange(int minRange, int maxRange)
{
    int value = 0;
    do
    {
        value = inputInt();
        if(!(value>= minRange && value <= maxRange))
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (!(value>= minRange && value <= maxRange));
    return value;
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


void inputCString(char* inputString, int minRange, int maxRange)
{
    
}