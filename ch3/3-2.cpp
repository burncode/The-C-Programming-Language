/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--30                                                   **
 *                                                                      **
 * File: 3-2.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include "utils.h"

#define BUFSIZE 1024

int escape (char s[], const char t[]);
int unescape (char s[], const char t[]);

int main ()
{
    char line[BUFSIZE];
    char buf[BUFSIZE];

    while (my_getline (line, BUFSIZE) >= 0) {
        unescape (buf, line);
        printf ("After unescape:\n%s\n", buf);

        escape (line, buf);
        printf ("Then escape this to origin input:\n%s\n\n", 
                line);
    }

    return 0;
}

int escape (char s[], const char t[])
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }

    s[j] = '\0';
    return j;
}

int unescape (char s[], const char t[])
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\') {
            switch (t[++i]) {
            case '\\':
                s[j++] = '\\';
                break;
            case 't':
                s[j++] = '\t';
                break;
            case 'n':
                s[j++] = '\n';
                break;
            case 'b':
                s[j++] = '\b';
                break;
            default:
                i--;
                s[j++] = '\\';
                break;
            }
        } else {
            s[j++] = t[i];
        }
    }

    s[j] = '\0';
    return j;
}
