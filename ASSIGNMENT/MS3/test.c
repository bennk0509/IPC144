#include "stdio.h"
#include <string.h>

struct Phone
{
    char description[100];
    char number[11];
};

// Data type: Patient 
// (Copy your code from MS#2)

struct Patient
{
    int patientNumber;
    char name[100];
    struct Phone phone;

};


// int importPatients(const char* datafile, struct Patient patients[], int max)
// {
//     FILE *fileOpen;
//     fileOpen = fopen(datafile,"r");
//     int count = 0;
//     fscanf(fileOpen,"%d|%49[^|]|%9[^|]|%14[^\n]\n",&patients[count].patientNumber,patients[count].name,patients[count].phone.description,patients[count].phone.number);
//     printf("%d|%49[^|]|%9[^|]|%14[^\n]\n",patients[count].patientNumber,patients[count].name,patients[count].phone.description,patients[count].phone.number);
// }
int main(void)
{
    FILE* file;
    struct Patient patients[100];
    file = fopen("patientData.txt","r");
    char line[100];
    int count = 0;
    // if(fgets(line, 100, file) != NULL)
    // {
    //     printf("%s",line);
    // }
    int max = 26;
    while (count < max )
    {
        int res = fscanf(file,"%d|%49[^|]|%9[^|]|%14[^\n]\n",&patients[count].patientNumber,patients[count].name,patients[count].phone.description,patients[count].phone.number);
        if(res == EOF)
            break;
        count++;
    }
    printf("Number of line %d\n",count);
    fclose(file);
    return 0;
}