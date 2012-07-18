/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--01                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200

#define DFTINC 8
#define DFTBEGIN 0

#define NONE 0
#define INCMODE 1
#define LISTMODE 2

#define YES 1
#define NO 0

void entab (char tab_flags[]);
int find_next_stop (int i, char tab_flags[]);
void print_help ();

int main (int argc, char* argv[]) 
{
    // tab_flags marks the position of each tab locates.
    // For example, if tab_flags[1~7] is NO
    // and tab_flags[8] is YES, then a '\t' in position 1~8
    // will move the cursor directly to 9, which means
    // the character right after '\t' will appear at postion 9.
    char tab_flags[MAXSIZE];
    int begin, inc, mode, stop;

    mode = NONE;
    begin = DFTBEGIN;
    inc = DFTINC;

    for (int i = 0; i < MAXSIZE; ++i) {
        tab_flags[i] = NO;
    }

    while (--argc > 0) {
        char* s = *++argv;

        if (s[0] == '-') {
            if (mode == LISTMODE) {
                print_help ();
                return -1;
            }

            mode = INCMODE;
            begin = atoi (s + 1);

        } else if (s[0] == '+') {
            if (mode == LISTMODE) {
                print_help ();
                return -1;
            }

            mode = INCMODE;
            inc = atoi (s + 1);

        } else {
            if (mode == INCMODE) {
                print_help ();
                return -1;
            }

            mode = LISTMODE;
            stop = atoi (s);
            tab_flags[stop] = YES;
        }
    }

    if (mode != LISTMODE) {
        for (int i = begin; i < MAXSIZE; i += inc) {
            tab_flags[i] = YES;
        }
    }

    entab (tab_flags);
    return 0;
}

void entab (char tab_flags[]) 
{
    int c, i, next, last;

    // i marks the current point of the input, starts from 1.
    // last marks the last non-blank point.
    // next marks the next tab point, which is a multiple of NUM.
    // Note that the point next cannot hold any character,
    // input after next point starts from next + 1.
    for (i = 1, last = 0; 
         (c = getchar ()) != EOF; i++) {
        if (c == '\t') {
            next = find_next_stop (i, tab_flags);
            i = (next > 0? next: i);

        } else if (c == '\n') {
            putchar (c);
            i = last = 0;

        } else if (c != ' ') {
            if (last < i - 1) {
                // Insert tabs.
                for (last++, 
                     next = find_next_stop (last, tab_flags);
                     i > next && next > 0; 
                     last = next + 1, 
                     next = find_next_stop (last, tab_flags)) {
                    putchar ('\t');
                }

                // Fill the rest part with blanks.
                for(; last < i; last++) {
                    putchar (' ');
                }
            }

            // Now we reach the same position as input.

            last = i;
            putchar (c);
        }

        // Ignore blanks.
    }
}

int find_next_stop (int i, char tab_flags[]) 
{
    for (; i < MAXSIZE; ++i) {
        if (tab_flags[i] == YES) {
            return i;
        }
    }
    
    return -1;
}

void print_help ()
{
    printf ("Usage: entab [-begin] [+inc].\n");
    printf ("       entab [stop...].\n");
    printf ("Note that 2 modes above cannot be specified ");
    printf ("at the same time.\n");
    printf ("If no arguments are specified, ");
    printf ("the default mode is inc-mode with ");
    printf ("begin = 0 and inc = 8.\n");
}
