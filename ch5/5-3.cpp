// Author: jrjbear@gmail.com
// Date: Sun Oct 13 11:52:54 2013
//
// File: 5-3.cpp
// Description: Implementation of strcat 


#include <string.h>
#include <stdio.h>
#include "utils/utils.h"

void my_strcat(char* s, const char* t);

int main(int argc, char* argv[]) {
    const int MAXSIZE = 1024;

    int len = 0;
    char line1[MAXSIZE];
    char line2[MAXSIZE];
    while (true) {
        printf("Input destination string: ");
        if ((len = my_getline(line1, MAXSIZE)) <= 0) {
            break;
        }
        line1[len - 1] = '\0';
        printf("Input source string: ");
        if ((len = my_getline(line2, MAXSIZE)) <= 0) {
            break;
        }
        line2[len - 1] = '\0';
        my_strcat(line1, line2);
        printf("After strcat(dest, src): %s\n\n", line1);
    }

    return 0;
}

void my_strcat(char* s, const char* t) {
    s += strlen(s);
    while ((*s++ = *t++) != '\0') {
        ;
    }
}
