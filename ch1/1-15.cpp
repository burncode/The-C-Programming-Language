/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-15.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

float fahr_to_celsius (float fahr);

int main ()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf ("%3s %6s\n", "^F", "^C");
    while (fahr <= upper) {
        printf ("%3.0f %6.1f\n", fahr, 
                fahr_to_celsius (fahr));
        fahr = fahr + step;
    }
}

float fahr_to_celsius (float fahr) 
{ return (5.0 / 9.0) * (fahr - 32); }
