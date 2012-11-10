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

    // `i < lim - 1' because we should leave at least one space for \0.
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

void print_help ()
{ 
    printf ("Usage: tail [-NUM].\n\n"); 
    printf ("NUM marks the number of output lines.\n");
    printf ("Default vale of NUM is 10.\n");
}
