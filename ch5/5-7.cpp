// Author: jrjbear@gmail.com
// Date: Sun Oct 13 12:34:23 2013
//
// File: 5-7.cpp
// Description: Read the whole input into array of lines


#include <string.h>
#include <stdio.h>
#include "utils/utils.h"

const int MAXLEN = 1024;

int readlines(char* lines[], int max_lines, char* buf, int buf_size);

int main(int argc, char* argv[])
{
    const int MAXLINES = 5000;
    const int MAXSIZE = MAXLEN * MAXLINES;

    char* lines[MAXLINES];
    char* buf = new char[MAXSIZE];
    int nlines = 0;
    if ((nlines = readlines (lines, MAXLINES, buf, MAXSIZE)) < 0) {
        return -1;
    } 
    for (int i = 0; i < nlines; ++i) {
        printf ("%s", lines[i]);
    }
    delete [] buf;
    return 0;
}

int readlines(char* lines[], int max_lines, char* buf, int buf_size)
{
    char line[MAXLEN];
    int len = 0;
    int size = 0;
    int nlines = 0;

    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (nlines >= max_lines) {
            printf("Max lines %d reached", max_lines);
            return -1;
        } else if (buf_size - size <= len) {
            printf("Max buffer size %d reached", buf_size);
            return -1;
        } else {
            strcpy(buf + size, line);
            lines[nlines++] = buf + size;
            size += len + 1;
        }
    }
    return nlines;
}
