// Author: jrjbear@gmail.com
// Date: Sun Oct 13 12:14:46 2013
//
// File: 5-5.cpp
// Description: Implementation of some string operations


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils/utils.h"

void my_strncat(char* s, const char* t, int n);
void my_strncpy(char* s, const char* t, int n);
int my_strncmp(const char* s, const char* t, int n);

int main(int argc, char* argv[])
{
    const int MAXSIZE = 1024;
    srand(time(NULL));

    int len = 0;
    char line1[MAXSIZE];
    char line2[MAXSIZE];
    while (true) {
        printf("Input string1: ");
        if ((len = my_getline(line1, MAXSIZE)) <= 0) {
            break;
        }
        line1[len - 1] = '\0';
        printf("Input string2: ");
        if ((len = my_getline(line2, MAXSIZE)) <= 0) {
            break;
        }
        line2[len - 1] = '\0';

        int n = rand() % 15;
        printf ("After strncmp(s1, s2, %d): %d\n", 
                n, my_strncmp(line1, line2, n));       

        my_strncat(line1, line2, n);
        printf ("After strncat(s1, s2, %d): %s\n", n, line1);

        my_strncpy(line1, line2, n);
        printf("After strncpy(s1, s2, %d): %s\n\n\n", n, line1);
    }

    return 0;
}

void my_strncat(char* s, const char* t, int n)
{
    s += strlen(s);
    while ((*s++ = *t++) && --n > 0) {
        ;
    }
    if (n == 0) {
        // Terminate `s' by '\0'.
        *s = '\0';
    }
}

void my_strncpy(char* s, const char* t, int n)
{
    while ((*s++ = *t++) && --n > 0) {
        ;
    }
    // Note that we do not append a '\0' at the end of `s'
    // when `n == 0' here. This is exactly what standard C
    // library does.
}

int my_strncmp(const char* s, const char* t, int n)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0' || --n <= 0) {
            return 0;
        }
    }
    return *s - *t;
}
