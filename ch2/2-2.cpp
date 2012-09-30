/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 2-2.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#define MAXLINE 1000

int my_getline (char line[], int maxline);
void copy (char to[], const char from[]);

int main () 
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline (line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy (longest, line);
        }
    }

    if (max > 0) {
        printf ("%s", longest);
    }

    return 0;
}

int my_getline (char s[], int lim)
{
    int c, i, flag;

    i = 0;
    do {
        flag = 0;

        if (i < lim - 1) {
            if ((c = getchar ()) != EOF) {
                if (c != '\n') {
                    s[i++] = c;
                    flag = 1;
                }
            }
        }
    } while(flag != 0);

    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy (char to[], const char from[]) 
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
