/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--22                                                   **
 *                                                                      **
 * File: 5-7.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include "utils.h"

#define MAXLEN 1024
#define MAXLINES 5000
#define MAXSIZE 1024 * 5000

int readlines (char* lines[], int max_lines, 
               char* buf, int buf_size);

int main ()
{
    int nlines, ret;
    char* buf;
    char* lines[MAXLINES];

    buf = new char[MAXSIZE];
    ret = 0;

    if ((nlines = readlines (lines, MAXLINES, 
                             buf, MAXSIZE)) < 0) {
        ret = -1;
    } else {
        for (int i = 0; i < nlines; ++i) {
            printf ("%s\n", lines[i]);
        }
    }

    delete [] buf;
    return ret;
}

int readlines (char* lines[], int max_lines, 
               char* buf, int buf_size)
{
    char line[MAXLEN];
    int nlines, size, len;

    nlines = 0;
    size = 0;
    while ((len = my_getline (line, MAXLEN)) >= 0) {
        if (nlines >= max_lines) {
            printf ("Max lines %d reached", 
                    max_lines);
            return -1;

        } else if (buf_size - size <= len) {
            printf ("Max buffer size %d reached", 
                    buf_size);
            return -1;

        } else {
            strcpy (buf + size, line);
            lines[nlines++] = buf + size;
            size += len + 1;
        }
    }

    return nlines;
}
