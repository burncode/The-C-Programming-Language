// Author: jrjbear@gmail.com
// Date: Mon Oct 14 23:45:46 2013
//
// File: main.cpp
// Description: Simple version of UNIX sort


#include <stdio.h>
#include <string.h>
#include <stdlib.h>             // atoi
#include <getopt.h>
#include "utils/utils.h"
#include "sort.h"

bool g_ignore_case = false;
int g_field_num = -1;

void print_usage();

int main(int argc, char* argv[])
{
    const int MAXLINES = 1 << 20;
    const int MAXLINE = 1 << 10;

    int opt = -1;
    CmpFn cmp = my_strcmp;
    bool reverse_flag = false;
    while ((opt = getopt_long(argc, argv, "+nrdfk:", NULL, NULL)) != -1) {
        switch (opt) {
        case 'n':
            cmp = numcmp;
            break;
        case 'r':
            reverse_flag = true;
            break;
        case 'd':
            cmp = dircmp;
            break;
        case 'f':
            g_ignore_case = true;
            break;
        case 'k':
            g_field_num = atoi(optarg);
            break;

        case '?':
        default:
            print_usage();
            return -1;
        }
    }
    if (optind < argc) {
        print_usage();
        return -1;
    }

    int len = 0;
    int pos = 0;
    char buf[MAXLINE];
    char* lines[MAXLINES];
    while ((len = my_getline(buf, MAXLINE)) > 0) {
        if (pos >= MAXLINES) {
            printf("Max lines reached: %d\n", MAXLINES);
            return -1;
        }

        // Discard character '\n'.
        char* ptr = (char*)alloc_mem(len);
        strncpy(ptr, buf, len - 1);
        ptr[len - 1] = '\0';
        lines[pos++] = ptr;
    }

    qsort(lines, 0, pos - 1, cmp);
    for (int i = 0; i < pos; ++i) {
        int index = (reverse_flag? pos - i - 1: i);
        printf("%s\n",  lines[index]);
    }

    return 0;
}

void print_usage()
{
    printf("Usage: sort [-nrdf] [-k NUM].\n\n");
    printf("-n: sort by numeric order.\n");
    printf("-r: sort in reverse order.\n");
    printf("-d: sort by directory order, which ignores characters except\n"
           "    numbers, letters and blanks.\n");
    printf("-f: case-insensitive sort.\n");
    printf("-k: sort only on the `NUM'th field (which starts from 1).\n"
           "    Note that fields are separated by blanks and leading\n"
           "    blanks are trimmed off.\n");
}
