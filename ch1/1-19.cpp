/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-19.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define MAXLINE 1024

int my_getline (char line[], int lim);

// len should be the length of the input string
// that you want to reverse.
void reverse (char s[], int len);

int main() 
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline (line, MAXLINE)) > 0) {
        reverse (line, len - 1);	
        printf ("%s", line);
    }

    return 0;
}

int my_getline (char s[], int lim) 
{
    int c, i;

    // i < lim - 1 because we should leave at least
    // one space for \0.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        // Here i can never be lim - 1, because
        // the loop condition above has already
        // check i < lim - 1 when c == \n.
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse (char s[], int len) 
{
    char temp;
    for(int i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
