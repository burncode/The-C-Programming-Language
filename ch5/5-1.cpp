/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--20                                                   **
 *                                                                      **
 * File: 5-1.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <ctype.h>
#include <stdio.h>
#include "utils.h"

int getint (int* pn);

int main ()
{
    int val, count, ret, c;

    count = 0;
    do {
        ret = getint (&val);
        if (ret > 0) {
            count++;
            printf ("val%d = %d\n", count, val);
        } else {
            c = getch ();
        }
    } while (c != EOF);
}

int getint (int* pn)
{
    int c, c2, sign;

    while (isspace (c = getch ())) {
        ;
    }

    // These characters can be the leading character of a number.
    if (!isdigit (c) && c != '+' && c != '-') {
        ungetch (c);
        return 0;
    }

    sign = (c == '-')? -1: 1;

    if (c == '-' || c == '+') {
        c2 = getch ();
        if (!isdigit (c2)) {
            ungetch (c2);
            ungetch (c);
            return 0;
        } else {
            c = c2;
        }
    }

    for (*pn = 0; isdigit (c); c = getch ()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
	
    ungetch (c);
    return c;
}
