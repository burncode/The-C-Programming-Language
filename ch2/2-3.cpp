/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 2-3.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <ctype.h>
#include "utils.h"

#define MAXLINE 1024

int htoi (char s[], int *result);

int main ()
{
    char line[MAXLINE];
    int result;
    while (my_getline (line, MAXLINE) >= 0) {
        if (htoi (line, &result) != 0) {
            printf ("Invalid input\n");
        } else {
            printf ("Value is: %d\n", result);
        }
    }
    return 0;
}

int htoi (char s[], int* result)
{
    int i, res, c, sign;

    i = 0;
    sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-'? 0: 1);
        i++;
    }

    if (s[i] == '0' && tolower (s[i + 1]) =='x') {
        i += 2;
    }

    if (s[i] == '\0') {
        return -1;
    }

    for (res = 0; s[i] != '\0'; i++) {
        c = tolower (s[i]);
        if (c >= '0' && c <= '9') {
            res = res * 16 + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            res = res * 16 + c - 'a' + 10;
        } else {
            return -1;
        }
    }
    *result = (sign == 0? -res: res);
    return 0;
}
