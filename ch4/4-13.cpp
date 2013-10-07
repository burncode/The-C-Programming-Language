// Author: jrjbear@gmail.com
// Date: Mon Oct  7 19:29:48 2013
//
// File: 4-13.cpp
// Description: Reverse a string using recursive way


#include <stdio.h>
#include <string.h>
#include "utils/utils.h"

void my_reverse(char s[]);

int main(int argc, char* argv[])
{
    const int MAXSIZE = 1024;

    int len = 0;
    char line[MAXSIZE];
    while ((len = my_getline(line, MAXSIZE)) > 0) {
        line[len - 1] = '\0';
        my_reverse(line);
        printf("After reverse: %s\n\n", line);
    }

    return 0;
}

void my_reverse(char s[])
{
    size_t len = strlen(s);
    if (len > 1) {
        reverse(s + 1);
    } else if (len == 0) {
        return;
    }
    
    char first = s[0];
    for (size_t i = 0; i < len - 1; ++i) {
        s[i] = s[i + 1];
    }
    s[len - 1] = first;
}

