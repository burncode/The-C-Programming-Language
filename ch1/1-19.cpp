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
#include "utils.h"

#define MAXLINE 1024


// `len' should be the length of the input string
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


void reverse (char s[], int len) 
{
    char temp;
    for(int i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
