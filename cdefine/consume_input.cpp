// Author: jrjbear@gmail.com
// Date: Sat Dec 14 18:27:15 2013
//
// File: consume_input.cpp
// Description: Consume input from stdin to fetch words


#include <ctype.h>
#include <stdio.h>

int getword(char s[], int lim)
{
    if (lim <= 1) {
        return -1;
    }

    int i = 0;
    int c = getchar();
    if (isalpha(c) || c == '_') {
        // These characters can be the beginning of a keyword
        do {
            s[i++] = c;
            c = getchar();
        } while (i < lim - 1 && (isalnum(c) || c == '_'));
    }
    s[i] = '\0';
    ungetc(c, stdin);
    return (i > 0? i: -1); 
}
 
int getdefine(char s[], int lim)
{
    if (lim <= 1) {
        return -1;
    }
    
    int i = 0;
    int c = getchar();
    while (c != '\n' && c != EOF && i < lim -1) {
        s[i++] = c;
        if (c == '\\') {
            c = getchar();
            if (c == '\n') {
                // '\n' has been escaped so we continue
                s[i++] = c;
            } else {
                ungetc(c, stdin);
            }
        }
        c = getchar();
    }
    ungetc(c, stdin);
    s[i] = '\0';
    return i;
}

               
int consume_quote(char quote)
{
    int c = -1;
    while ((c = getchar()) != quote) {
        if (c == '\n') {
            printf("\nERROR: Detected '\\n' inside quote\n");
            return -1;
        } else if (c == EOF) {
            printf("\nERROR: Unclosed quote: %c\n", quote);
            return -1;
        } else {
            putchar(c);
            if (c == '\\') {
                // Skip escape characters
                putchar(getchar());
            }
        }
    }
    return 0;
}

int consume_line_comment()
{
    int c = getchar();
    while (c != '\n' && c != EOF) {
        putchar(c);
        c = getchar();
    }
    ungetc(c, stdin);
    return 0;
}

int consume_multi_comment()
{
    int c = -1;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == '*') {
            c = getchar();
            if (c == '/') {
                putchar(c);
                break;
            }
            ungetc(c, stdin);
        }
    }
    if (c == EOF) {
        printf("\nERROR: Unclosed comment\n");
        return -1;
    }
    return 0;
}

int consume_blanks()
{
    int c = getchar();
    while (isspace(c) && c != '\n') {
        putchar(c);
        c = getchar();
    }
    ungetc(c, stdin);
    return 0;
}
