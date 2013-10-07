// Author: jrjbear@gmail.com
// Date: Sat Oct  5 23:27:34 2013
//
// File: 4-1.cpp
// Description: String search(returns the rightmost one) using KMP

#include <stdio.h>
#include <string.h>
#include "utils/utils.h"

int strrindex(const char src[], const char pattern[]);
void compute_next(const char src[], int next[]);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;

    int len = 0;
    char line[MAXLINE];
    char pattern[MAXLINE];
    while (true) {
        printf("Input source string: ");
        if ((len = my_getline(line, MAXLINE)) <= 0) {
            break;
        }
        line[len - 1] = '\0';        

        printf("Input pattern: ");
        if ((len = my_getline(pattern, MAXLINE)) <= 0) {
            break;
        }
        pattern[len - 1] = '\0';
        printf("strrindex(%s, %s): %d\n\n", line, pattern, 
               strrindex(line, pattern));
    }

    return 0;
}

int strrindex(const char src[], const char pattern[])
{
    static const int MAXSIZE = 1024;
    int next[MAXSIZE];
    if (strlen(pattern) > MAXSIZE) {
        printf("Pattern length overflow: %dvs%d", strlen(pattern), MAXSIZE);
        return -1;
    }
    compute_next(pattern, next);

    int i = 0;
    int j = 0;
    int start = -1;
    while (src[i] != '\0') {
        if (src[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
            if (j < 0) {
                // Compare `src' from the beginning of pattern.
                j = 0;
                i++;
                continue;
            }
        }

        if (pattern[j] == '\0') {
            // Find one match, record it in `start' and continue
            // searching. Note that `j' can never be 0 here.
            start = i - j;
            j = next[j];
        }
    }
    return start;
}

void compute_next(const char src[], int next[])
{
    next[0] = -1;
    if (src[0] == '\0') {
        return;
    }
    
    // next[i] = x means src[0 ... (x-1)] == src[(i-x) ... (i-1)].
    next[1] = 0;
    for (int i = 1; src[i] != '\0'; i++) {
        int j = next[i - 1];
        while (src[i - 1] != src[j] && j >= 0) {
            j = next[j];
        }
        next[i] = j + 1;
    }
}
