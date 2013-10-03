// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:52:27 2013
//
// File: 1-8.cpp
// Description: Count white spaces

#include <stdio.h>

int main(int argc, char* argv[])
{
    int ns = 0;
    int nt = 0;
    int nl = 0;

    for (int c = getchar(); c != EOF; c = getchar()) {
        if (c == '\n') {
            nl++;
        } else if (c == '\t') {
            nt++;
        } else if (c == ' ') {
            ns++;
        }
    }

    printf("%-15s %5d\n", "Total Spaces", ns);
    printf("%-15s %5d\n", "Total Tabs", nt);
    printf("%-15s %5d\n", "Total Lines", nl);

    return 0;
}

