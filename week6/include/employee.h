/***************************************
 * HOMEWORK:    Assignment 5
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-25>
 *
 * DESCRIPTION:  Header file for employee strcture
 * 
 ****************************************/

#include <stdbool.h>
#include <time.h>


#define STD_HOURS 40.0      // Standard weekely hours before overtime.
#define LOT_SIZE 5          // Default number of employee to enter into the system.
#define STD_OVERTIME 1.5    // Standatd time and a half pay

/**
 * Function: is_overtime()
 * ---------------------------
 *  helper function that determines if the amount of time worked is over 
 *  STD_HOURS
 *  @return true if the number of hours is is over STD_HOURS
 **/
bool is_overtime(int hours_worked);


/**
 * Function: caculate_pay()
 * ---------------------------
 * @param hours the numer of hours the employee worked
 * @param wage_rate the hourly wage of the employee
 * 
 * @returns the total gorss pay the emplyee earns with overtime
 * 
 **/
float caculate_pay(float hours, float wage_rate);


/**
 * Function: log_row()
 * ---------------------------
 *  Wites current row into desired output file 
 *  TODO: add row array
 *  @param clock_number employee clock number
 *  @param row pointer to the row of data that containes employee data
 **/
void log_row(char *filename, int clock_number, float *row);


/**
 * Function: display_row()
 * ---------------------------
 *  Wites the current employees data stdout 
 *  @param clock_number employee clock number
 *  @param row pointer to the row of data that containes the employee data
 **/
void display_row(int clock_number, float *row);



