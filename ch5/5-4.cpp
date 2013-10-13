// Author: jrjbear@gmail.com
// Date: Sun Oct 13 11:59:53 2013
//
// File: 5-4.cpp
// Description: Tells whether a string is the suffix of another


#include <string.h>
#include <stdio.h>
#include "utils/utils.h"

int strend(const char* s, const char* t);

int main(int argc, char* argv[])
{
    const int MAXSIZE = 1024;

    char line1[MAXSIZE];
    char line2[MAXSIZE];
    while (true) {
        printf("Input string1: ");
        if (my_getline(line1, MAXSIZE) <= 0) {
            break;
        }
        printf("Input string2: ");
        if (my_getline(line2, MAXSIZE) <= 0) {
            break;
        }
        printf("string2 is%s the suffix of string1\n\n",
               (strend(line1, line2) == 0? " not": ""));
    }

    return 0;
}

int strend(const char* s, const char* t)
{
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);
    int offset = len_s - len_t;

    if (offset >= 0) {
        s += offset;
        while (*s != '\0') {
            if (*s++ != *t++) {
                break;
            }
        }
        if (*s == '\0') {
            return 1;
        }
    }
    return 0;
}
