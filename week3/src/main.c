/***************************************
 * HOMEWORK:    Assignment 2
 *
 * NAME:        Clayton Easley
 *
 * CLASS:       C Programming, Summer 2025
 *
 * DATE:        <2025-06-02>
 *
 * DESCRIPTION:  Program which determines gross pay and outputs to the screen
 * and writes to file. Allows for multiple entries.
 ****************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int clockNumber; // employee clock number
    int numEmployees;
    float gross;    // gross pay for week (wage * hours)
    float hours;    // number of hours worked per week
    float wageRate; // hourly wage

    FILE *output; // pointer to the output file

    // taken from example
    // Open file in append mode
    if ((output = fopen("home.txt", "a")) == (FILE *)NULL) // why cast type to NULL pointer ?
    {
        fprintf(stderr, "[ERROR] Unable to open file home.txt\n");
        return -1;
    }

    fprintf(output, "\n***** Pay Caculator *****\n");

    //add headder to home.txt
    fprintf(output, "Clock#\tWage\tHours\t\tGross");
    fprintf(output, "\n---------------------------------------------\n");
    
    
    printf("\nHow many entries are you entering: ");
    scanf("%d", &numEmployees);

    if(numEmployees < 0)
    {
        printf("[ERROR] value cannot be negative\n");
        return -1; // return -1 if an error occurs
    }

    // start looping
    for (size_t i = 0; i < numEmployees; i++)
    {
        printf("\n***** Pay Caculator *****\n");
        printf("\nEnter Your Employee ID: ");
        scanf("%d", &clockNumber);

        printf("\nEnter hourly wage: ");
        scanf("%f", &wageRate);

        printf("\nEnter hours worked: ");
        scanf("%f", &hours);

        if ((clockNumber < 0) || (wageRate < 0) || (hours < 0) || (numEmployees < 0))
        {
            printf("[ERROR] value cannot be negative entry terminated\n");
            continue; // continue program although error has occured.
        }

        // calculate gross pay
        gross = wageRate * hours;

        // print to screen
        printf("\n---------------------------------------------\n");
        printf("Clock#\tWage\tHours\t\tGross");
        printf("\n---------------------------------------------\n");
        printf("%06d\t%2.2f\t%2.2f\t\t%2.2f\n", clockNumber, wageRate, hours, gross);

        // write to file
        //fprintf(output, "\n---------------------------------------------\n");
        fprintf(output, "%06d\t%2.2f\t%2.2f\t\t%2.2f\n", clockNumber, wageRate, hours, gross);
    } // for numEmployees
    fclose(output); // close the file
    return 0;
} // main
