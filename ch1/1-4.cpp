/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-4.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

int main ()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 180;
    step = 10;

    celsius = lower;
    printf ("%4s %6s\n", "^F", "^C");
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf ("%4.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
