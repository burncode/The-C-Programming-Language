// Author: jrjbear@gmail.com
// Date: Fri Oct  4 18:48:25 2013
//
// File: 2-10.cpp
// Description: Implement `lower' using conditional expression


#include <stdio.h>

int lower(int c)
{ return (c >= 'A' && c <= 'Z')? c - 'A' + 'a': c; }

int main(int argc, char* argv[])
{
    char c = '\0';
    while (true) {
        printf("Input a character: ");
        if (scanf ("%c", &c) != 1) {
            break;
        }
        if (c == '\n') {
            continue;
        }
        printf ("lower(%c) is %c\n\n", c, lower(c));
    }

    return 0;
}
