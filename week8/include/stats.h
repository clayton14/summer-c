/***************************************
 * HOMEWORK:    Assignment 7
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        2025-07-08
 *
 * DESCRIPTION:  headder containing statistic functions definitions
 *
 ****************************************/

#ifndef STATS_H
#define STATS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Refranced functions from https://www.geeksforgeeks.org/dsa/mean-and-median-of-an-unsorted-array/


/**
 * Function: compare
 *--------------------------
 * comparison function intended for use with sorting
 * functions like `qsort`. It compares two elements, 'a' and 'b'.
 * 
 *
 * @param a A const void pointer to the first element.
 * @param b A const void pointer to the second element.
 *
 * @return float An float less than, equal to, or greater than zero if 'a' is
 * found to be less than, to match, or be greater than 'b', respectively.
 */
float compare(const void* a, const void* b);


/**
 * Function: mean
 *--------------------------
 * Calculates the arithmetic mean (average) of a given array of floating-point numbers.
 * It assumes a fixed-size array
 *
 * @param data An array of floats for which to calculate the mean.
 *
 * @return float The arithmetic mean of the elements in the data array.
 */
float mean(float data[]);

/**
 * Function: median
 *--------------------------
 * Calculates the median value of an array of floating-point numbers.
 * For the median to be correct, the input array MUST be sorted.
 *
 * @param arr A pointer to a sorted array of floats.
 * @param len The total number of elements in the array.
 * @param is_sorted Flag that skips in function sorting if array is sorted.
 * 
 * @return float The median value of the elements in the array.
 */
float median(float *arr, int len, bool is_sorted);

/**
 * Function: std_dev
 *--------------------------
 * Calculates the population standard deviation of a given array of floating-point
 * numbers. 
 *
 * @param data An array of floats for which to calculate the standard deviation.
 *
 * @return float The population standard deviation of the elements in the data array.
 */
float std_dev(float data[]);






#endif //STATS_H