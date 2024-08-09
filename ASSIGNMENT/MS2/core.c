#include <stdio.h>
#include "core.h"
#include <string.h>

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
            printf("ERROR! Value must be between %d and %d inclusive: ",minRange,maxRange);
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
        clearInputBuffer();
        for(i=0;stringOfCharacter[i] != '\0';i++)
        {
            if(inputChar == stringOfCharacter[i])
            {
                check = 1;
            }
        }
        if(check == 1)
        {
            break;
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ",stringOfCharacter);
        }
    }
    return inputChar;
}

void inputCString(char* inputString, int minRange, int maxRange)
{
    char str[20];
    int i;
    do
    {
        scanf("%[^\n]%*c", str);
        i=0;
        while(str[i]!='\0')
        {
            i++;
        }
        if(i != minRange && i!= maxRange && minRange == maxRange)
        {
            printf("ERROR: String length must be exactly %d chars: ",minRange);

        }
        else if (i < minRange)
        {
            printf("ERROR: String length must be between %d and %d chars: ",minRange,maxRange);
        }
        else if (i> maxRange)
        {
            printf("ERROR: String length must be no more than %d chars: ",maxRange);
        }
                
    } while ( !(i>=minRange && i <=maxRange));
    int j;
    //inputString = &str;
    if (i >= minRange && i <= maxRange) {
            // Copy the valid input to the output string manually
            for (j = 0; j < i; j++) {
                inputString[j] = str[j];
            }
            inputString[i] = '\0'; // Ensure null-termination
    }
}

void displayFormattedPhone(const char* phoneNumber)
{
    int n = 0;
    char numDigit[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int isValid = 1;
    if(phoneNumber != NULL)
    {
        while(phoneNumber[n]!= '\0')
        {
            int isDigit = 0;
            int j;
            for(j=0;j<10;j++)
            {
                 if(phoneNumber[n] == numDigit[j])
                {
                    isDigit = 1;
                    break;
                }   
            }
            if(!isDigit)
            {
                isValid = 0;
            }
            n++;
        }
        if(n == 10 && isValid == 1)
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c",
           phoneNumber[0], phoneNumber[1], phoneNumber[2],
           phoneNumber[3], phoneNumber[4], phoneNumber[5],
           phoneNumber[6], phoneNumber[7], phoneNumber[8], phoneNumber[9]);
        }
        else{
            printf("(___)___-____");
        }
    }
    else{
        printf("(___)___-____");
    }
}
