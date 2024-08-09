/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Khanh Anh Kiet Nguyen
Student ID#: 170049233
Email      : kaknguyen@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[],int max,int fmt)
{
    int i;
    int count = 0;
    if(fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    
    for(i=0;i<max;i++)
    {
        if(patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i],fmt);
            count++;
        }
    }
    
    if(count == 0)
    {
        printf("*** No records found ***\n");
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)

void searchPatientData(const struct Patient patient[], int max)
{
        int selection = 1;
        while(selection !=0 )
        {
            printf("Search Options\n");
            printf("==========================\n");
            printf("1) By patient number\n");
            printf("2) By phone number\n");
            printf("..........................\n");
            printf("0) Previous menu\n");
            printf("..........................\n");
            printf("Selection: ");
        
        selection = inputIntRange(0, 2);
        
            if (selection == 1)
            {
                searchPatientByPatientNumber(patient, max);
            }
            else if (selection == 2)
            {
                searchPatientByPhoneNumber(patient, max);
            }
        }
    putchar('\n');
}


// Add a new patient record to the patient array
// (Copy your code from MS#2)

void addPatient(struct Patient patient[], int max)
{
        int i, count = 0;
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == 0)
            {
                patient[i].patientNumber = nextPatientNumber(patient, max);
                inputPatient(&patient[i]);
                count++;
                    printf("*** New patient record added ***\n");
            
                putchar('\n');
                i = max;
            }
        }
    
        if (count == 0)
        {
            printf("ERROR: Patient listing is FULL!\n");
            putchar('\n');
        }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max)
{
        int patientNumber = 0, patientPosition = 0;
            printf("Enter the patient number: ");
        patientNumber = inputIntPositive();
        patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    
        if (patientPosition < 0)
        {
            putchar('\n');
            printf("ERROR: Patient record not found!\n");
            putchar('\n');
            suspend();
        }
        else if (patientPosition >= 0)
        {
            menuPatientEdit(&patient[patientPosition]);
        }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)

