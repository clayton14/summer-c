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
//include guards
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdbool.h>
#include <time.h>

#define STD_HOURS 40.0   // Standard weekely hours before overtime.
#define LOT_SIZE 5       // Default number of employee to enter into the system.
#define STD_OVERTIME 1.5 // Standatd time and a half pay

/**
 * Function: is_overtime()
 * ---------------------------
 *  helper function that determines if the amount of time worked is over
 *  STD_HOURS
 *  @return true if the number of hours is is over STD_HOURS
 **/
bool is_overtime(float hours_worked);

/**
 * Function: caculate_pay
 *--------------------------
 * function that calculates the gross pay based on hours worked and wage rate.
 * It accounts for overtime hours, applying an overtime rate for hours
 * exceeding STD_HOURS.
 *
 * @param hours The total number of hours worked by the employee (float).
 * @param wage_rate The employee's hourly wage rate (float).
 *
 * @return float The calculated gross pay.
 */
float calculate_gross(float hours, float wage_rate);


/**
 * Function: caculate_avg
 * ------------------------
 * Caculates the avrage value given an array of floats.
 *
 * @param arr the array of floats to avrage
 * @param len the length of the array
 * 
 * @return the avrage of the array (float)
 */
float caculate_avg(float *arr, int len);



/**
 * Function: log_emp
 * ------------------------
 * Logs employee payroll information to a specified file.
 *
 * @param file_ptr A pointer to the FILE object where the data will be written.
 * This file should be opened in write mode ("w") or append mode ("a").
 * @param clock_number The employee's unique clock number (integer).
 * @param wage_rate The employee's hourly wage rate (float).
 * @param hours The number of regular hours worked by the employee (float).
 * @param overtime_hours The number of overtime hours worked by the employee (float).
 * @param overtime_pay The amount of pay earned from overtime hours (float).
 * @param gross The employee's total gross pay (float).
 *
 * @return void
 */
void log_emp(char *filename, int clock_number, float wage_rate, float hours, float overtime_hours, float overtime_pay, float gross);

/**
 * Function: display_row()
 * ---------------------------
 *  displays a row of data given array as an input
 *  @param clock_number employee clock number
 *  @param row pointer to the row of data that containes the employee data
 *
 *  @return void
 **/
void display_row(float *row);

#endif // EMPLOYEE_H