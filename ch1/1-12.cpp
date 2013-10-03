// Author: jrjbear@gmail.com
// Date: Thu Oct  3 00:44:44 2013
//
// File: 1-12.cpp
// Description: Print one word per line

#include <stdio.h>

enum LineState {
    OLD_LINE = 0,
    NEW_LINE = 1,
};

int main(int argc, char* argv[])
{
    int c = -1;
    LineState state = NEW_LINE;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c =='\n') {
            if (state == OLD_LINE) {
                putchar('\n');
                state = NEW_LINE;
            }
            // Here `state == NEWLINE', so we do not output
            // empty lines when reading successive blanks.
        } else {
            putchar(c);
            state = OLD_LINE;
        }
    }

    return 0;
}
