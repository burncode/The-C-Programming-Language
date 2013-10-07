// Author: jrjbear@gmail.com
// Date: Mon Oct  7 14:16:06 2013
//
// File: 4-11.cpp
// Description: Use static variable in getop to store last character


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static const char NUMBER = '0';

// Cannot recognize numbers with sign character.
int getop(char s[]);

int main(int argc, char* argv[])
{
    const int BUFSIZE = 1024;

    char s[BUFSIZE];
    int op = EOF;
    while ((op = getop(s)) != EOF) {
        if (op == NUMBER) {
            printf("number element: %f\n", atof(s));
        } else {
            printf("operator element: %c\n", op);
        }
    }

    return 0;
}

int getop(char s[])
{
    static int last_c =  EOF;

    int c = (last_c == EOF)? getchar(): last_c;
    last_c = EOF;
    while (c == ' ' || c == '\t') {
        c = getchar();
    }

    int i = 0;
    s[i] = '\0';

    if (!isdigit(c) && c != '.') {
        return c;
    }
    do {
        s[i++] = c;
        c = getchar();
    } while (isdigit(c));

    if (c == '.') {
        // May introduce a bug when input is 123.abc. If so,
        // s[] will be `123.' and return value is `NUMBER'.
        do {        
            s[i++] = c;
            c = getchar();
        } while (isdigit(c));
    }
    s[i] = '\0';
    last_c =  c;
    return NUMBER;
}

