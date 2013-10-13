// Author: jrjbear@gmail.com
// Date: Sun Oct 13 09:49:27 2013
//
// File: 5-1.cpp
// Description: Get an integer from standard input


#include <ctype.h>
#include <stdio.h>

// Returns 0 if it's not an integer. Otherwise returns the next character
// right after the integer, and this character will be pushed back to
// standard input.
int getint(int* pn);

int main(int argc, char* argv[])
{
    int ret = 0;
    int val = 0;
    int count = 0;
    do {
        ret = getint(&val);
        if (ret > 0) {
            count++;
            printf("val%d = %d\n", count, val);
        } else {
            ret = getchar();
        }
    } while (ret != EOF);

    return 0;
}

int getint(int* pn)
{
    int c = EOF;
    while (isspace(c = getchar())) {
        ;
    }

    // These characters can be the leading character of a number.
    if (!isdigit(c) && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    int sign = (c == '-')? -1: 1;
    if (c == '-' || c == '+') {
        int c2 = getchar();
        if (!isdigit(c2)) {
            ungetc(c2, stdin);
            ungetc(c, stdin);
            return 0;
        } else {
            c = c2;
        }
    }

    for (*pn = 0; isdigit(c); c = getchar()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    ungetc(c, stdin);
    return c;
}
