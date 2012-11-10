/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-18.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define MAXLINE 1024

int trim (char line[], int lim);

int main ()
{
    int len;
    char line[MAXLINE];

    while ((len = trim (line, MAXLINE)) >= 0) {
        printf ("%s", line);
    }

    return 0;
}

int trim (char s[], int lim) 
{
    int c, i, last;

    // `i < lim - 1' because we should leave at least one space for '\0'.
    // `last' marks the last non-blank point of input.
    for (i = 0, last = -1; i < lim - 1 
         && (c = getchar()) != EOF 
         && c != '\n'; i++) {
        if (c != ' ' && c != '\t') {
            last = i;
        }
        s[i] = c;
    }

    if(c == '\n' && last >= 0) {
        // Here `i' can never be `lim - 1', because the loop condition
        // above has already check `i < lim - 1' when `c == \n'. Note
        // that we skip '\n' when the whole line is empty (`last < 0').
        s[i] = c;
        s[++last] = c;
    }
    s[++last] = '\0';

    return (c == EOF? -1: last);
}
