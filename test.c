/* Fibonacci Series */
#include <stdio.h>
#include <string.h>
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
        if(i == minRange == maxRange)
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

void displayFormattedPhone(char* phoneNumber)
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
#define BUFFER_SIZE 300

int main() {
    printf("*** Start of Tokenizing Words Demo ***\n"); 
    char words[BUFFER_SIZE];    //create array with size 300 type char to store the words
    char* nextWord = NULL;      //create pointer nextWord
    int wordsCounter;           //create wordsCounter type int
    do {
        printf("Type a few words separated by space (q - to quit):\n");
        fgets (words, BUFFER_SIZE, stdin);      //get the string store each character into words array
        words [strlen(words) - 1] = '\0';       //set the end of the arrays is '\0' means ends of line
        //check if the words != 'q', go to inside the if loop
        if (strcmp(words, "q") != 0)            
        { 
            
            nextWord = strtok(words, " ");
            wordsCounter = 1;
            while (nextWord) {
                printf("Word #%d is \'%s\'\n", wordsCounter++, nextWord); 
                nextWord = strtok(NULL, " ");
            }
        }
    } while (strcmp(words, "q") != 0);
    printf("*** End of Tokenizing Words Demo ***\n\n");
    return 0;
}