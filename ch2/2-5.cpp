// Author: jrjbear@gmail.com
// Date: Fri Oct  4 17:12:34 2013
//
// File: 2-5.cpp
// Description: Search a string for any character in a pattern

#include <stdio.h>
#include <string.h>
#include "utils/utils.h"


int any(const char buf[], const char pattern[]);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;

    char line[MAXLINE];
    char pattern[MAXLINE];
    while (true) {
        printf("Input source string: ");
        if (my_getline(line, MAXLINE) <= 0) {
            break;
        }
        printf("Input pattern: ");
        if (my_getline(pattern, MAXLINE) <= 0) {
            break;
        }
        int idx = any(line, pattern);
        if (idx < 0) { 
            printf("Not found\n");
        } else {
            printf("Find character at position: %d\n\n", idx);
        }
    }

    return 0;
}

int any(const char buf[], const char pattern[])
{
    // Bitmap used to record characters, starts from 0 which
    // means the first bit in bitmap represents 0.
    static const int SIZE = 256;
    static char bitmap[(SIZE + 7) / 8];

    memset(bitmap, 0, sizeof(bitmap));
    for (int i = 0; pattern[i] != '\0'; i++) {
        unsigned char c = pattern[i];
        bitmap[c / 8] |= (1 << c % 8);
    }

    for (int i = 0; buf[i] != '\0'; i++) {
        unsigned char c = buf[i];
        if (bitmap[c / 8] & (1 << c % 8)) {
            return i;
        }
    }
    return -1;
}
