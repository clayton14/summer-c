/***************************************
 * HOMEWORK:    Assignment 9
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-26
 *
 * DESCRIPTION:  Program which determines employee gross pay and outputs to the
 *screen and writes to file. Allows for multiple entries and caulates overtime
 *pay and employee avrages.
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "stats.h"

#define PRINT_BUF_SIZE 1024

employee emp[LOT_SIZE] = {
  { { .first_name = "Connie", .last_name = "Cobol" },
    .state = "MA",
    .clock_number = 98401,
    .wage_rate = 10.60 },
  { { .first_name = "Mary ", .last_name = "Apl" },
    .state = "NH",
    .clock_number = 526488,
    .wage_rate = 9.75 },
  { { .first_name = "Frank", .last_name = "Fortran" },
    .state = "VT",
    .clock_number = 765349,
    .wage_rate = 10.50 },
  { { .first_name = "Jeff", .last_name = "Ada" },
    .state = "NY",
    .clock_number = 034645,
    .wage_rate = 12.25 },
  { { .first_name = "Anton", .last_name = "Pascal" },
    .state = "CA",
    .clock_number = 127615,
    .wage_rate = 8.35 },
};

const char *header_str
    = "Name\t\tTax State\tClock#\tWage\tHours\tOT Hours\tOT Pay\t\tGross";

void print_output ()
{
 
  bool headder_printed = false;
  if (!headder_printed)
  {
      // TODO: use snrintf
    printf (
        "\n------------------------------------------------------------------------------------------------------------------------\n");
    printf (
        "Name\t\tClock#\tWage\tHours\tOT Hours\tOT Pay\tGross Pay\tState Tax\tFed Tax\t\tNet Pay");
    printf (
        "\n------------------------------------------------------------------------------------------------------------------------\n");
  }
  headder_printed = true;

  // loop
  for (size_t i = 0; i < LOT_SIZE; i++)
    {
      //print_emp (&emp[i]);
      snprint_emp(&emp[i],  1024, headder_printed);
    } // end for
}


int main ()
{

  printf ("*********** Pay Calculator ***********\n");

  //start looping
  for (size_t i = 0; i < LOT_SIZE; i++)
    {

      float ot_pay = 0;
      float ot_hr = 0;
      get_hours (&emp[i]);

      // caculate overtime
      if (is_overtime (&emp[i]))
        {
          ot_hr = (emp[i].hours - STD_HOURS);
          ot_pay = (ot_hr * emp[i].wage_rate);
        }

      emp[i].overtime_hours = ot_hr;
      emp[i].overtime_pay = ot_pay;

     // caculate  gross pay
     calculate_gross (&emp[i], emp[i].hours, emp[i].wage_rate);
      
     // Caulate fed and state tax for employee at i-th index
     float stax = (get_state_tax(&emp[i]) * emp[i].gross_pay);
     float ftax = (FED_TAX_RATE * emp[i].gross_pay);
     emp[i].net_pay = emp[i].gross_pay - (stax + ftax);

     emp[i].state_tax = stax;
     emp[i].fed_tax = ftax;


      // log to file
      //log_employee ("empoyee.log", &emp[i]);

    } // end for

  print_output();
  calculate_stats (&emp, LOT_SIZE);


  return 0;
} // end main
