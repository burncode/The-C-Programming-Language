// Author: jrjbear@gmail.com
// Date: Thu Oct  3 19:02:06 2013
//
// File: 1-24.cpp
// Description: Check basic syntac of C like quotes, braces


#include <stdio.h>

enum CodeState {
    CODE = 0,
    LINE_COMMENT = 1,
    MULTI_COMMENT = 2,
};

// Check escape characters from `stream', which will consume
// the characters from `stream' on success. Otherwise, it
// will be put back into `stream'.
int check_escape(FILE* stream);

int main(int argc, char* argv[])
{
    const int MAX = 256;

    char stack[MAX];
    int top = 0;

    int c = -1;
    CodeState state = CODE;
    while ((c = getchar()) != EOF) {
        if (state == CODE) {
            if (c == '\"' || c == '\'') {
                int quote = c;
                int num_ch = 0;
                while (true) {
                    c = getchar();
                    if (c == '\\') {
                        check_escape(stdin);
                    } else if (c == quote) {
                        break;
                    } else if (c == '\n') {
                        printf("Detected \\n inside quote\n");
                        return -1;
                    } else if (c == EOF) {
                        printf("Unclosed quote: %c\n", quote);
                        return -1;
                    }
                    ++num_ch;
                }   
                if (quote == '\'' && num_ch > 1) {
                    printf("Multiple characters inside single quote\n");
                }

            } else if (c == '/') {
                c = getchar();
                if (c == '/') {
                    state = LINE_COMMENT;
                } else if (c == '*') {
                    state = MULTI_COMMENT;
                } else {
                    ungetc(c, stdin);
                }

            } else if (c == '{' || c == '[' || c == '(') {
                if (top >= MAX) {
                    printf("Checking stack overflow: %d\n", MAX);
                    return -1;
                }
                stack[top++] = c;

            } else if (c == '}' || c == ']' || c == ')') {
                bool match = false;
                if (top > 0) {
                    switch (stack[--top]) {
                    case '{':
                        if (c == '}') {
                            match = true;
                        }
                        break;
                    case '[':
                        if (c == ']') {
                            match = true;
                        }
                        break;
                    case '(':
                        if (c == ')') {
                            match = true;
                        }
                        break;
                    default:
                        printf("Impossible to reach here\n");
                        break;
                    }
                }
                if (!match) {
                    printf("Unmatched %c\n", stack[top]);
                    return -1;
                }                
            }

        } else if (c == '\n' && state == LINE_COMMENT) {
            state = CODE;

        } else if (c == '*' && state == MULTI_COMMENT) {
            if (getchar() == '/') {
                state = CODE;
            }
        }

        // Comment area, do not check this.
    }

    if (state == MULTI_COMMENT) {
        printf("Unclosed comment\n");
        return -1;
    } else if (top > 0) {
        printf("Unclosed %c\n", stack[--top]);
        return -1;
    } else {
        printf("Check OK\n");
    }

    return 0;
}

int check_escape(FILE* stream) 
{
    static const char escapes[] = "abfnrtv?\\\'\"";

    int c = getc(stream);
    for (int i = 0; escapes[i] != '\0'; i++) {
        if (escapes[i] == c) {
            return 0;
        }
    }
    
    // hexadecimal representaion.
    if (c == 'x') {
        int i = 0;
        for (; i < 2; ++i) {
            c = getc(stream);
            if (!(c >= '0' && c <= '9' 
                  || c >= 'a' && c <= 'f' 
                  || c >= 'A' && c <= 'F')) {
                ungetc(c, stdin);
                break;
            } 
        }
        if (i == 0) {
            printf("Illegal escape character: \\x%c\n", c);
            return -1;
        } else {
            return 0;
        }
    }

    // octal representation or just '\0'.
    if (c == '0') {
        for (int i = 0; i < 3; ++i) {
            c = getc(stream);
            if (!(c >= '0' && c <= '7')) {
                ungetc(c, stdin);
                break;
            }
        }
        return 0;
    }
    
    return 0;
}
