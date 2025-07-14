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
#include <string.h>

#include "employee.h"
#include "stats.h"

bool is_overtime(employee *emp)
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

void get_hours(employee *emp)
{
  float hr = 0;
  if (emp != NULL)
  {
    printf("\n [ID: %06d] Enter hours worked: ", emp->clock_number);
    scanf("%f", &hr);
    if (hr < 0)
    {
      printf("[ERROR] value cannot be negative entry terminated\n");
      hr = 0.0;
    }
    emp->hours = hr;
  }
}

float calculate_gross(employee *emp, float hours, float wage_rate)
{
  float gross = 0;
  if (emp != NULL)
  {
    if (is_overtime(emp))
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

void caculate_stats(employee *arr_emp, int len)
{
  // Dynamically allocate array
  float *avg = (float *)calloc(len, sizeof(float));

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
    avg[5] += arr_emp[i].state_tax;
    avg[6] += arr_emp[i].fed_tax;
    avg[7] += arr_emp[i].net_pay;
  }

  printf(
      "\n---------------------------------------------------------------\n");

  printf("Avg:\t\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f\t\t%2.2f\t%2.2f\n", avg[0] / len,
         avg[1] / len, avg[2] / len, avg[3] / len, avg[4] / len, avg[5] / len);
}

void print_emp(employee *emp)
{

  char name_buf[NAME_SIZE];
  snprintf(&name_buf, NAME_SIZE, "%s %s", emp->emp_name.first_name, emp->emp_name.last_name); 

  printf("%s\t%06d\t%2.2f\t%2.2f\t%2.2f\t\t+%2.2f\t\t%2.2f\t\t%2.2f\t\t%2.2f\t%2.2f\n", name_buf, emp->clock_number,
         emp->wage_rate, emp->hours, emp->overtime_hours, emp->overtime_pay,
         emp->gross_pay, emp->state_tax, emp->fed_tax, emp->net_pay);
}

void snprint_emp(employee *emp, int buf_size, bool print_header)
{

  char buf[buf_size];

  // name bufer
  char name_buf[NAME_SIZE];
  snprintf(&name_buf, NAME_SIZE, "%s %s", emp->emp_name.first_name, emp->emp_name.last_name);

  int wirtten_bytes = 0;

  // Add names and clock number
  wirtten_bytes += snprintf(buf + wirtten_bytes, sizeof(buf) - wirtten_bytes,
                            "%s\t%06d", name_buf, emp->clock_number);

  // Wage and hours
  wirtten_bytes += snprintf(buf + wirtten_bytes, sizeof(buf) - wirtten_bytes,
                            "\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f",
                            emp->wage_rate, emp->hours,
                            emp->overtime_hours, emp->overtime_pay);

  // Pay and taxes
  wirtten_bytes += snprintf(buf + wirtten_bytes, sizeof(buf) - wirtten_bytes,
                        "\t%2.2f\t\t%2.2f\t\t%2.2f\t\t%2.2f",
                        emp->gross_pay, emp->state_tax, 
                        emp->fed_tax, emp->net_pay);
  
  // end row with newline
  wirtten_bytes += snprintf(buf + wirtten_bytes, sizeof(buf) - wirtten_bytes,
                            "\n");


    printf("%s", buf);
}

void log_employee(char *filename, employee *emp)
{
  FILE *output;
  if ((output = fopen(filename, "a")) == (FILE *)NULL)
  {
    fprintf(stderr, "[ERROR] Unable to open file employee.log\n");
  }
  fprintf(output, "%06d\t%2.2f\t%2.2f\t%2.2f\t+%2.2f\t\t%2.2f\t%2.2f\t\t%2.2f\n",
          emp->clock_number, emp->wage_rate, emp->hours, emp->overtime_hours,
          emp->overtime_pay, emp->gross_pay);

  fclose(output);
}

void print_name(employee *emp)
{
  char buff[NAME_SIZE] = "";

  if (emp == NULL)
  {
    printf("Employee is NULL");
    return;
  }

  // printf("Names %s\n", emp->emp_name.first_name);
  strcat(buff, emp->emp_name.first_name);
  strcat(buff, " ");
  strcat(buff, emp->emp_name.last_name);

  printf("%s\n", buff);
}

float get_state_tax(employee *emp)
{

  if (emp == NULL)
  {
    perror("Employee is NULL");
    return -1;
  }

  if (strcmp(emp->state, "MA") == 0)
  {
    return MA_TAX_RATE;
  }
  else if (strcmp(emp->state, "NH") == 0)
  {
    return NH_TAX_RATE;
  }
  else if (strcmp(emp->state, "VT") == 0)
  {
    return VT_TAX_RATE;
  }
  else if (strcmp(emp->state, "CA") == 0)
  {
    return CA_TAX_RATE;
  }
  else
  {
    return DEFAULT_TAX_RATE;
  }
}