// Author: jrjbear@gmail.com
// Date: Thu Oct  3 17:56:03 2013
//
// File: 1-23.cpp
// Description: Remove C comments


#include <stdio.h>

enum CodeState {
    CODE = 0,
    LINE_COMMENT = 1,
    MULTI_COMMENT = 2,
};

int main(int argc, char* argv[])
{
    int c = -1;
    CodeState state = CODE;
    while ((c = getchar()) != EOF) {
        if (state == CODE) {
            if (c == '\"' || c == '\'') {
                putchar(c);
                int quote = c;
                while ((c = getchar()) != EOF) {
                    putchar(c);                    
                    if (c == '\\') {
                        // Skip escape character.
                        putchar(getchar());
                    } else if (c == quote) {
                        break;
                    }
                }                    
                 
            } else if (c == '/') {
                c = getchar();
                if (c == '/') {
                    state = LINE_COMMENT;
                } else if (c == '*') {
                    state = MULTI_COMMENT;
                } else {
                    // '/' is not followed by '/' or '*', 
                    // so just print what we read.
                    putchar('/');
                    putchar(c);
                }

            } else {
                putchar(c);
            }

        } else if (state == LINE_COMMENT && c == '\n') {
            state = CODE;
            putchar(c);

        } else if (c == '*' && state == MULTI_COMMENT) {
            if (getchar() == '/') {
                state = CODE;
            }
        }

        // Comment area, do not print.
    } 

    return 0;
}
