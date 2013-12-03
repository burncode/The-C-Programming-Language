// Author: jrjbear@gmail.com
// Date: Sat Nov 30 15:55:26 2013
//
// File: gettoken.cpp
// Description: Get the next token from stdin


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "utils/utils.h"
#include "undcl.h"

static const int MAXLINE = 1024;

static char line[MAXLINE] = "";
static int nlines = 0;
static int pos = 0;
static int last_pos = 0;


int gettoken(char s[])
{
    int c = line[pos];
    int i = 0;
    s[i] = '\0';

    do {
        if (c == '\0') {
            pos = 0;
            clear();
            if (my_getline(line, MAXLINE) <= 0) {
                return EOF;
            }
        }	

        do {
            c = line[pos++];
        } while (c == ' ' || c == '\t');
    } while (c == '\0');

    push(pos - 1);
    if (isalpha(c) || c == '_') {
        // Name must begin with a character or an underscore.
        do {
            s[i++] = c;
            c = line[pos++];
        } while (isalnum(c) || c == '_');
        pos--;
        s[i] = '\0';

        if (strcmp(s, "const") == 0) {
            return CONST;
        } else {
            return NAME;
        }
    }

    // We do not support digit number here since it isn't
    // necessary in this program.
    if (!isdigit(c)) {
        s[i] = c;
        s[i + 1] = '\0';
        return c;
    }
   
    do {
        s[i++] = c;
        c = line[pos++];
    } while (isdigit(c));
    pos--;
    s[i] = '\0';
    return NUMBER;
}

void unget_token()
{ 
    if (!empty()) {
        pos = pop();
    }
}

void undcl_error(const char* err)
{ printf("ERROR(Pos %d): %s\n", top() + 1, err); }
