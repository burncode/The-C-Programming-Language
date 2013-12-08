// Author: jrjbear@gmail.com
// Date: Wed Oct  2 20:34:27 2013
//
// File: utils.cpp
// Description: 

#include <stdio.h>
#include <string.h>

int my_getline(char s[], int lim)
{
    if (lim <= 1) {
        return 0;
    }

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

void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
