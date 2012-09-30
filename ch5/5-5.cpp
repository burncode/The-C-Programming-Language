/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--22                                                   **
 *                                                                      **
 * File: 5-5.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#define MAXSIZE 1024

void my_strncat (char* s, const char* t, int n);
void my_strncpy (char* s, const char* t, int n);
int my_strncmp (char* s, const char* t, int n);

int main ()
{
    srand (time (NULL));

    char line1[MAXSIZE];
    char line2[MAXSIZE];
    char buf[MAXSIZE];

    while (my_getline (line1, MAXSIZE) >= 0
           && my_getline (line2, MAXSIZE) >= 0) {
        int n = rand () % 20 + 1;
                
        strncpy (buf, line1, MAXSIZE);
        my_strncat (buf, line2, n);
        printf ("After strncat (%s, %s, %d):\n%s\n\n", 
                line1, line2, n, buf);

        strncpy (buf, line1, MAXSIZE);
        my_strncpy (buf, line2, n);
        printf ("After strncpy (%s, %s, %d):\n%s\n\n", 
                line1, line2, n, buf);

        printf ("After strncmp (%s, %s, %d): %d\n\n", 
                line1, line2, n, 
                my_strncmp (line1, line2, n));

        printf ("***********************************"
                "*******************************\n\n");
    }

    return 0;
}

void my_strncat (char* s, const char* t, int n)
{
    s += strlen (s);
    while ((*s++ = *t++) && --n > 0) {
        ;
    }
    
    if (n == 0) {
        // s is not terminated by '\0'.
        *s = '\0';
    }
}

void my_strncpy (char* s, const char* t, int n)
{
    while ((*s++ = *t++) && --n > 0) {
        ;
    }

    // Note that we do not append a '\0' at the end of s
    // when n = 0 here.
    // This is exactly what standard C library does.
}

int my_strncmp (char* s, const char* t, int n)
{
    for (; *s == *t; s++, t++, n--) {
        if (*s == '\0' || n == 0) {
            return 0;
        }
    }
    
    return *s - *t;
}
