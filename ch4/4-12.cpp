/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--17                                                   **
 *                                                                      **
 * File: 4-12.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define BUFSIZE 1024

// This function returns the bits of n.
int itoa (int n, char s[]);

int main()
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

int itoa (int n, char s[])
{
    unsigned int num;
    int bits;

    if (n < 0) {
        // Convert negative integer into postive,
        // and then put it into unsigned int
        // so that even the largest negative integer
        // can fit in.
        // Note that we assume that the number is
        // represented in two's complement.
        num = (unsigned int) ~n + 1;
        s[0] = '-';
        s++;
    } else {
        num = (unsigned int) n;
    }

    if (num / 10 > 0) {
        bits = itoa (num / 10, s);
    } else {
        bits = 0;
    }

    s[bits] = num % 10 + '0';
    s[bits + 1] = '\0';
    
    return bits + 1;
}
