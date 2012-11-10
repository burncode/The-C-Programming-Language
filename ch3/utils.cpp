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

int my_getline (char s[], int lim) 
{
    int c, i;

    // `i < lim - 1' because we should leave at least one space for '\0'.
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
