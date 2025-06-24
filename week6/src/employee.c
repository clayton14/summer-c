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


#include "employee.h"

#include <stdio.h>
#include <stdlib.h>


// employee clock number
int clock_number[LOT_SIZE] = {98401, 526488, 765349, 34645, 127615};
// hourly wage
float wageRate[LOT_SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};
float hours[LOT_SIZE];                    // number of hours worked per week
float overtime_hours[LOT_SIZE]; // number of overtime hours worked
float overtime_pay[LOT_SIZE];   // amount of overtim pay in dollars
float gross[LOT_SIZE];                    // gross pay for week (wage * hours)


float caculate_pay()
{
    return 0.0;
}

void write_to_file()
{

}

/**
 * Function: display_output()
 * ---------------------------
 *  Displays table of employee data to stdout
 *  @param num_entries the number of entries to display to stdout
 **/ 
void display_output(int num_entries)
{
    // cant display more that LOT_SIZE
    if (num_entries > LOT_SIZE)
    {
        num_entries = LOT_SIZE;
    }

    //print header
    printf("\n---------------------------------------------------------------\n");
    printf("Clock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross");
    printf("\n---------------------------------------------------------------\n");
    
    for (size_t i = 0; i < num_entries; i++)
    {

        printf("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
               clock_number[i], wageRate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);
    } //end for

}

int get_utc_time()
{
    return 0;
}