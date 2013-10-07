// Author: jrjbear@gmail.com
// Date: Thu Oct  3 22:58:24 2013
//
// File: 2-4.cpp
// Description: Filter a string through a pattern


#include <stdio.h>
#include <string.h>
#include "utils/utils.h"

void squeeze(char buf[], const char pattern[]);

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
        printf("Input filter patter: ");
        if (my_getline(pattern, MAXLINE) <= 0) {
            break;
        }
        squeeze(line, pattern);
        printf("After squeeze: %s\n\n", line);
    }

    return 0;
}

void squeeze(char buf[], const char pattern[])
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

    int offset = 0;
    for (int i = 0; buf[i] != '\0'; i++) {
        unsigned char c = buf[i];
        if (!(bitmap[c / 8] & (1 << c % 8))) {
            buf[offset++] = buf[i];
        }
    }
    buf[offset] = '\0';
}
