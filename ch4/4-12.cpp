// Author: jrjbear@gmail.com
// Date: Mon Oct  7 19:18:40 2013
//
// File: 4-12.cpp
// Description: Convert integer to string


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

// This function returns the number of digits of n.
int itoa(int n, char s[]);

int main(int argc, char* argv[])
{
    const int BUFSIZE = 1024;
    const int MAXVAL = 10000;
    srand(time(NULL));
    
    char number[BUFSIZE];

    itoa(INT_MAX, number);
    printf("itoa INT_MAX: %s\n", number);
    itoa(INT_MIN, number);
    printf("itoa INT_MIN: %s\n", number);

    for (int i = 0; i < 10; ++i) {
        int n = rand() % MAXVAL;
        int sign = (rand() % 2 > 0? 1: -1);
        itoa(n * sign, number);
        printf("itoa(%d): %s\n", n * sign, number);
    }   

    return 0;
}

int itoa(int n, char s[])
{
    unsigned int num = (unsigned int)n;
    if (n < 0) {
        // Convert negative number to its opposite one. Note that
        // in 2's complement representation, it is tricky to handle
        // largest negative number because of the limitation on
        // signed value. This problem can be fixed by using unsigned
        // value to fit in the largest negative number.
        num = (unsigned int)~n + 1;
        s[0] = '-';
        s++;
    }

    int dight_num = 1;
    if (num / 10 > 0) {
        dight_num = itoa(num / 10, s) + 1;
    } 

    s[dight_num - 1] = num % 10 + '0';
    s[dight_num] = '\0';
    return dight_num;
}
