/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: gettoken.cpp                                                   **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "dcl.h"

#define MAXLINE 1024

static char line[MAXLINE];
static int nlines = 0;
static int pos = 0;
static int last_pos = 0;


int gettoken (char s[])
{
    static bool read_eof = false;

    int i, c, ret;

    if (read_eof) {
        return EOF;
    }

    while (line[pos] == '\0') {
        if (my_getline (line, MAXLINE) < 0) {
            read_eof = true;
            return EOF;
        } else {
            nlines++;
            pos = 0;
        }
        
        for (c = line[pos]; 
             c == ' ' || c == '\t'; c = line[++pos]) {
            ;
        }
    }

    for (c = line[pos]; 
         c == ' ' || c == '\t'; c = line[++pos]) {
        ;
    }
    last_pos = pos;

    i = 0;
    s[i] = '\0';

    if (isalpha (c) || c == '_') {
        // Name must begin with an alpha or underscore.
        do {
            s[i++] = c;
            c = line[++pos];
        } while (isalnum (c) || c == '_');
        s[i] = '\0';

        if (strcmp (s, "const") == 0) {
            return CONST;
        } else {
            return NAME;
        }
    }

    // We do not support digit number here since it isn't
    // necessary in this program.

    if (!isdigit (c)) {
        pos++;
        return c;
    }
   
    do {
        s[i++] = c;
        c = line[++pos];
    } while (isdigit (c));
    s[i] = '\0';

    return NUMBER;
}

void unget_token ()
{  pos = last_pos; }

void dcl_error (const char* err)
{ printf ("(Line %d, Pos %d) error: %s\n", nlines, last_pos + 1, err); }
