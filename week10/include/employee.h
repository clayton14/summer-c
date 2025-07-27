/***************************************
 * HOMEWORK:    Assignment 9
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-26
 *
 * DESCRIPTION:  Header file for employee strcture
 *
 ****************************************/
//include guards
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "taxes.h"

#define STD_HOURS 40.0   // Standard weekely hours before overtime.
#define LOT_SIZE 5       // Default number of employee to enter into the system.
#define STD_OVERTIME 1.5 // Standatd time and a half pay

#define NAME_SIZE 25
#define FIRST_NAME_SIZE 10
#define LAST_NAME_SIZE 10

typedef struct name
{
   const char first_name[FIRST_NAME_SIZE];
   const char last_name[LAST_NAME_SIZE]; 
}name;

typedef struct employee
{
    name emp_name;
    char state [3];
    int clock_number;
    float wage_rate;
    float hours;
    float overtime_hours;
    float overtime_pay;
    float state_tax;
    float fed_tax;
    float gross_pay;
    float net_pay;
}employee;


/**
 * Function: is_overtime()
 * ---------------------------
 *  helper function that determines if the amount of time worked is over
 *  STD_HOURS
 *  @return true if the number of hours is is over STD_HOURS
 **/
bool is_overtime(employee *emp);



/**
 * Function: get_hours()
 * ------------------------
 * fuction that asks the user to input the number of hours worked for
 * a given employee
 */
void get_hours(employee *emp);


/**
 * Function: caculate_pay
 *--------------------------
 * function that calculates the gross pay and updates struct based on hours worked and wage rate.
 * It accounts for overtime hours, applying an overtime rate for hours
 * exceeding STD_HOURS.
 *
 * @param emp Struct pointer to the employe to update
 * @param hours The total number of hours worked by the employee (float).
 * @param wage_rate The employee's hourly wage rate (float).
 *
 * @return float The calculated gross pay.
 */
// float calculate_gross(float hours, float wage_rate);
float calculate_gross(employee *emp, float hours, float wage_rate);

/**
 * Function: caculate_avg
 * ------------------------
 * Caculates the avrage value given an pointer to employee struct.
 *
 * @param arr_emp the array of employee structs to avrage
 * @param len the length of the array
 * 
 * @return the avrage of the array (float)
 */
void calculate_stats(employee *arr_emp, int len);


void snprint_stats(employee *emp, int buf_size);


void print_emp(employee *emp);


void get_full_name(char *buff, employee *emp);


void snprint_emp(employee *emp, int buf_size, bool print_header);


float get_state_tax(employee *emp);


float get_fed_tax(employee *emp);


/**
 * Function: log_employee()
 * ------------------------
 * Logs employee payroll information to a specified file.
 *
 * @param file_ptr A pointer to the FILE object where the data will be written.
 * This file should be opened in write mode ("w") or append mode ("a").
 * @param emp a pointer to the employee struct to be logged
 * 
 * @return void
 */
void log_employee(char *filename, employee *emp);


#endif // EMPLOYEE_H