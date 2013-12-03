// Author: jrjbear@gmail.com
// Date: Tue Dec  3 16:37:07 2013
//
// File: main.cpp
// Description: Convert word description to declaration


#include <stdio.h>
#include <string.h>
#include "undcl.h"

int main(int argc, char* argv[])
{ 
    const int MAXSIZE = 4096;
    char token[MAXSIZE];
    char temp[MAXSIZE];
    char result[MAXSIZE];

    printf("-------------Welcome to Reverse Declaration Parser!-------------\n");
    printf("It reads a sequence of tokens which are more friendly to human\n"
            "and then converts it into a declaration in C. e.g., if you type:\n"
            "x() * [] *() char,\n"
            "which means x is a function returning a pointer to an array of\n"
            "pointers to functions returing char if you read this by order,\n"
            "then it will be transformed into:\n"
            "char(*(*x())[])().\n\n");
    
    printf("Note that this parser doesn't handle parameter list inside a function\n"
           "and type qualifiers like \"const\". Also there is no error recovery.\n\n");

    int type = -1;
    while ((type = gettoken(token)) != EOF) {
        if (type == '\n') {
            continue;

        } else if (type == NAME) {
            strcpy(result, token);
            for (type = gettoken(token); type != '\n' && type != EOF;
                 type = gettoken(token)) {
                if (type == '(') {
                    type = gettoken(token);
                    if (type == ')') {
                        strcat(result, "()");
                    } else {
                        undcl_error("Missing ')' to close a function");
                        break;
                    } 

                } else if (type == '[') {
                    strcat(result, "[");
                    type = gettoken(token);
                    if (type == NUMBER) {
                        strcat(result, token);
                        type = gettoken(token);
                    }
                    if (type == ']') {
                        strcat(result, "]");
                    } else {
                        undcl_error("Missing ']' to close an array");
                        break;
                    }
                
                } else if (type == '*') {
                    strcpy(temp, "*");
                    for (type = gettoken(token); type == '*'; 
                         type = gettoken(token)) {
                        // Successive '*' can be put together without parenthese.
                        strcat(temp, "*");
                    } 
                    strcat(temp, result);

                    if (type != NAME) {
                        sprintf(result, "(%s)", temp);
                    } else {
                        // If the next token is the name of type, parentheses
                        // are not necessary to wrap '*'.
                        strcpy(result, temp);
                    }                       
                    unget_token();

                } else if (type == NAME) {
                    sprintf(temp, "%s %s", token, result);
                    strcpy(result, temp);
                    printf("Declaration is: %s\n", result);
                    type = gettoken(token);
                    break;

                } else {
                    sprintf(temp, "Unknown token: %s", token);
                    undcl_error(temp);
                    break;
                }
            }  
     
        } else {
            undcl_error("Expected a NAME to be the identifier");
        }
        
        if (type != '\n' && type != EOF) {
            printf("Throw away remaining tokens until new line: %s", token);
            for (type = gettoken(token); type != '\n' && type != EOF; 
                 type = gettoken(token)) {
                printf(", %s", token);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
