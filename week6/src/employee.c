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

bool is_overtime(float hours_worked)
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

float calculate_gross(float hours, float wage_rate)
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



float caculate_avg(float *arr, int len)
{
    float total = 0;
    if (len <= 0)
    {
        return 0.0f;
    }

    for (size_t i = 0; i < len; i++)
    {
        total += arr[i];
    }

    return total / len;
}

void log_emp(char *filename, int clock_number, float wage_rate, float hours, float overtime_hours, float overtime_pay, float gross)
{
    FILE *output;
    if ((output = fopen(filename, "a")) == (FILE *)NULL)
    {
        fprintf(stderr, "[ERROR] Unable to open file employee.log\n");
    }
    fprintf(output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\n",
            clock_number, wage_rate, hours, overtime_hours, overtime_pay, gross);

    fclose(output);
}



void display_row(float *row)
{
    for (size_t i = 0; i < LOT_SIZE; i++)
    {
        printf("%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
               row[0], row[1], row[2], row[3], row[4], row[5]);
    } // end for
}
