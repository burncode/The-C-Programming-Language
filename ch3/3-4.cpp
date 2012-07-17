/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--30                                                   **
 *                                                                      **
 * File: 3-4.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "utils.h"

#define BUFSIZE 1024

void itoa (int n, char s[]);

int main ()
{
    srand (time (NULL));

    char number[BUFSIZE];
    
    itoa (INT_MAX, number);
    printf ("itoa INT_MAX: %s\n", number);
    itoa (INT_MIN, number);
    printf ("itoa INT_MIN: %s\n", number);

    for (int i = 0; i < 10; ++i) {
        int n = rand () % INT_MAX;
        int sign = (rand () % 2 > 0? 1: -1);

        itoa (n * sign, number);
        printf ("itoa (%d): %s\n", n * sign, number);
    }    

    return 0;
}

void itoa (int n, char s[])
{
    int i;
    unsigned int num;

    if (n < 0) {
        // Convert negative integer into postive,
        // and then put it into unsigned int
        // so that even the largest negative integer
        // can fit in.
        // Note that we assume that the number is
        // represented in two's complement.
        num = (unsigned int) ~n	+ 1;
    } else {
        num = (unsigned int) n;
    }

    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (n < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse (s);
}
