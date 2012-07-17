/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--30                                                   **
 *                                                                      **
 * File: 3-3.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <ctype.h>
#include "utils.h"

#define BUFSIZE 1024

int expand (char s1[], char s2[]);
int fill (char begin, char end, char* dest);

int main ()
{
    char line[BUFSIZE];
    char buf[BUFSIZE];

    while (my_getline (line, BUFSIZE) >= 0) {
        expand (line, buf);
        printf("After expand:\n%s\n\n", buf);
    }

    return 0;
}

int expand (char s1[], char s2[])
{
    int i, j, ret;

    // begin marks the letter on the left side of '-',
    // while end marks the letter on the right side.
    // The value is '\0' by default.
    char begin, end;

    begin = end = '\0';
    for (i = 0, j = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == '-') {
            end = s1[i + 1];
            ret = fill (begin, end, &s2[j - 1]);
            
            if (ret > 0) {
                j += ret - 1;
                begin = end;
                i++;
                continue;
            } 
        }

        s2[j++] = s1[i];
        begin = s1[i];
    }

    s2[j] = '\0';
    return j;
}

int fill (char begin, char end, char* dest)
{
    int i = 0;

    if (begin <= end) {
        if (islower (begin) && islower (end) 
            || isupper (begin) && isupper (end) 
            || isdigit (begin) && isdigit (end)) {
            for (; begin + i <= end; ++i) {
                dest[i] = begin + i;
            }
        }
    }

    return i;
}
