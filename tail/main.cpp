/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--17                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tail.h"

#define DFTLINES 10
#define MAXLINE 1024

void print_help ();

int main (int argc, char* argv[])
{
    // lines is a ring buffer that holds pointers to
    // the last nlines of the input.
    int nlines, pos, len;
    char buf[MAXLINE];
    char* ptr;
    char** lines;

    nlines = DFTLINES;
    pos = 0;

    if (argc > 2) {
        print_help ();
        return -1;

    } else if (argc == 2) {
        char* s = *++argv;
        if (s[0] != '-') {
            print_help ();
            return -1;
        }

        nlines = atoi (++s);
    }

    lines = new char*[nlines];
    for (int i = 0; i < nlines; ++i) {
        lines[i] = NULL;
    }

    while ((len = my_getline (buf, MAXLINE)) > 0) {
        if (lines[pos] != NULL) {
            free_mem (lines[pos]);
        }
        
        // Don't forget additional space for '\0'.
        ptr = (char*) alloc_mem (len + 1);
        strcpy (ptr, buf);
        lines[pos] = ptr;
        pos = (pos + 1) % nlines;
    }

    
    for (int i = pos, count = 0;
         count < nlines;
         i = (i + 1) % nlines, count++) {
        if (lines[i] != NULL) {
            printf ("%s", lines[i]);
        }
    }         

    return 0;
}

void print_help ()
{ printf ("Usage: tail [-n]\n."); }
