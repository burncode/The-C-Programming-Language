// Author: jrjbear@gmail.com
// Date: Fri Oct  4 23:51:52 2013
//
// File: 3-3.cpp
// Description: Expand '-' abbreviation


#include <stdio.h>
#include <ctype.h>
#include "utils/utils.h"

int expand(const char src[], char dst[]);

int main(int argc, char* argv[])
{
    const int BUFSIZE = 1024;

    char buf[BUFSIZE];
    char line[BUFSIZE];
    while (my_getline(line, BUFSIZE) > 0) {
        expand(line, buf);
        printf("After expand: %s\n", buf);
    }

    return 0;
}

int expand(const char src[], char dst[])
{
    // `begin' marks the letter on the left side of '-',
    // while `end' marks the letter on the right side.
    char begin = '\0';
    char end = '\0';
    int offset = 0;
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == '-') {
            end = src[i + 1];
            if (begin < end) {
                if (islower(begin) && islower(end) 
                    || isupper(begin) && isupper(end) 
                    || isdigit(begin) && isdigit(end)) {
                    for (int j = 1; begin + j <= end; ++j) {
                        dst[offset++] = begin + j;
                    }
                    begin = '\0';
                    ++i;
                    continue;
                }
            }
        }
        dst[offset++] = src[i];
        begin = src[i];
    }
    dst[offset] = '\0';
    return 0;
}
