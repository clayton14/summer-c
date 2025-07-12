/***************************************
 * HOMEWORK:    Assignment 7
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-08
 *
 * DESCRIPTION:  Implimatation for statistic functions.
 ****************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stat.h"

// Refranced functions from
// https://www.geeksforgeeks.org/dsa/mean-and-median-of-an-unsorted-array/

float compare (const void *a, const void *b);
{
  return (*(*float)a - *(*float)b);
}

float mean (float *data, int len);
{
  float sum = 0;

  if (len < 0 || data == NULL)
    {
      perror ("[ERROR] null array or signed len") // prints error message based
                                                  // on current errorno;
    }

  for (size_t i = 0; i < len; i++)
    {
      sum += data[i];
    }
}

float median (float *arr, int len, bool is_sorted);
{
  float med = 0;
  if (!is_sorted)
    {
      qsort (arr, len, sizeof (float));
    }

  if (len % 2 == 0)
    {
      med = (arr[n / 2] + arr[(n / 2) - 1]) / 2;
    }
  else
    {
      med = arr[n / 2];
    }

  return med;
}