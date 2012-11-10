/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 2-4.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include "utils.h"

#define SIZE 256
#define MAXLINE 1024

void squeeze (char s1[], const char s2[]);

int main ()
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    while (my_getline (s1, MAXLINE) >= 0
           && my_getline (s2, MAXLINE) >= 0) {
        squeeze (s1, s2);
        printf("After squeeze, s1: %s\n", s1);
    }

    return 0;
}

void squeeze(char s1[], const char s2[])
{
    // Bitmap used to record characters, starts from 0 which
    // means the first bit in bitmap represents 0.
    static char bitmap[(SIZE + 7) / 8];

    int i, j;
    unsigned char c;

    memset (bitmap, 0, sizeof (bitmap));
    for (i = 0; s2[i] != '\0'; i++) {
        c = s2[i];
        bitmap[c / 8] |= (1 << c % 8);
    }

    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        c = s1[i];
        if (!(bitmap[c / 8] & (1 << c % 8))) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
