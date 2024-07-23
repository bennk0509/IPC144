
#ifndef CORE_H
#define CORE_H

// Clear the standard input buffer 
void clearInputBuffer(void); 
 
// Wait for user to input the "enter" key to continue 
void suspend(void);

//Get valid integer from the keyboard
int inputInt();

//Perform the same operations as inputInt but validates the value entered is greater than 0.
int inputIntPositive();

//performs the same operations as inputInt but validates the value entered is between the 
//two arguments received by the function (inclusive)
int inputIntRange(int minRange, int maxRange);

//return a single character value
//receives one argument an unmodifiable C string array representing a list of valid characters. 
char inputCharOption(char * stringOfCharacter);

void inputCString(char* inputString, int minRange, int maxRange);
//The purpose of this function is to obtain user input for a C string value with a length (number of 
//characters) in the character range specified by the 2nd and 3rd arguments received (inclusive).

void displayFormattedPhone(char* displayString);

#endif