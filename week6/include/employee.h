/***************************************
 * HOMEWORK:    Assignment 5
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-25>
 *
 * DESCRIPTION:  Header file for emplyee strcture
 * 
 ****************************************/


#define STD_HOURS 40.0      // Standard weekely hours before overtime.
#define LOT_SIZE 5          // Default number of employee to enter into the system.
#define STD_OVERTIME 1.5    // Standatd time and a half pay


float caculate_pay();


void write_to_file();


/**
 * Function: display_output()
 * ---------------------------
 *  Displays table of employee data to stdout
 *  @param num_entries the number of entries to display to stdout
 **/ 
void display_output(int num_entries);

int get_utc_time();
