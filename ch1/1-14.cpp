/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-14.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <ctype.h>

#define MAXHLST 80
#define MAXCHAR 128

int main () 
{
    int c, i, max, len;
    int count[MAXCHAR];

    for (i = 0; i < MAXCHAR; i++) {
        count[i] = 0;
    }

    // Count times of characters whose value is less than `MAXCHAR'.
    while ((c = getchar ()) != EOF) {
        if (c < MAXCHAR) {
            ++count[c];
        }
    }

    // Find the max count value.
    for (i = 0, max = 0; i < MAXCHAR; i++) {
        if (max < count[i]) {
            max = count[i];
        }
    }

    if (max == 0) {
        printf ("No character found\n");
        return 0;
    }

    printf ("%5s,%5s,%5s:\n", "INT", "CHAR", "FREQ");
    for (i = 0; i < MAXCHAR; i++) {
        if (isprint (i)) {
            printf ("%5d,%5c,%5d: ", i, i, count[i]);
        } else {
            printf ("%5d,%5c,%5d: ", i, ' ', count[i]);
        }

        // Get the percentage of `count[i]' to `max', and then
        // decide how many '*' should be displayed.
        for (len = (MAXHLST * count[i] + max - 1) / max; 
             len > 0; len--) {
            printf ("*");
        }
        printf ("\n");
    }

    return 0;
}
