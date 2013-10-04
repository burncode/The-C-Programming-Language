// Author: jrjbear@gmail.com
// Date: Sat Oct  5 00:47:06 2013
//
// File: 3-6.cpp
// Description: Convert integer to string padding to required width


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "utils/utils.h"

void itoa(int n, char s[], int width);

int main(int argc, char* argv[])
{
    const int BUFSIZE = 1024;
    const int MAXVAL = 1024;
    srand(time(NULL));

    char number[BUFSIZE];
    for (int i = 0; i < 10; ++i) {
        int n = rand() % MAXVAL;
        int sign = (rand() % 2 > 0? 1: -1);
        int width = rand() % 8 + 2;
        itoa(n * sign, number, width);
        printf("itoa(%d) in minimum width(%d):\n%s\n", 
               n * sign, width, number);
    }    

    return 0;
}

void itoa(int n, char s[], int width)
{
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
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (n < 0) {
        s[i++] = '-';
    }
    while (i < width) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
