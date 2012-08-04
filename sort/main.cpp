/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--21                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

#define DFTLINES 1024

bool g_ignore_case;
int g_field_num;

int main (int argc, char* argv[])
{
    // All the input lines are stored in `lines',
    // whose max size is limited by `cap'
    // and current size is marked by `pos'.
    bool reverse_flag;
    int len, pos, cap, op;
    char** lines;
    char** tmp;
    char* ptr;
    char buf[MAXLINE];
    CmpFn cmp;

    cmp = (CmpFn) my_strcmp;
    reverse_flag = false;
    g_ignore_case = false;
    g_field_num = 0;


    while (--argc > 0) {
        op = getop (*++argv, buf);
        
        switch (op) {
        case FLAG:
            for (char* c = buf; *c != '\0'; ++c) {
                switch (*c) {
                case 'n':
                    cmp = (CmpFn) numcmp;
                    break;

                case 'r':
                    reverse_flag = true;
                    break;

                case 'd':
                    cmp = (CmpFn) dircmp;
                    break;

                case 'f':
                    g_ignore_case = true;
                    break;

                case 'k':
                    if (* (c + 1) == '\0' 
                        && --argc > 0
                        && getop (*++argv, buf) == NUMBER) {
                        g_field_num = atoi (buf);
                        break;
                    }

                default:
                    print_help ();
                    return -1;
                }
            }
            break;

        default:
            print_help ();
            return -1;
        }
    }
             

    cap = DFTLINES;
    lines = new char*[cap];
    pos = 0;
    while ((len = my_getline (buf, MAXLINE)) >= 0) {
        if (pos == cap) {
            // `lines' has reached its capacity,
            // so we double `cap' here.
            tmp = new char*[cap * 2];
            bcopy (lines, tmp, cap * sizeof (char*));
     
            delete lines;
            lines = tmp;
            cap *= 2;
        }

        ptr = (char*) alloc_mem (len + 1);
        strcpy (ptr, buf);
        lines[pos++] = ptr;
    }

    qsort (lines, 0, pos - 1, cmp);

    for (int i = 0; i < pos; ++i) {
        int index = (reverse_flag? pos - i - 1: i);
        printf ("%s\n",  lines[index]);
    }

    return 0;
}
