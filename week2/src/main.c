/***************************************
 * HOMEWORK:    Assignment 1
 * 
 * NAME:        Clayton Easley
 * 
 * CLASS:       C Programming, Summer 2025
 * 
 * DATE:        <2025-05-27>
 * 
 * DESCRIPTION: 
 ****************************************/

#include <stdio.h>
#include <stdlib.h>



//FILE *output_ptr; // pointer to output file

int main()
{

    int clockNumber; // employee clock number 
    float gross;     // gross pay for week (wage * hours) 
    float hours;     // number of hours worked per week 
    float wageRate;  // hourly wage 


    printf("\n***** Pay Caculator *****\n");
    printf("\nEnter Your Employee ID:\n");
    scanf("%06d", &clockNumber);
    if(clockNumber < 0)
    {
        printf("[ERROR] your Employee ID cannot be negative");
        return 0;
    }
    printf("%06d", clockNumber);
    printf("\nEnter hours worked:\n");
    scanf("%f", &hours);
    printf("%2.2f\n", hours);    
    return 0;
} // main

