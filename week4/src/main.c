/***************************************
 * HOMEWORK:    Assignment 3
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-09>
 *
 * DESCRIPTION:  Program which determines employee gross pay and outputs to the screen
 * and writes to file.
 * Allows for multiple entries and caulates overtime pay.
 ****************************************/

#include <stdio.h>
#include <stdlib.h>

#define STD_HOURS 40.0 // Standard weekely hours before overtime.
// #define LOT_SIZE 5     // Default number of employee to enter into the system.

int main()
{
    int clock_number;       // employee clock number
    int num_employees;
    float gross;          // gross pay for week (wage * hours)
    float hours;          // number of hours worked per week
    float overtime_hours; // number of overtime hours worked
    float wageRate;       // hourly wage

    FILE *output; // pointer to the output file

    // taken from example
    // Open file in append mode
    if ((output = fopen("home.txt", "a")) == (FILE *)NULL) // why cast type to NULL pointer ?
    {
        fprintf(stderr, "[ERROR] Unable to open file home.txt\n");
        return -1;
    }

    fprintf(output, "\n***** Pay Caculator *****\n");
    // add headder to home.txt
    fprintf(output, "Clock#\tWage\tHours\tOT Pay\t\tGross");
    fprintf(output, "\n---------------------------------------------------------------\n");

    printf("\nHow many entries are you entering: ");
    scanf("%d", &num_employees);

    if (num_employees < 0)
    {
        printf("[ERROR] value cannot be negative\n");
        return -1; // return -1 if an error occurs
    }

    // start looping
    for (size_t i = 0; i < num_employees; i++)
    {
        printf("\n***** Pay Caculator *****\n");
        printf("\nEnter Your Employee ID: ");
        scanf("%d", &clock_number);

        printf("\nEnter hourly wage: ");
        scanf("%f", &wageRate);

        printf("\nEnter hours worked: ");
        scanf("%f", &hours);

        // determine if employee worked overtime and cacualte overtime hours.
        if (STD_HOURS < hours)
        {
            overtime_hours = hours - STD_HOURS;
            printf("overtime_hours: %2.2f\n", overtime_hours);
        }

        if ((clock_number < 0) || (wageRate < 0) || (hours < 0) || (num_employees < 0) || (overtime_hours < 0))
        {
            printf("[ERROR] value cannot be negative entry terminated\n");
            continue; // continue program although error has occured.
        }

        // calculate gross pay with overtime
        float overtime_pay = ((wageRate * 1.5) * overtime_hours);
        gross = (wageRate * (hours - overtime_hours)) + overtime_pay;

        // print to screen
        printf("\n---------------------------------------------------------------\n");
        printf("Clock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross");
        printf("\n---------------------------------------------------------------\n");
        printf("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n", 
            clock_number, wageRate, hours, overtime_hours, overtime_pay, gross);

        // write to file
        fprintf(output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\n", 
            clock_number, wageRate, hours, overtime_hours, overtime_pay, gross);

        overtime_hours = 0; // reset for next entry
    } // end for
    // close the file
    fclose(output);
    return 0;
} // end main
