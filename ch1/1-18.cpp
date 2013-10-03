// Author: jrjbear@gmail.com
// Date: Thu Oct  3 11:20:50 2013
//
// File: 1-18.cpp
// Description: Delete trailing white spaces

#include <stdio.h>

// Deletes trailing white spaces and skips entirely blank lines.
// Returns the number of characters including '\n'.
int trim(char line[], int lim);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;

    int len;
    char line[MAXLINE];
    while ((len = trim(line, MAXLINE)) > 0) {
        printf("%s", line);
    }

    return 0;
}

int trim(char s[], int lim) 
{
    // `last' marks the last non-blank position.
    int last = -1;
    int i = 0;
    int c = -1;

    // Make sure `i < lim - 1' so as to leave at least one space for '\0'.
    while (i < lim - 1 && (c = getchar()) != EOF) {
        if (c == '\n') {
            if (last >= 0) {
                s[++last] = c;
                break;
            } else {
                // Skip entirely blank lines.
                i = 0;
                continue;
            }
            
        } else if (c != ' ' && c != '\t') {
            last = i;
        }
        s[i++] = c;
    }

    s[++last] = '\0';
    return last;
}
