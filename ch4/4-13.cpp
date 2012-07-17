/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--17                                                   **
 *                                                                      **
 * File: 4-13.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAXSIZE 1024

void reverse (char s[]);

int main ()
{
    char line[MAXSIZE];

    while (my_getline (line, MAXSIZE) >= 0) {
        reverse (line);
        printf ("After reverse: %s\n\n", line);
    }

    return 0;
}

void reverse (char s[])
{
    size_t len = strlen (s);
    if (len > 1) {
        reverse (s + 1);
    }
    
    char first = s[0];

    for (size_t i = 0; i < len - 1; ++i) {
        s[i] = s[i + 1];
    }

    s[len - 1] = first;
}

