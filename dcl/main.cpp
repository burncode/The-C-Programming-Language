/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--11--04                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include "dcl.h"

#define MAXSIZE 4096

int main ()
{
    char result[MAXSIZE];
    char token[MAXSIZE];
    int ret, type;

    printf ("------------Welcome to Declaration Parser!--------------\n");
    printf ("It reads the declarations in C/C++. ';' is required to\n"
            "separate declarations.\n\n");

    printf ("Note that this parser does not check type, which means\n"
            "anything appears in that position will be regarded as a\n"
            "type name. Also we only support one type qualifier: \"const\".\n"
            "Another restriction is that you will have to give identifier\n"
            "name in the parameter list of a function declaration.\n\n");

    type = gettoken (token);
    while (type != EOF) {
        // Unget this token which was used to test against EOF.
        unget_token ();

        result[0] = '\0';
        ret = declaration (result);
        if (ret < 0) {
            printf ("Fail to parse declaration, %d errors\n\n", -ret);
        } else {
            printf ("%s\n\n", result);
        }

        // Error recovery here is simple since we recognize ';' as
        // delimiter which we think "can't be" mistyped.
        for (type = gettoken (token); 
             type != ';' && type != EOF; type = gettoken (token)) {
            dcl_error ("Expected ';' to separate declarations");
        }

        // Test whether it is EOF right after ';'.
        type = gettoken (token);
    }

    return 0;
}
