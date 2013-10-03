// Author: jrjbear@gmail.com
// Date: Wed Oct  2 20:34:27 2013
//
// File: utils.cpp
// Description: 

#include <stdio.h>

int my_getline(char s[], int lim)
{
    int i = 0;
    int c = -1;

    // Make sure `i < lim - 1' so as to leave at least one space for '\0'.
    while (i < lim - 1 && c != '\n') {
        c = getchar();
        if (c == EOF) {
            break;
        }
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
