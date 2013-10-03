// Author: jrjbear@gmail.com
// Date: Thu Oct  3 11:15:44 2013
//
// File: 1-17.cpp
// Description: Print lines whose length is greater than THRESHOLD


#include <stdio.h>
#include "utils/utils.h"

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;
    const int THRESHOLD = 80;

    int len = -1;
    char line[MAXLINE];
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}
