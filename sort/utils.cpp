/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: utils.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_getline (char s[], int lim) 
{
    int c, i;

    // `i < lim - 1' because we should leave at least one space for '\0'.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    s[i] = '\0';
    if (c == EOF) {
        return -1;
    } else {
        return i;
    }
}

void swap (char* v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void find_field (const char* s, int field_num, int* begin, int* end)
{
    int count, i;

    if (field_num < 1) {
        *begin = 0;
        *end = strlen (s);
        return;
    }

    count = 0;
    i = 0;
    
    // Skip leading blanks.
    while (isblank (s[i])) {
        i++;
    }

    // Calculate value of `begin'.
    if (field_num > 1) {
        while (s[i] != '\0') {
            if (isblank (s[i])) {
                while (isblank (s[i])) {
                    i++;
                }
            
                if (++count >= field_num - 1) {
                    break;
                }

            } else {
                i++;
            }
        }
    }
    *begin = i;

    // Calculate value of `end'.
    while (s[i] != '\0' && !isblank (s[i])) {
        i++;
    }
    *end = i;
}

void print_help ()
{
    printf ("Usage: sort [-nrdf] [-k NUM].\n\n");
    printf ("-n: sort by numeric order.\n");
    printf ("-r: sort in reverse order.\n");
    printf ("-d: sort by directory order, which compare input only\n"
            "    on numbers, letters and blanks.\n");
    printf ("-f: case-insensitive sort.\n");
    printf ("-k: sort only on the NUMth field. Note that fields are\n"
            "    separated by blanks and the leading blanks of each\n"
            "    line will be discarded.\n");
}
