/***************************************
 * HOMEWORK:    Assignment 7
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-08
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

bool
is_overtime (employee *emp)
{
  if (emp->hours > STD_HOURS)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void
get_hours (employee *emp)
{
  float hr = 0;
  if (emp != NULL)
    {
      printf ("\n [ID: %06d] Enter hours worked: ", emp->clock_number);
      scanf ("%f", &hr);
      if (hr < 0)
        {
          printf ("[ERROR] value cannot be negative entry terminated\n");
          hr = 0.0;
        }
      emp->hours = hr;
    }
}

float
calculate_gross (employee *emp, float hours, float wage_rate)
{
  float gross = 0;
  if (emp != NULL)
    {
      if (is_overtime (emp))
        {
          float overtime_hours = hours - STD_HOURS;
          float overtime_pay = ((wage_rate * STD_OVERTIME) * overtime_hours);
          gross = (wage_rate * (hours - overtime_hours)) + overtime_pay;
        }
      else
        {
          gross = wage_rate * hours;
        }

      emp->gross_pay = gross;
    }

  return gross;
}

void
caculate_avg (employee *arr_emp, int len)
{
  // Dynamically allocate array
  float *avg = (float *)calloc (len, sizeof (float));

  if (len <= 0)
    {
      return 0.0f;
    }

  for (size_t i = 0; i < len; i++)
    {
      avg[0] += arr_emp[i].wage_rate;
      avg[1] += arr_emp[i].hours;
      avg[2] += arr_emp[i].overtime_hours;
      avg[3] += arr_emp[i].overtime_pay;
      avg[4] += arr_emp[i].gross_pay;
    }

  printf (
      "\n---------------------------------------------------------------\n");

  printf ("Avg:\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f\t\t%2.2f\n", avg[0] / len,
          avg[1] / len, avg[2] / len, avg[3] / len, avg[4] / len);
}

void
print_emp (employee *emp)
{
  printf ("%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\n", emp->clock_number,
          emp->wage_rate, emp->hours, emp->overtime_hours, emp->overtime_pay,
          emp->gross_pay);
}

void
log_employee (char *filename, employee *emp)
{
  FILE *output;
  if ((output = fopen (filename, "a")) == (FILE *)NULL)
    {
      fprintf (stderr, "[ERROR] Unable to open file employee.log\n");
    }
  fprintf (output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\n",
           emp->clock_number, emp->wage_rate, emp->hours, emp->overtime_hours,
           emp->overtime_pay, emp->gross_pay);

  fclose (output);
}
