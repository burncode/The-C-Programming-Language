// Author: jrjbear@gmail.com
// Date: Mon Oct 14 23:11:09 2013
//
// File: main.cpp
// Description: Simple version of UNIX tail


#include <stdlib.h>             // atoi
#include <string.h>
#include <stdio.h>
#include "utils/utils.h"
#include "tail.h"

void print_usage();

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;
    const int DFTLINES = 10;
    
    char buf[MAXLINE];
    int nlines = DFTLINES;
    if (argc > 2) {
        print_usage();
        return -1;
    } else if (argc == 2) {
        Option op = my_getopt(*++argv, buf);
        if (op != NUMBER) {
            print_usage();
            return -1;
        }
        nlines = atoi (buf);
    }

    // `lines' is a ring buffer that holds pointers to the last
    // `nlines' of the input.
    char** lines = new char*[nlines];
    for (int i = 0; i < nlines; ++i) {
        lines[i] = NULL;
    }
     
    int len = 0;
    int cur_pos = 0;
    while ((len = my_getline(buf, MAXLINE)) > 0) {
        if (lines[cur_pos] != NULL) {
            free_mem(lines[cur_pos]);
        }

        // Don't forget additional space for '\0'.
        char* ptr = (char*)alloc_mem(len + 1);
        strcpy(ptr, buf);
        lines[cur_pos] = ptr;
        cur_pos = (cur_pos + 1) % nlines;
    }

    for (int i = cur_pos, count = 0; count < nlines;
         i = (i + 1) % nlines, count++) {
        if (lines[i] != NULL) {
            printf("%s", lines[i]);
        } 
    }
    return 0;
}

void print_usage()
{ 
    printf("Usage: tail [-NUM].\n\n"); 
    printf("Print the last `NUM' lines of input. It's default value is 10\n");
}
