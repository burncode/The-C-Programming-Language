/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--30                                                   **
 *                                                                      **
 * File: 3-5.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "utils.h"

#define BUFSIZE 1024

int itob (int n, char s[], int b);

int main ()
{
    srand (time (NULL));

    char number[BUFSIZE];

    itob (INT_MAX, number, 2);
    printf ("itob INT_MAX in binary: %s\n", number);
    itob (INT_MAX, number, 10);
    printf ("itob INT_MAX in decimal: %s\n", number);
    itob (INT_MAX, number, 16);
    printf ("itob INT_MAX in hexadecimal: %s\n", number);
    
    itob (INT_MIN, number, 2);
    printf ("itob INT_MIN in binary: %s\n", number);
    itob (INT_MIN, number, 10);
    printf ("itob INT_MIN in decimal: %s\n", number);
    itob (INT_MIN, number, 16);
    printf ("itob INT_MIN in hexadecimal: %s\n\n", number);

    for (int i = 0; i < 10; ++i) {
        int n = rand () % INT_MAX;
        int sign = (rand () % 2 > 0? 1: -1);
        int result = n * sign;
        int base = rand () % 8 + 2;

        itob (result, number, base);
        printf ("itob (%d) in base %d: %s\n", 
                result, base, number);

        itob (result, number, 16);
        printf ("itob (%d) in hexadecimal: %s\n\n", 
                result, number);
    }

    return 0;
}

int itob (int n, char s[], int b)
{
    int i, r;
    unsigned int num;

    if (b <= 0 || b > 16) {
        return -1;
    }

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
        r = num % b;
        if (r < 10) {
            s[i++] = r + '0';
        } else {
            s[i++] = r - 10 + 'A';
        }
    } while ((num /= b) > 0);

    if (b > 10) {
        s[i++] = 'x';
        s[i++] = '0';
    }

    if (n < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse (s);
}