void removePatient(struct Patient patient[], int max)
{
        int patientNumber = 0, patientPosition = 0;
        char choice[10];
            printf("Enter the patient number: ");
        patientNumber = inputIntPositive();
        patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    
        if (patientPosition < 0)
        {
            putchar('\n');
            printf("ERROR: Patient record not found!\n");
            putchar('\n');
        }
        else
        {
            displayPatientData(&patient[patientPosition], FMT_FORM);
            putchar('\n');
            printf("Are you sure you want to remove this patient record? (y/n): ");
            int isValid = 0;
            while (isValid == 0)
            {
                
                fgets(choice, sizeof(choice), stdin);
                if (strcmp(choice, "n\n") == 0)
                {
                    printf("Operation aborted.\n");
                    isValid = 1;
                }

                else if ( strcmp(choice, "y\n") == 0)
                {
                    patient[patientPosition].patientNumber = 0;
                    patient[patientPosition].name[0] = '\0';
                    patient[patientPosition].phone.description[0] = '\0';
                    patient[patientPosition].phone.number[0] = '\0';
                    printf("Patient record has been removed!\n");
                    isValid = 1;
                }
                else
                {
                    printf("ERROR: Character must be one of [yn]: ");
                    // Continue looping for valid input
                }
            }

        putchar('\n');
    }
}



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    qsort(data->appointments, data->maxAppointments, sizeof(struct Appointment), compareAppointments);

    struct Date allDates = {0};  // Dummy date for the all records header
    displayScheduleTableHeader(&allDates, 1);
    int i;
    int j;
    for (i = 0; i < data->maxAppointments; i++) {
        // Find the corresponding patient for the current appointment
        struct Patient* patient = NULL;
        for (j = 0; j < data->maxPatient; j++) {
            if (data->patients[j].patientNumber == data->appointments[i].patientNumber) {
                patient = &data->patients[j];
                break;
            }
        }

        if (patient != NULL) {
            displayScheduleData(patient, &data->appointments[i], 1);
        }
    }
    putchar('\n');

}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    struct Date searchDate;
    printf("Year        : ");
    searchDate.year = inputIntPositive();
    printf("Month (1-12): ");
    searchDate.month = inputIntRange(1, 12);
    int maxDayAMonth = daysInMonth(searchDate.month,searchDate.year);
    printf("Day (1-%d)  : ",maxDayAMonth);
    searchDate.day = getValidDay(searchDate.month, searchDate.year);
    printf("\n");
    int count = 0;
    struct Appointment appointmentsForDate[data->maxAppointments];
    int i;
    for (i = 0; i < data->maxAppointments; i++) {
        if (data->appointments[i].date.year == searchDate.year &&
            data->appointments[i].date.month == searchDate.month &&
            data->appointments[i].date.day == searchDate.day) {
            appointmentsForDate[count++] = data->appointments[i];
        }
    }
    // Sort the appointments for the specific date
    qsort(appointmentsForDate, count, sizeof(struct Appointment), compareAppointments);

    displayScheduleTableHeader(&searchDate, 0);

    for (i = 0; i < count; i++) {
        // Find the corresponding patient for the current appointment
        struct Patient* patient = NULL;
        for (int j = 0; j < data->maxPatient; j++) {
            if (data->patients[j].patientNumber == appointmentsForDate[i].patientNumber) {
                patient = &data->patients[j];
                break;
            }
        }

        if (patient != NULL) {
            displayScheduleData(patient, &appointmentsForDate[i], 0);
        }
        }
    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatients) 
{
    int patientNumber;
    struct Date date;
    struct Time time;

    do
    {
        printf("Patient Number: ");
        scanf("%d", &patientNumber);
        if (!isValidPatientNumberForRemoval(patientNumber, patients, maxPatients)) {
            printf("ERROR: Invalid patient number!\n\n");
    }
    } while (!isValidPatientNumberForRemoval(patientNumber, patients, maxPatients));

    printf("Year        : ");
    scanf("%d", &date.year);
    printf("Month (1-12): ");
    scanf("%d", &date.month);
    int maxDayAMonth = daysInMonth(date.month,date.year);
    printf("Day (1-%d)  : ",maxDayAMonth);
    date.day = getValidDay(date.month, date.year);
    int validTime = 0;
    int validDay = 0;
    while (!validTime) {
        if(validDay == 1)
        {
            printf("Year        : ");
            scanf("%d", &date.year);
            printf("Month (1-12): ");
            scanf("%d", &date.month);
            int maxDayAMonth = daysInMonth(date.month,date.year);
            printf("Day (1-%d)  : ",maxDayAMonth);
            date.day = getValidDay(date.month, date.year);
            validDay = 0;
        }

        printf("Hour (0-23)  : ");
        scanf("%d", &time.hour);
        printf("Minute (0-59): ");
        scanf("%d", &time.min);
        if (!isValidAppointmentTime(date, time)) {
            printf("ERROR: Time must be between %02d:00 and %02d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
            continue;
        }

        if (isAppointmentConflict(appointments, maxAppointments, &date, &time)) {
            printf("\n");
            printf("ERROR: Appointment timeslot is not available!\n\n");
            validDay = 1;
            continue;
        }

        validTime = 1;
    }

    int slot = findAvailableAppointmentSlot(appointments, maxAppointments);
    if (slot == -1) {
        printf("ERROR: No available appointment slots!\n\n");
        return;
    }

    // Add the appointment
    appointments[slot].patientNumber = patientNumber;
    appointments[slot].date = date;
    appointments[slot].time = time;

    printf("\n*** Appointment scheduled! ***\n");
    putchar('\n');
    clearInputBuffer();
}
// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatients) {
    int patientNumber;
    struct Date date;

    printf("Patient Number: ");
    scanf("%d", &patientNumber);

    if (!isValidPatientNumberForRemoval(patientNumber, patients, maxPatients)) {
        printf("ERROR: Patient record not found\n\n");
        clearInputBuffer();
        return;
    }
    printf("Year        : ");
    scanf("%d", &date.year);
    printf("Month (1-12): ");
    scanf("%d", &date.month);
    int maxDayAMonth = daysInMonth(date.month,date.year);
    printf("Day (1-%d)  : ",maxDayAMonth);
    date.day = getValidDay(date.month, date.year);

    printf("\n");
    // Find the appointment to remove
    int found = 0;
    int i;
    for (i = 0; i < maxAppointments; i++) {
        if (appointments[i].patientNumber == patientNumber &&
            appointments[i].date.year == date.year &&
            appointments[i].date.month == date.month &&
            appointments[i].date.day == date.day) {

            // Display patient details
            displayPatientDetails(patientNumber, patients, maxPatients);
            printf("\n");
            // Confirm removal
            char confirmation;
            printf("Are you sure you want to remove this appointment (y,n): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y' || confirmation == 'Y') {
                // Mark the appointment as removed
                appointments[i].patientNumber = 0;
                appointments[i].date.year = 0;
                appointments[i].date.month = 0;
                appointments[i].date.day = 0;
                appointments[i].time.hour = 0;
                appointments[i].time.min = 0;
                printf("\n*** Appointment record has been removed! ***\n\n");
                clearInputBuffer();
            } else {
                printf("Appointment removal cancelled.\n\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("ERROR: No matching appointment found for the given patient number and date.\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
        int patientNumber = 0, patientIndex = 0;
        
            putchar('\n');
            printf("Search by patient number: ");
        
        patientNumber = inputIntPositive();
        patientIndex = findPatientIndexByPatientNum(patientNumber, patient, max);
    
        if (patientIndex < 0)
        {
            putchar('\n');
            printf("*** No records found ***\n");
        }
        else
        {
            displayPatientData(&patient[patientIndex], FMT_FORM);
        }
    
    
        putchar('\n');
        suspend();
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
        putchar('\n');
        int i, count = 0;
        char phoneNumber[PHONE_LEN + 1] = { 0 };
    
            printf("Search by phone number: ");
        
        inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
        putchar('\n');
        displayPatientTableHeader();
    
    
        for (i = 0; i < max; i++)
        {
            if (strcmp(patient[i].phone.number, phoneNumber) == 0)
            {
                displayPatientData(&patient[i], FMT_TABLE);
                count++;
            }
        }

        if (count == 0)
        {
            putchar('\n');
            printf("*** No records found ***\n");
        }
    
        putchar('\n');
        suspend();
}


// Get the next highest patient number
// (Copy your code from MS#2)

int nextPatientNumber(const struct Patient patient[], int max)
{
        int i, maxNum = 0;
        
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber >= maxNum)
            {
                maxNum = patient[i].patientNumber + 1;
            }
        }
    return maxNum;
}


// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
        int i;
    
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == patientNumber)
            {
                putchar('\n');
                return i;
            }
        }
    return -1;
}

