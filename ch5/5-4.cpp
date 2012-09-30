/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--22                                                   **
 *                                                                      **
 * File: 5-4.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include "utils.h"

#define MAXSIZE 1024

int strend (char* s, const char* t);

int main ()
{
    char line1[MAXSIZE];
    char line2[MAXSIZE];

    while (my_getline (line1, MAXSIZE) >= 0
           && my_getline (line2, MAXSIZE) >= 0) {
        printf ("strend (%s, %s): %d\n\n", line1, 
                line2, strend (line1, line2));
    }

    return 0;
}

int strend (char* s, const char* t)
{
    int offset;
    size_t len_s, len_t;

    len_s = strlen (s);
    len_t = strlen (t);
    offset = len_s - len_t;

    if (offset >= 0) {
        s += offset;
        while (*s != '\0') {
            if (*s++ != *t++) {
                break;
            }
        }
        
        if (*s == '\0') {
            return 1;
        }
    }

    return 0;
}
