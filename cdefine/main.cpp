// Author: jrjbear@gmail.com
// Date: Mon Dec  9 22:39:56 2013
//
// File: main.cpp
// Description: Simple `#define' preprocessor of C

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cdefine.h"

int main(int argc, char* argv[])
{
    const int MAXSIZE = 4096;
    char word[MAXSIZE];
    char def[MAXSIZE];

    int c = -1;
    bool newline = true;
    while ((c = getchar()) != EOF) {
        if (c == '\"' || c == '\'') {
            newline = false;
            putchar(c);
            if (consume_quote(c)) {
                return -1;
            }

        } else if (c == '/') {
            newline = false;
            putchar(c);
            c = getchar();
            if (c == '/') {
                putchar(c);
                if (consume_line_comment()) {
                    return -1;
                }
            } else if (c == '*') {
                putchar(c);
                if (consume_multi_comment()) {
                    return -1;
                }
            } else {
                ungetc(c, stdin);
            }

        } else if (isalpha(c) || c == '_') {
            newline = false;
            ungetc(c, stdin);
            // These characters can be the beginning of a keyword
            getword(word, MAXSIZE);
            const char* defn = lookup(word);
            if (defn != NULL) {
                fputs(defn, stdout);
            } else {
                fputs(word, stdout);
            }
            
        } else if (c == '#') {
            if (!newline) {
                printf("\nERROR: Preprocessor sign '#' must should be at the "
                       "beginning of a line\n");
                return -1;
            }
            newline = false;
            putchar(c);
            // Preprocessor control line may contain blanks
            consume_blanks();
            if (getword(word, MAXSIZE) < 0) {
                printf("\nERROR: Missing preprocessor control after '#'\n");
                return -1;
            }
            fputs(word, stdout);
            if (strcmp(word, "define") == 0) {
                consume_blanks();
                if (getword(word, MAXSIZE) < 0) {
                    printf("\nERROR: Macro name must be identifier\n");
                    return -1;
                }
                fputs(word, stdout);
                
                c = getchar();
                if (!isspace(c) || c == '\n') {
                    printf("\nERROR: Only support macros without parameters\n");
                    return -1;
                } 
                ungetc(c, stdin);
                consume_blanks();
                getdefine(def, MAXSIZE);
                install(word, def);
                fputs(def, stdout);
            } else if (strcmp(word, "undef") == 0) {
                consume_blanks();
                if (getword(word, MAXSIZE) < 0) {
                    printf("\nERROR: Macro name must be identifier\n");
                    return -1;
                }
                fputs(word, stdout);
                undef(word);
            }

        } else {
            if (c == '\n') {
                newline = true;
            }
            putchar(c);
        }
    }
  
    return 0;
}

