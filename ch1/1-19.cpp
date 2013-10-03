// Author: jrjbear@gmail.com
// Date: Thu Oct  3 13:54:11 2013
//
// File: 1-19.cpp
// Description: Reverse each line


#include <stdio.h>
#include "utils/utils.h"

void reverse(char s[], int len);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;
    
    int len = 0;
    char line[MAXLINE];
    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(line, len - 1);	
        printf("%s", line);
    }

    return 0;
}


void reverse(char s[], int len) 
{
    char temp;
    for(int i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
