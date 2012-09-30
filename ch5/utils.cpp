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
#include <string.h>

#define BUFSIZE 100

// Note that '\n' is removed in s and this function
// returns the number of the remaining characters.
int my_getline (char s[], int lim) 
{
    int c, i;

    // i < lim - 1 because we should leave at least
    // one space for '\0'.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    s[i] = '\0';
    if (c == EOF) {
        return -1;
    } else {
        return i;
    }
}

void reverse (char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; 
         i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}



static int buf[BUFSIZE];
static int bufp = 0;

int getch () 
{ return (bufp > 0)? buf[--bufp]: getchar (); }

void ungetch (int c)
{
    if (bufp >= BUFSIZE) {
        printf ("Stack overflow\n");
    } else {
        buf[bufp++] = c;
    }
}
