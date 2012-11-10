/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-24.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#define CODE 0
#define LINE_COMMENT 1
#define MULTI_COMMENT 2
#define MAX 256

static char stack[MAX];
static int top;

int check_quote (char c);
int check_brace (char c);
int check_escape ();

int main () 
{
    int c, state;

    state = CODE;
    top = 0;
    while ((c = getchar ()) != EOF) {
        if (state == CODE) {
            if (c == '\"' || c == '\'') {
                if (check_quote (c) != 0) {
                    return -1;
                }

            } else if (c == '/') {
                c = getchar ();
                if (c == '/') {
                    state = LINE_COMMENT;
                } else if (c == '*') {
                    state = MULTI_COMMENT;
                } else {
                    if (check_brace (c) != 0) {
                        return -1;
                    }
                }

            } else {
                if (check_brace (c) != 0) {
                    return -1;
                }
            }

        } else if (c == '\n' && state == LINE_COMMENT) {
            state = CODE;

        } else if (c == '*' && state == MULTI_COMMENT) {
            if (getchar () == '/') {
                state = CODE;
            }
        }

        // Comment area, do not check this.
    }

    if (state == MULTI_COMMENT) {
        printf ("Unclosed comment");
        return -1;

    } else if (top > 0) {
        printf ("Unmatched brace/bracket/parenthese");
        return -1;

    } else {
        printf ("Check OK");
    }

    return 0;
}


int check_quote (char c) 
{
    if (c == '\"') {
        while ((c = getchar ()) != EOF && c != '\"') {
            if (c == '\\') {
                if (check_escape () != 0) {
                    return -1;
                }
            } else if (c == '\n') {
                printf ("string contains \\n");
                return -1;
            }
        }

        if (c == EOF) {
            printf ("Unclosed double quote");
            return -1;
        }

    } else if (c == '\'') {
        c = getchar ();
        if (c == '\\') {
            if (check_escape () != 0) {
                return -1;
            }
        } else if (c == '\n') {
            printf ("character contains \\n");
            return -1;
        }

        if (getchar () != '\'') {
            printf ("Unclosed single quote");
            return -1;
        }
    }

    return 0;
}

void errorMsg(char *msg) 
{
    printf("%s\n", msg);
    exit(-1);
}

int check_escape () 
{
    static char escapes[] = "abfnrtv?\\\'\"";

    int i, c;
    c = getchar ();
    for (i = 0; escapes[i] != '\0'; i++) {
        if (escapes[i] == c) {
            return 0;
        }
    }
	
    // hexadecimal representaion
    if (c == 'x') {
        for (i = 0; i < 2; i++) {
            c = getchar ();	
            if (!(c >= '0' && c <= '9' 
                  || c >= 'a' && c <= 'f' 
                  || c >= 'A' && c <= 'F')) {
                break;
            }
        }

        if (i == 0) {
            printf ("Illegal escape character: \\x%c", c);
            return -1;
        } else if (i == 1) {
            // This is an 1-digit hexadecimal value, so we
            // put back the next character we read.
            ungetc (c, stdin);
        }

        return 0;
    }

    // octal representation
    for (i = 0; i < 3; i++) {
        if (!(c >= '0' && c <= '7')) {
            break;
        }
        c = getchar ();	
    }
    
    if (i == 0) {
        printf ("Illegal escape character: \\%c", c);
        return -1;
    } else if (i > 0 && i <= 2) {
        // This is an 1/2-digit octal value, so we put back
        // the next character we read.
        ungetc (c, stdin);
    }

    return 0;
}

int check_brace (char c) 
{
    if (c == '{' || c == '[' || c == '(') {
        if (top >= MAX) {
            printf ("Checking stack overflow");
            return -1;
        }
        stack[top++] = c;

    } else if (c == '}' || c == ']' || c == ')') {
        if (top > 0) {
            switch (c) {
            case '}':
                if (stack[--top] == '{') {
                    return 0;
                }
            case ']':
                if (stack[--top] == '[') {
                    return 0;
                }
            case ')':
                if (stack[--top] == '(') {
                    return 0;
                }
            }
        }

        printf ("Unmatched %c", c);
        return -1;
    }

    return 0;
}
