/***************************************
 * HOMEWORK:    Assignment 7
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-08
 *
 * DESCRIPTION:  Program which determines employee gross pay and outputs to the
 *screen and writes to file. Allows for multiple entries and caulates overtime
 *pay and employee avrages.
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"

// https://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Designated-Inits.html
employee emp[LOT_SIZE] = {
  { { .first_name = "Connie", .last_name = "Cobol" },
    .state_tax = "MA",
    .clock_number = 98401,
    .wage_rate = 10.60 },
  { { .first_name = "Mary ", .last_name = "Apl" },
    .state_tax = "NH",
    .clock_number = 526488,
    .wage_rate = 9.75 },
  { { .first_name = "Frank", .last_name = "Fortran" },
    .state_tax = "VT",
    .clock_number = 765349,
    .wage_rate = 10.50 },
  { { .first_name = "Jeff", .last_name = "Ada" },
    .state_tax = "NY",
    .clock_number = 034645,
    .wage_rate = 12.25 },
  { { .first_name = "Anton", .last_name = "Pascal" },
    .state_tax = "NH",
    .clock_number = 127615,
    .wage_rate = 8.35 },

};

const char *header_str
    = "Name\t\tTax State\tClock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross";

void
print_output ()
{
  printf (
      "\n---------------------------------------------------------------\n");
  printf (
      "Fist Name\tLast Name\t Clock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross");
  printf (
      "\n---------------------------------------------------------------\n");

  // loop
  for (size_t i = 0; i < LOT_SIZE; i++)
    {
      print_emp (&emp[i]);
    } // end for
}

int
main ()
{
  printf ("*********** Pay Calculator ***********\n");

  // start looping
  for (size_t i = 0; i < LOT_SIZE; i++)
    {

      float ot_pay = 0;
      float ot_hr = 0;
      get_hours (&emp[i]);

      if (is_overtime (&emp[i]))
        {
          ot_hr = (emp[i].hours - STD_HOURS);
          ot_pay = (ot_hr * emp[i].wage_rate);
        }

      emp[i].overtime_hours = ot_hr;
      emp[i].overtime_pay = ot_pay;

      calculate_gross (&emp[i], emp[i].hours, emp[i].wage_rate);
      // log to file
      log_employee ("empoyee.log", &emp[i]);

    } // end for

  print_output ();
  caculate_avg (&emp, LOT_SIZE);

  return 0;
} // end main
