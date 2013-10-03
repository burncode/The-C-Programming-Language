// Author: jrjbear@gmail.com
// Date: Thu Oct  3 00:42:11 2013
//
// File: 1-10.cpp
// Description: Print escape character

#include <stdio.h>

int main(int argc, char* argv[])
{
    int c = -1;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }

    return 0;
}
