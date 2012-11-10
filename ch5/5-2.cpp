/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--20                                                   **
 *                                                                      **
 * File: 5-2.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <ctype.h>
#include "utils.h"

int getfloat (float* pf);

int main ()
{
    int count, ret, c;
    float val;

    count = 0;
    do {
        ret = getfloat (&val);
        if (ret > 0) {
            count++;
            printf ("val%d = %f\n", count, val);
        } else {
            c = getch ();
        }
    } while (c != EOF);
}

int getfloat (float* pf)
{
    int c, c2, sign, power;
    bool is_number;

    is_number = false;
    while (isspace (c = getch ())) {
        ;
    }

    // These characters can be the leading character of a number.
    if (!isdigit (c) && c != '+' 
        && c != '-' && c != '.') {
        ungetch (c);
        return 0;
    }
  
    sign = (c == '-')? -1: 1;

    // '+' and '-' should be followed by a digit to be a number
    // or be followed by a '.'. For example, -.123.
    if ((c == '-' || c == '+')) {
        c2 = getch ();
        if (!isdigit (c2) && c2 != '.') {
            ungetch (c2);
            ungetch (c);
            return 0;
        } else {
            c = c2;
        }
    }

    // '.' should be followed by a digit to be a pure digit number.
    if (c == '.') {
        c2 = getch ();
        if (!isdigit (c2)) {
            ungetch (c2);
            ungetch (c);
            return 0;
        } else {
            ungetch (c2);
        }
    }


    for (*pf = 0; isdigit (c); c = getch ()) {
        *pf = 10 * *pf + (c - '0');
        is_number = true;
    }
    *pf *= sign;

    if (c == '.') {
        // '.' should be followed by a digit to be a digit number.
        c2 = getch ();
        if (!isdigit (c2)) {
            ungetch (c2);
            ungetch (c);
            return (is_number? c: 0);
        } else {
            c = c2;
        }

        for (power = 1; isdigit (c); c = getch ()) {
            *pf = 10 * *pf + (c - '0') * sign;
            power *= 10;
        }
        *pf = *pf / (float) power;
    }

    ungetch (c);
    return c;
}
