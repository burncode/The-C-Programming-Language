// Author: jrjbear@gmail.com
// Date: Tue Dec  3 13:09:06 2013
//
// File: main.cpp
// Description: Simple grammar parser of C declarations


#include <stdio.h>
#include "dcl.h"

int main(int argc, char* argv[])
{
    const int MAXSIZE = 4096;
    char result[MAXSIZE];
    char token[MAXSIZE];

    printf("--------------Welcome to Declaration Parser!--------------\n");
    printf("This is a simple grammar parser of C declarations. You can\n"
           "type declarations line by line.\n\n");

    printf("Note that this parser doesn't validate the type and only\n"
           "support one type qualifier: \"const\". Also, you have to give\n"
           "identifier name of a parameter inside a function declaration.\n"
           "arrar[] may contain constant number to express size. Other\n"
           "expressions are not supported.\n\n");

    while (true) {
        int type = gettoken(token);
        if (type == EOF) {
            break;
        } else if (type == '\n') {
            continue;
        } else {
            unget_token();
            result[0] = '\0';
            int ret = declaration(result);
            if (ret < 0) {
                printf("Fail to parse declaration, %d errors", -ret);
            } else {
                printf("%s", result);
            }
        }

        // Skip all the remaining tokens until new line. It's unnecessary
        // to do error recovery here.
        bool remain = false;
        for (type = gettoken(token); type != '\n' && type != EOF; 
             type = gettoken(token)) {
            if (!remain) {
                printf("\nThrow away remaining tokens until "
                       "new line: %s", token);
                remain = true;
            } else {
                printf(", %s", token);
            }
        }
        printf("\n\n");
    }

    return 0;
}
