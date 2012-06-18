/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--05--03                                                   **
 *                                                                      **
 * File: 4-1.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <string.h>
#include "common.hpp"

#define MAXSIZE 1024
#define BUFSIZE 1024

int strrindex (const char src[], const char pattern[]);
void compute_next (const char src[], int next[]);

int main ()
{
    char line[BUFSIZE];
    char pattern[BUFSIZE];

    while (my_getline (line, BUFSIZE) >= 0
           && my_getline (pattern, BUFSIZE) >= 0) {
        printf("strrindex (%s, %s): %d\n", line, pattern, 
               strrindex (line, pattern));
    }

    return 0;
}

int strrindex (const char src[], const char pattern[])
{
    static int next[MAXSIZE];
    compute_next (pattern, next);

    int i, j, start;
    i = j = 0;
    start = -1;
    while (src[i] != '\0') {
        if (src[i] == pattern[j]) {
            i++;
            j++;

        } else {
            j = next[j];
            if (j < 0) {
                // Compare src from the beginning of pattern.
                j = 0;
                i++;
                continue;
            }
        }

        if (pattern[j] == '\0') {
            // Find one match, record it in start and continue searching.
            // Note that j can never be 0 here.
            start = i - j;
            j = next[j];
        }
    }

    return start;
}

void compute_next (const char src[], int next[])
{
    next[0] = -1;
    if (src[0] == '\0') {
        return;
    }
    
    // i marks the index of the current character in src.
    // If x = next[i], then it means 
    // string src[0 ... (x - 1)] == src[(i - x) ... (i - 1)].
    next[1] = 0;
    for (int i = 1; src[i] != '\0'; i++) {
        int j = next[i - 1];
        while (src[i - 1] != src[j] && j >= 0) {
            j = next[j];
        }
        next[i] = j + 1;
    }
}
