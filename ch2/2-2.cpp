// Author: jrjbear@gmail.com
// Date: Thu Oct  3 22:28:35 2013
//
// File: 2-2.cpp
// Description: Read lines without using logical operators


#include <stdio.h>

// This is like `my_getline' except it doesn't use any logical operators.
int my_getline2(char s[], int lim);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;
    char line[MAXLINE];
    while (my_getline2(line, MAXLINE) > 0) {
        printf("%s", line);
    }

    return 0;
}

int my_getline2(char s[], int lim)
{
    int i = 0;
    while (i < lim - 1) {
        int c = getchar();
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            s[i++] = c;
            break;
        }
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
