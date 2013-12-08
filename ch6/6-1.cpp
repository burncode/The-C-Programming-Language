// Author: jrjbear@gmail.com
// Date: Tue Dec  3 20:26:35 2013
//
// File: 6-1.cpp
// Description: Count keywords of C

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct Keyword {
    const char* word;
    int count;
} keytab[] = {
    // All keywords in C sorted lexicographically
    "#define", 0,
    "#elif", 0,
    "#else", 0,
    "#error", 0,
    "#if", 0,
    "#ifdef", 0,
    "#ifndef", 0,
    "#include", 0,
    "#line", 0,
    "#pragma", 0,
    "#undef", 0,
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

int getword(char s[], int lim);
int binary_search(const char* word, const Keyword tab[], int n);

int main(int argc, char* argv[])
{
    const int MAXSIZE = 1024;
    const int NKEYS = sizeof(keytab) / sizeof(keytab[0]);
    char word[MAXSIZE];
    int c = -1;

    while ((c = getword(word, MAXSIZE)) != EOF) {
        if (isalpha(c) || c == '#') {
            int n = binary_search(word, keytab, NKEYS);
            if (n >= 0) {
                keytab[n].count++;
            }                
        }
    }
    for (int i = 0; i < NKEYS; ++i) {
        if (keytab[i].count > 0) {
            printf("%4d %s\n", keytab[i].count, keytab[i].word);
        }
    }
    return 0;
}


enum CodeState {
    CODE = 0,
    LINE_COMMENT = 1,
    MULTI_COMMENT = 2,
};

int getword(char s[], int lim)
{
    if (lim <= 1) {
        return EOF;
    }

    int c = -1;
    int i = 0;
    CodeState state = CODE;
    while ((c = getchar()) != EOF) {
        if (state == CODE) {
            while (isspace(c)) {
                c = getchar();
            }
            if (c == '\"' || c == '\'') {
                int quote = c;
                while ((c = getchar()) != quote) {
                    if (c == '\\') {
                        // Skip escape characters
                        c = getchar();
                    } else if (c == '\n') {
                        printf("ERROR: Detected '\\n' inside quote\n");
                        return EOF;
                    } else if (c == EOF) {
                        printf("ERROR: Unclosed quote: %c\n", quote);
                        return EOF;
                    }
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

            } else if (isalpha(c) || c == '_') {
                // These characters can be the beginning of a keyword
                do {
                    s[i++] = c;
                    c = getchar();
                } while (i < lim - 1 && (isalnum(c) || c == '_'));
                s[i] = '\0';
                ungetc(c, stdin);
                return s[0];

            } else if (c == '#') {
                // Preprocessor control line may contain blanks
                s[i++] = c;
                do {
                    c = getchar();
                } while (isspace(c) && c != '\n');
                while (i < lim - 1 && isalpha(c)) {
                    s[i++] = c;
                    c = getchar();
                }
                s[i] = '\0';
                ungetc(c, stdin);
                return s[0];

            } else {
                s[i] = c;
                s[i + 1] = '\0';
                return c;                
            }
        } else if (c == '\n' && state == LINE_COMMENT) {
            state = CODE;
        } else if (c == '*' && state == MULTI_COMMENT) {
            if (getchar() == '/') {
                state = CODE;
            }
        }
        // Comment area, don't care
    }
    
    return EOF;
}

int binary_search(const char* word, const Keyword tab[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int ret = strcmp(word, tab[mid].word);
        if (ret > 0) {
            low = mid + 1;
        } else if (ret < 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
