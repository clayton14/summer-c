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

    employee emp;
    emp.clock_number = 98401;
    printf("emp num: %d\n", emp.clock_num);

    int clock_number[LOT_SIZE] = {
        98401, 526488, 765349, 34645, 127615};
    float wage_rate[LOT_SIZE] = {
        10.6, 9.75, 10.5, 12.25, 8.35};

    // float hours[LOT_SIZE] = {0.0f};          // number of hours worked per week
    // float overtime_hours[LOT_SIZE] = {0.0f}; // number of overtime hours worked
    // float overtime_pay[LOT_SIZE] = {0.0f};   // amount of overtim pay in dollars
    // float gross[LOT_SIZE] = {0.0f};          // gross pay for week (wage * hours)


    printf("*********** Pay Calculator ***********");

    

    // start looping
    // for (size_t i = 0; i < LOT_SIZE; i++)
    // {

    //     printf("\n [ID: %06d] Enter hours worked: ", clock_number[i]);
    //     scanf("%f", &hours[i]);

    //     // Cant work negitave hours.
    //     if (hours[i] < 0)
    //     {
    //         printf("[ERROR] value cannot be negative entry terminated\n");
    //         hours[i] = 0;
    //         continue; // continue program although error has occured.
    //     }

    //     if(is_overtime(hours[i]))
    //     {
    //         overtime_hours[i] = hours[i] - STD_HOURS;
    //         printf("OT hr: %2.2f", overtime_hours[i]);
    //     }
    //     else
    //     {
    //         overtime_hours[i] = 0; 
    //     }
    //     overtime_pay[i] = overtime_hours[i] * wage_rate[i];
    //     gross[i] = calculate_gross(hours[i], wage_rate[i]);
    //     //printf("AVG wage: %2.2f   %2.2f\n", caculate_avg(wage_rate, LOT_SIZE), wage_rate[i]);


    // } // end for

    // printf("\n---------------------------------------------------------------\n");
    // printf("Clock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross");
    // printf("\n---------------------------------------------------------------\n");

    // // loop
    // for (size_t i = 0; i < LOT_SIZE; i++)
    // {
    //     printf("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n",
    //        clock_number[i], wage_rate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);
    //     log_emp("home.txt", clock_number[i], wage_rate[i], hours[i], overtime_hours[i], overtime_pay[i], gross[i]);
    // } // end for

    // printf("---------------------------------------------------------------\n");
    
    // float avg_wage = caculate_avg(wage_rate, LOT_SIZE);
    // float avg_hours = caculate_avg(hours, LOT_SIZE);
    // float avg_overtime_hr = caculate_avg(overtime_hours, LOT_SIZE);
    // float avg_overtime_pay = caculate_avg(overtime_pay, LOT_SIZE);
    // float avg_gross = caculate_avg(gross, LOT_SIZE);

    // printf("Avg:\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n", 
    //         avg_wage, avg_hours, avg_overtime_hr, avg_overtime_pay, avg_gross
    //     );


    return 0;
} // end main
