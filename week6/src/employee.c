/***************************************
 * HOMEWORK:    Assignment 5
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-24>
 *
 * DESCRIPTION:  Implimatation for employee
 * 
 * determines employee gross pay and outputs to the screen
 * and writes to file. 
 * Allows for multiple entries and caulates overtime pay 
 * and employee avrages
 ****************************************/

#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

bool is_overtime(int hours_worked)
{
    if (STD_HOURS < hours_worked)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float caculate_pay(float hours, float wage_rate)
{
    float gross;
    if (is_overtime(hours))
    {
        float overtime_hours = hours - STD_HOURS;
        float overtime_pay = ((wage_rate * STD_OVERTIME) * overtime_hours);
        gross = (wage_rate * (hours - overtime_hours)) + overtime_pay;
    }
    else
    {
        gross = wage_rate * hours;
    }

    return gross;
}

void log_row(char *filename, int clock_number, float *row)
{

    // int clock_number, float wage_rate, float hours, float overtime_hours, float overtime_pay, float gross
    //  pointer to the output file
    FILE *output;
    // Open file in append mode
    if ((output = fopen(filename, "a")) == (FILE *)NULL)
    {
        fprintf(stderr, "[ERROR] Unable to open file employee.log\n");
        return -1;
    }
    // write to file
    fprintf(output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\n",
            row[0], row[1], row[2], row[3], row[4], row[5]);

    fclose(output);
}

/**
 * Function: display_output()
 * ---------------------------
 *  Displays table of employee data to stdout
 *  @param num_entries the number of entries to display to stdout
 **/
void display_row(int clock_number, float *row)

{

    // print header
    printf("\n---------------------------------------------------------------\n");
    printf("Clock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross");
    printf("\n---------------------------------------------------------------\n");

    for (size_t i = 0; i < LOT_SIZE; i++)
    {

        printf("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
               clock_number, row[0], row[1], row[2], row[3], row[4], row[5]);
    } // end for
}
