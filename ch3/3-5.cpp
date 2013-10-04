// Author: jrjbear@gmail.com
// Date: Sat Oct  5 00:39:55 2013
//
// File: 3-5.cpp
// Description: Convert integer into string of specific base

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "utils/utils.h"


int itob(int n, char s[], int b);

int main(int argc, char* argv[])
{
    const int BUFSIZE = 1024;
    const int MAXVAL = 10000;
    srand(time(NULL));

    char number[BUFSIZE];

    itob(INT_MAX, number, 2);
    printf("itob INT_MAX in binary: %s\n", number);
    itob(INT_MAX, number, 10);
    printf("itob INT_MAX in decimal: %s\n", number);
    itob(INT_MAX, number, 16);
    printf("itob INT_MAX in hexadecimal: %s\n", number);
    
    itob(INT_MIN, number, 2);
    printf("itob INT_MIN in binary: %s\n", number);
    itob(INT_MIN, number, 10);
    printf("itob INT_MIN in decimal: %s\n", number);
    itob(INT_MIN, number, 16);
    printf("itob INT_MIN in hexadecimal: %s\n\n", number);

    for (int i = 0; i < 10; ++i) {
        int n = rand() % MAXVAL;
        int sign = (rand() % 2 > 0? 1: -1);
        int result = n * sign;
        int base = rand() % 8 + 2;

        itob(result, number, base);
        printf("itob(%d) in base %d: %s\n", result, base, number);
        itob(result, number, 16);
        printf("itob(%d) in hexadecimal: %s\n\n", result, number);
    }

    return 0;
}

int itob(int n, char s[], int b)
{
    if (b <= 0 || b > 16) {
        printf("Invalid parameter(b): %d\n", b);
        return -1;
    }

    unsigned int num = (unsigned int)n;
    if (n < 0) {
        // Convert negative number to its opposite one. Note that
        // in 2's complement representation, it is tricky to handle
        // largest negative number because of the limitation on
        // signed value. This problem can be fixed by using unsigned
        // value to fit in the largest negative number.
        num = (unsigned int)~n + 1;
    }

    int i = 0;
    do {
        int remain = num % b;
        if (remain < 10) {
            s[i++] = remain + '0';
        } else {
            s[i++] = remain - 10 + 'A';
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
    reverse(s);
    return 0;
}
