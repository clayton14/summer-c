/***************************************
 * HOMEWORK:    Assignment 5
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-24>
 *
 * DESCRIPTION:  Program which determines employee gross pay and outputs to the screen
 * and writes to file.
 * Allows for multiple entries and caulates overtime pay and employee avrages.
 ****************************************/

#include <stdio.h>
#include <stdlib.h>

#include "employee.h"




int main()
{
    

    float avg_data[5] = {0}; // array to store avrage of each metric

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
        else
        {
            overtime_hours[i] = 0;
        }

        // calculate gross pay with overtime
        overtime_pay[i] = ((wageRate[i] * STD_OVERTIME) * overtime_hours[i]);
        gross[i] = (wageRate[i] * (hours[i] - overtime_hours[i])) + overtime_pay[i];

        // sum total of each metric in there respective index in the array
        // defined in order as listed above
        avg_data[0] += wageRate[i];
        avg_data[1] += hours[i];
        avg_data[2] += overtime_hours[i];
        avg_data[3] += overtime_pay[i];
        avg_data[4] += gross[i];

    } // end for
    
    // Print header


    // loop
    for (size_t i = 0; i < LOT_SIZE; i++)
    {
        // print to stdout
        printf("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
               clock_number[i], wageRate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);

        // write to file
        fprintf(output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\n",
                clock_number[i], wageRate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);

    } // end for

    // Spacer
    printf("---------------------------------------------------------------\n");

    // print avrages using format described in assignment 4
    // display and write total
    printf("Total\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
           avg_data[0], avg_data[1], avg_data[2], avg_data[3], avg_data[4]);

    fprintf(output, "Total\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
            avg_data[0], avg_data[1], avg_data[2], avg_data[3], avg_data[4]);

    // display avg
    printf("Avrage \t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
           avg_data[0] / LOT_SIZE, avg_data[1] / LOT_SIZE, avg_data[2] / LOT_SIZE, avg_data[3] / LOT_SIZE, avg_data[4] / LOT_SIZE);

    fprintf(output, "Total\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
            avg_data[0] / LOT_SIZE, avg_data[1] / LOT_SIZE, avg_data[2] / LOT_SIZE, avg_data[3] / LOT_SIZE, avg_data[4] / LOT_SIZE);

    // close the file
    fclose(output);
    return 0;
} // end main
