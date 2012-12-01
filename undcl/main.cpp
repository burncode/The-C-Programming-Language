/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--11--24                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include "undcl.h"

#define MAXSIZE 4096

int main ()
{
    char token[MAXSIZE];
    char temp[MAXSIZE];
    char result[MAXSIZE];
    int type, err;
    bool has_name;

    printf ("------------Welcome to Reverse Declaration Parser!-------------\n");
    printf ("It reads a sequence of tokens which are more friendly to human\n"
            "and then converts it into a declaration in C. e.g., if you input:\n"
            "x () * [] * () char,\n"
            "which means x is a function returning a pointer to an array of\n"
            "pointers to functions returing char if you read this by order,\n"
            "then it will be transformed into:\n"
            "char (*(*x())[])().\n\n");
    
    printf ("Note that this parser doesn't handle parameter list inside a function\n"
            "and type qualifiers like \"const\". '\\n' is used to separate each\n"
            "sequence of tokens.\n\n");

    while ((type = gettoken (token)) != EOF) {
        err = 0;
        has_name = false;

        if (type == '\n') {
            continue;

        } else if (type != NAME) {
            undcl_error ("Expected a name to begin with");
            err++;

        } else {
            strcpy (result, token);
            for (type = gettoken (token); 
                 type != '\n' && type != EOF;
                 type = gettoken (token)) {
                if (type == '(') {
                    type = gettoken (token);
                    if (type == ')') {
                        strcat (result, "()");
                    } else {
                        undcl_error ("Missing ')'");
                        err++;
                        break;
                    } 

                } else if (type == '[') {
                    strcat (result, "[");
                    type = gettoken (token);
                    if (type == NUMBER) {
                        strcat (result, token);
                        type = gettoken (token);
                    }

                    if (type == ']') {
                        strcat (result, "]");
                    } else {
                        undcl_error ("Missing ']'");
                        err++;
                        break;
                    }
                
                } else if (type == '*') {
                    strcpy (temp, "*");
                    // Successive '*' can be put together without parenthese.
                    for (type = gettoken (token);
                         type == '*'; type = gettoken (token)) {
                        strcat (temp, "*");
                    }

                    strcat (temp, result);
                    if (type != NAME) {
                        sprintf (result, "(%s)", temp);
                    } else {
                        // If the next token is the type name, parentheses
                        // are not necessary to wrap '*'.
                        strcpy (result, temp);
                    }                       
                    unget_token ();

                } else if (type == NAME) {
                    sprintf (temp, "%s %s", token, result);
                    strcpy (result, temp);

                    type = gettoken (token);
                    if (type == '\n') {
                        printf ("Declaration is: %s\n\n", result);
                        has_name = true;
                    } else {
                        undcl_error ("Expected '\\n' to end this declaration");
                        err++;
                    }
                    break;

                } else {
                    sprintf (temp, "Invalid input: %s", token);
                    undcl_error (temp);
                    err++;
                    break;
                }
            }       
        }

        if (!has_name && err == 0) {
            undcl_error ("Expected a name to be the type");
        }

        for (; type != '\n' && type != EOF;
             type = gettoken (token)) {
            ;
        }
    }

    return 0;
}
