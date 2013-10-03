// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:53:43 2013
//
// File: 1-9.cpp
// Description: Delete successive blanks

#include <stdio.h>

int main(int argc, char* argv[])
{
    int c = -1;
    int lastc = -1;

    while ((c = getchar()) != EOF) { 
        if (lastc == ' ' && c == ' ') {
            continue;
        } else {
            putchar(c);
            lastc = c;
        }
    }

    return 0;
}
