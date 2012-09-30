/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--17                                                   **
 *                                                                      **
 * File: 4-11.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define BUFSIZE 1024

int getop (char s[]);

int main ()
{
    char s[BUFSIZE];
    char op;
    
    while ((op = getop (s)) != EOF) {
        if (op == NUMBER) {
            printf ("number element: %f\n", atof (s));
        } else {
            printf ("operator element: %c\n", op);
        }
    }

    return 0;
}

int getop (char s[])
{
    static int last_c =  0;

    int i, c;

    c = (last_c == 0)? getchar (): last_c;
    last_c =  0;
    while ((s[0] =  c) == ' ' || c == '\t') {
        c =  getchar ();
    }
    s[1] =  '\0';

    if (!isdigit (c) && c != '.') {
        return c;
    }

    i = 0;
    if (isdigit (c)) {
        while (isdigit (s[++i] = c =  getchar ())) {
            ;
        }
    }
    if (c == '.') {
        while (isdigit (s[++i] = c =  getchar ())) {
            ;
        }
    }
    s[i] = '\0';

    last_c =  c;
    return NUMBER;
}