int compareAppointments(const void *a, const void *b)
{
    struct Appointment *ap1 = (struct Appointment *)a;
    struct Appointment *ap2 = (struct Appointment *)b;

    if (ap1->date.year == 0 && ap1->date.month == 0 && ap1->date.day == 0)
        return 1; // Push ap1 to the end
    if (ap2->date.year == 0 && ap2->date.month == 0 && ap2->date.day == 0)
        return -1; // Push ap2 to the end

    if (ap1->date.year != ap2->date.year) {
        return ap1->date.year - ap2->date.year;
    }
    // Compare month
    if (ap1->date.month != ap2->date.month) {
        return ap1->date.month - ap2->date.month;
    }
    // Compare day
    if (ap1->date.day != ap2->date.day) {
        return ap1->date.day - ap2->date.day;
    }
    // Compare hour
    if (ap1->time.hour != ap2->time.hour) {
        return ap1->time.hour- ap2->time.hour;
    }
    // Compare minute
    return ap1->time.min - ap2->time.min;
}

int isValidAppointmentTime(struct Date date, struct Time time) {
    if (time.hour < START_HOUR || time.hour > END_HOUR) {
        return 0; // Invalid hour
    }
    if (time.hour == END_HOUR && time.min != 0) {
        return 0; // End hour must have 0 minutes
    }
    if (time.min % APPOINTMENT_INTERVAL != 0) {
        return 0; // Invalid minute interval
    }
    return 1; // Valid time
}

int isValidPatientNumberForRemoval(int patientNumber, struct Patient* patients, int maxPatients) {
    int i;
    for (i = 0; i < maxPatients; i++) {
        if (patients[i].patientNumber == patientNumber) {
            return 1; // Valid patient number
        }
    }
    return 0; // Invalid patient number
}

int isAppointmentConflict(const struct Appointment* appointments, int maxAppointments, const struct Date* date, const struct Time* time) {
    int i;
    for (i = 0; i < maxAppointments; i++) {
        // Check if the date matches
        if (appointments[i].date.year == date->year &&
            appointments[i].date.month == date->month &&
            appointments[i].date.day == date->day) {
            
            // Check if the time matches
            if (appointments[i].time.hour == time->hour &&
                appointments[i].time.min == time->min) {
                return 1; // Conflict found
            }
        }
    }
    return 0; // No conflict
}

