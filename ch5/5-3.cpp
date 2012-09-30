/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--22                                                   **
 *                                                                      **
 * File: 5-3.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include "utils.h"

#define MAXSIZE 1024

void my_strcat (char* s, const char* t);

int main ()
{
    char line1[MAXSIZE];
    char line2[MAXSIZE];

    while (my_getline (line1, MAXSIZE) >= 0
           && my_getline (line2, MAXSIZE) >= 0) {
        my_strcat (line1, line2);
        printf ("After strcat: %s\n\n", line1);
    }

    return 0;
}

void my_strcat (char* s, const char* t)
{
    s += strlen (s);
    while (*s++ = *t++) {
        ;
    }
}
