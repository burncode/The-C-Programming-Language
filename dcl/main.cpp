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
    int ret, type;

    printf("--------------Welcome to Declaration Parser!--------------\n");
    printf("This is a simple grammar parser of C declarations. You can\n"
           "type declarations line by line.\n\n");

    printf("Note that this parser doesn't validate the type and only\n"
           "support one type qualifier: \"const\". Also, you have to give\n"
           "identifier name inside parameter list of a function declaration.\n\n");

    while (true) {
        type = gettoken(token);
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
        
        // Error recovery here is simple since we recognize ';' as
        // delimiter which we think "can't be" mistyped.
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
