/***************************************
 * HOMEWORK:    Assignment 8
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-20
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




void calculate_stats(employee *emp, int len)
{
  // Dynamically allocate array

  // get min and max 

  // get mean and median

 if (len <= 0)
  {
    return 0.0f;
  }

  float *wage_rates = (float *)calloc(len + 1, sizeof(float));
  float *hours = (float *)calloc(len + 1, sizeof(float));
  float *overtime_hours = (float *)calloc(len + 1, sizeof(float));
  float *overtime_pays = (float *)calloc(len + 1, sizeof(float));
  float *state_taxes = (float *)calloc(len + 1, sizeof(float));
  float *fed_taxes = (float *)calloc(len + 1, sizeof(float));
  float *gross_pays = (float *)calloc(len + 1, sizeof(float));
  float *net_pays = (float *)calloc(len + 1, sizeof(float));

  // coppy data

  for (size_t i = 0; i < len; i++)
  {
    wage_rates[i] = emp[i].wage_rate;
    hours[i] = emp[i].hours;
    overtime_hours[i] = emp[i].overtime_hours;
    overtime_pays[i] = emp[i].overtime_pay;
    state_taxes[i] = emp[i].state_tax;
    fed_taxes[i] = emp[i].fed_tax;
    gross_pays[i] = emp[i].gross_pay;
    net_pays[i] = emp[i].net_pay;

  }

/*
for i = 0 to num oeioke
add array[i] to last element of array, calloc one extra spoace
fpor ever array


*/

  
//calculating totals and putting them at the end of the arrays
for (int i= 0; i<len; i++)
{
  wage_rates[len] += wage_rates[i];
  hours[len] += hours[i];
  overtime_hours[len] += overtime_hours[i];
  overtime_pays[len] += overtime_pays[i];
  gross_pays[len] += gross_pays[i];
  state_taxes[len] += state_taxes[i];
  fed_taxes[len] += fed_taxes[i];
  net_pays[len] += net_pays[i];
}

  printf(
      "\n------------------------------------------------------------------------------------------------------------------------\n");

  printf("Totals: \t\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f\t%2.2f\t\t%2.2f\t\t%2.2f\t\t%2.2f\n", wage_rates[len], hours[len], overtime_hours[len],
  overtime_pays[len], gross_pays[len], state_taxes[len], fed_taxes[len], net_pays[len]);
    
  printf("Averages: \t\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f\t%2.2f\t\t%2.2f\t\t%2.2f\t\t%2.2f\n", wage_rates[len]/len, hours[len]/len, 
  overtime_hours[len]/len, overtime_pays[len]/len, gross_pays[len]/len, state_taxes[len]/len, fed_taxes[len]/len, net_pays[len]/len);

  printf("Minimum: \t\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f\t%2.2f\t\t%2.2f\t\t%2.2f\t\t%2.2f\n", get_min(wage_rates, len), get_min(hours, len),
  get_min(overtime_hours, len), get_min(overtime_pays, len), get_min(gross_pays, len), get_min(state_taxes, len), 
  get_min(fed_taxes, len), get_min(net_pays, len));

  printf("Maximum: \t\t%2.2f\t%2.2f\t%2.2f\t\t%2.2f\t%2.2f\t\t%2.2f\t\t%2.2f\t\t%2.2f\n", get_max(wage_rates, len), get_max(hours, len),
  get_max(overtime_hours, len), get_max(overtime_pays, len), get_max(gross_pays, len), get_max(state_taxes, len), 
  get_max(fed_taxes, len), get_max(net_pays, len));


  free(wage_rates);
  free(hours);
  free(overtime_hours);
  free(overtime_pays);
  free(state_taxes);
  free(fed_taxes);
  free(gross_pays);
  free(net_pays);


  

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