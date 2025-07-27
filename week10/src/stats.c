/***************************************
 * HOMEWORK:    Assignment 8
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-20
 *
 * DESCRIPTION:  Implimatation for statistic functions.
 ****************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stats.h"

// Refranced functions from
// https://www.geeksforgeeks.org/dsa/mean-and-median-of-an-unsorted-array/

float compare (const void *a, const void *b)
{
  return (*(float*)a - *(float*)b);
}

float mean (float *data, int len)
{
  float sum = 0;

  if (len < 0 || data == NULL)
    {
      perror ("[ERROR] null array or signed len"); // prints error message based
                                                  // on current errorno;
      return -1;
    }

  for (size_t i = 0; i < len; i++)
    {
      printf("data %f\n", data[i]);
      sum += data[i];
    }
    printf("sum %f, len %d, avg %f\n", sum, len, sum/len);
   return sum / len;
}

float median (float *arr, int len, bool is_sorted)
{
  float med = 0;
  if (!is_sorted)
    {
      qsort (arr, len, sizeof (float), compare);
    }

  if (len % 2 == 0)
    {
      med = (arr[len / 2] + arr[(len / 2) - 1]) / 2;
    }
  else
    {
      med = arr[len / 2];
    }

  return med;
}


float get_min(float *data, int len)
{
    if(len < 0)
    {
        return -1;
    }

    float current_min = data[0];

    for(int i = 0; i < len; i++)
    {
        if (data[i] < current_min)
        {
            current_min = data[i];
        }
    }

    return current_min;

}

float get_max(float *data, int len)
{
    if(len < 0)
    {
        return -1;
    }

    float current_max = data[0];

    for(int i = 0; i < len; i++)
    {
        if (data[i] > current_max)
        {
            current_max = data[i];
        }
    }

    return current_max;
}
