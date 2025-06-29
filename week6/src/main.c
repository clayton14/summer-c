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
    

    int clock_number[LOT_SIZE] = {
        98401, 526488, 765349, 34645, 127615};
    float wage_rate[LOT_SIZE] = {
        10.6, 9.75, 10.5, 12.25, 8.35};
    float hours[LOT_SIZE];          // number of hours worked per week
    float overtime_hours[LOT_SIZE]; // number of overtime hours worked
    float overtime_pay[LOT_SIZE];   // amount of overtim pay in dollars
    float gross[LOT_SIZE];          // gross pay for week (wage * hours)
    float avg_data[5] = {0};        // array to store avrage of each metric

    FILE *output;                  
        
   


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


        gross[i] = caculate_pay(hours[i], wage_rate[i]);
        
        // sum total of each metric in there respective index in the array
        // defined in order as listed above
        avg_data[0] += wage_rate[i];
        avg_data[1] += hours[i];
        avg_data[2] += overtime_hours[i];
        avg_data[3] += overtime_pay[i];
        avg_data[4] += gross[i];

    } // end for
    
   


    // loop
    for (size_t i = 0; i < LOT_SIZE; i++)
    {
        // print to stdout


       
    } // end for

    // Spacer

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
    
    return 0;
} // end main
