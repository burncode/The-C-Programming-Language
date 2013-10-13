// Author: jrjbear@gmail.com
// Date: Sun Oct 13 10:56:16 2013
//
// File: 5-2.cpp
// Description: Get a float number from standard input


#include <stdio.h>
#include <ctype.h>

// Returns 0 if it's not a float number. Otherwise returns the next
// character right after the float, and this character will be pushed
// back to standard input.
int getfloat(float* pf);

int main(int argc, char* argv[])
{
    int ret = 0;
    int count = 0;
    float val = 0;
    do {
        ret = getfloat(&val);
        if (ret > 0) {
            count++;
            printf ("val%d = %f\n", count, val);
        } else {
            ret = getchar();
        }
    } while (ret != EOF);

    return 0;
}

int getfloat(float* pf)
{
    int c = EOF;
    while (isspace(c = getchar())) {
        ;
    }

    // These characters can be the leading character of a number.
    if (!isdigit(c) && c != '+' && c != '-' && c != '.') {
        ungetc(c, stdin);
        return 0;
    }
    int sign = (c == '-')? -1: 1;

    // '.' should be followed by a digit to be a pure digit number.
    if (c == '.') {
        int c2 = getchar();
        ungetc(c2, stdin);
        if (!isdigit(c2)) {
            ungetc(c, stdin);
            return 0;
        }
    }
    if ((c == '-' || c == '+')) {
        // '+' and '-' may be followed by a digit or a '.'.
        int c2 = getchar();
        if (isdigit(c2)) {
            c = c2;
        } else if (c2 == '.') {
            int c3 = getchar();
            ungetc(c3, stdin);
            if (isdigit(c3)) {
                // Case such as +.123.
                c = c2;
            } else {
                ungetc(c2, stdin);
                ungetc(c, stdin);
                return 0;
            }
        } else {
            ungetc(c2, stdin);
            ungetc(c, stdin);
            return 0;
        }
    }

    for (*pf = 0; isdigit(c); c = getchar()) {
        *pf = 10 * *pf + (c - '0');
    }
    *pf *= sign;

    if (c == '.') {
        int c2 = getchar();
        if (!isdigit(c2)) {
            // Case such as 123.abc.
            ungetc(c2, stdin);
            ungetc(c, stdin);
            return c;
        } else {
            c = c2;
        }
        int power = 1;
        for (; isdigit(c); c = getchar()) {
            *pf = 10 * *pf + (c - '0') * sign;
            power *= 10;
        }
        *pf = *pf / power;
    }
    ungetc(c, stdin);
    return c;
}