void displayPatientDetails(int patientNumber, struct Patient* patients, int maxPatients) {
    for (int i = 0; i < maxPatients; i++) {
        if (patients[i].patientNumber == patientNumber) {
            struct Patient* curPatient = &patients[i];            
            displayPatientData(curPatient,FMT_FORM);
            return;
        }
    }
    printf("ERROR: Patient number not found.\n");
}

int findAvailableAppointmentSlot(const struct Appointment* appointments, int maxAppointments) {
    int i;
    for (i = 0; i < maxAppointments; i++) {
        if (appointments[i].patientNumber == 0 && appointments[i].date.year == 0 && appointments[i].date.month == 0 && appointments[i].date.day == 0 && appointments[i].time.hour == 0 && appointments[i].time.min == 0 ) { // Assuming an invalid patient number indicates an empty slot
            return i; // Return the index of the available slot
        }
    }
    return -1; // No available slot found
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11: // April, June, September, November
            return 30;
        case 2: // February
            return isLeapYear(year) ? 29 : 28;
        default: // January, March, May, July, August, October, December
            return 31;
    }
}

// Function to get a valid day for a given month and year
int getValidDay(int month, int year) {
    int maxDays = daysInMonth(month, year);
    return inputIntRange(1, maxDays);
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)

void inputPatient(struct Patient* patient)
{
        printf("Patient Data Input\n"
                "------------------\n");
    
        printf("Number: %05d\n", patient->patientNumber);
        printf("Name  : ");
        
        
        inputCString(patient->name, 1, NAME_LEN);
        
        putchar('\n');
        
        inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)

void inputPhoneData(struct Phone* phone)
{
        int selection = 0;
        char des1[PHONE_DESC_LEN + 1] = { "CELL" };
        char des2[PHONE_DESC_LEN + 1] = { "HOME" };
        char des3[PHONE_DESC_LEN + 1] = { "WORK" };
        char des4[PHONE_DESC_LEN + 1] = { "TBD" };
            printf("Phone Information\n");
            printf("-----------------\n");
            printf("How will the patient like to be contacted?\n");
            printf("1. Cell\n"
                   "2. Home\n"
                   "3. Work\n"
                   "4. TBD\n");
    
            printf("Selection: ");
    
        selection = inputIntRange(1, 4);
            
            printf("\n");
    
        if (selection == 1)
            strcpy(phone->description, des1);
        else if (selection == 2)
            strcpy(phone->description, des2);
        else if (selection == 3)
            strcpy(phone->description, des3);
        else if (selection == 4)
            strcpy(phone->description, des4);
    
        if(selection != 4)
        {
        
            printf("Contact: %s\n", phone->description);
            int isPhone = 0;
            do {
                char inputPhone[20];
                printf("Number : ");
                scanf("%[^\n]%*c", inputPhone);
                int len = strlen(inputPhone);
                if(len != 10)
                {
                    printf("Invalid 10-digit number! ");
                }
                else{
                    strcpy(phone->number,inputPhone);
                    isPhone = 1; 
                }
            } while (!isPhone);
            
        
        //check the number is 10 digit or not, if not scanf the number again
        
        putchar('\n');
        }
        else
        {
            phone->number[0] = '\0';
        }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* file;
    int count = 0;
    file  = fopen(datafile,"r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }
    while (count < max )
    {
        int res = fscanf(file,"%d|%49[^|]|%9[^|]|%14[^\n]\n",&patients[count].patientNumber,patients[count].name,patients[count].phone.description,patients[count].phone.number);
        if(res == EOF)
            break;
        count++;
    }
    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* file;
    int count = 0;
    file  = fopen(datafile,"r");
    if (file == NULL)
    {
        printf("Error to import file.\n");
        return -1;
    }
    while (count < max )
    {
        int res = fscanf(file,"%d,%d,%d,%d,%d,%d\n",&appoints[count].patientNumber,&appoints[count].date.year,&appoints[count].date.month,&appoints[count].date.day,&appoints[count].time.hour,&appoints[count].time.min);
        if(res == EOF)
            break;
        count++;
    }
    return count;
}
