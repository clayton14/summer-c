/***************************************
 * HOMEWORK:    Assignment 4
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-17>
 *
 * DESCRIPTION:  Program which determines employee gross pay and outputs to the screen
 * and writes to file.
 * Allows for multiple entries and caulates overtime pay and employee avrages.
 ****************************************/

#include <stdio.h>
#include <stdlib.h>

#define STD_HOURS 40.0 // Standard weekely hours before overtime.
#define LOT_SIZE 5     // Default number of employee to enter into the system.

int main()
{
    // employee clock number
    int clock_number[LOT_SIZE] = {98401, 526488, 765349, 34645, 127615};
    // hourly wage
    float wageRate [LOT_SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};    
    float gross[LOT_SIZE];          // gross pay for week (wage * hours)
    float hours[LOT_SIZE];          // number of hours worked per week
    float overtime_hours[LOT_SIZE]; // number of overtime hours worked
    float overtime_pay[LOT_SIZE];   // amount of overtim pay in dollars

    float avg_data [6];             // array to store avrage of each caculation 

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


    // start looping
    for (size_t i = 0; i < LOT_SIZE; i++)
    {
        // printf("\n***** Pay Caculator *****\n");
        // printf("\nEnter Your Employee ID: ");
        // scanf("%d", &clock_number[i]);

        // printf("\nEnter hourly wage: ");
        // scanf("%f", &wageRate[i]);

        printf("\n [ID: %06d] Enter hours worked: ", clock_number[i]);
        scanf("%f", &hours[i]);
        
        // Cant work negitave hours.
        if (hours[i] < 0)
        {
            printf("[ERROR] value cannot be negative entry terminated\n");
            hours[i] = 0; 
            continue; // continue program although error has occured.
        }

        // determine if employee worked overtime and cacualte overtime hours.
        if (STD_HOURS < hours[i])
        {
            overtime_hours[i] = hours[i] - STD_HOURS;
        }

        // calculate gross pay with overtime
        overtime_pay[i] = ((wageRate[i] * 1.5) * overtime_hours[i]);
        gross[i] = (wageRate[i] * (hours[i] - overtime_hours[i])) + overtime_pay[i];

    } // end for

    // Print header
    printf("\n---------------------------------------------------------------\n");
    printf("Clock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross");
    printf("\n---------------------------------------------------------------\n");

    // loop for prinint
    for (size_t i = 0; i < LOT_SIZE; i++)
    {
       
        printf("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
               clock_number[i], wageRate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);

        // write to file
        fprintf(output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\n",
                clock_number[i], wageRate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);

    } // end for
    
    // close the file
    fclose(output);
    return 0;
} // end main
