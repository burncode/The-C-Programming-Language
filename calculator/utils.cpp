/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: utils.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <math.h>
#include <string.h>
#include "calc.h"

int my_getline (char s[], int lim) 
{
    int c, i;

    // `i < lim - 1' because we should leave at least one space for '\0'.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        // Here `i' can never be `lim - 1', because the loop condition
        // above has already check `i < lim - 1' when `c == \n'.
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

void do_math_func (const char s[])
{
    if (strcmp (s, "sin") == 0) {
        push (sin (pop ()));
    } else if (strcmp (s, "cos") == 0) {
        push (cos (pop ()));
    } else if (strcmp (s, "exp") == 0) {
        push (exp (pop ()));
    } else {
        printf ("Unknown mathematic command: %s\n", s);
    }
}
