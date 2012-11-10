/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--09--30                                                   **
 *                                                                      **
 * File: dcl.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include "dcl.h"

#define MAXTOKEN 1024

// In general, the rule of thumb about error recovery here is any
// mismatched token T will be given a second chance, thus we assume
// you just missed a token before T. However if T still can't be
// matched, it will be throwed away, thus we recognize T as garbage
// that you accidentally typed in. Note that ';' is recognized as
// delimiter to separate delcarations no matter how many errors
// we encounted before. Thus any recovery attempt will stop after
// reading ';'.

int declaration (char* result)
{
    char token[MAXTOKEN];
    char token2[MAXTOKEN];
    bool is_const, fail;
    int type, ret;
    
    is_const = false;
    fail = false;
    ret = 0;
    
    type = gettoken (token);
    if (type == NAME) {
        type = gettoken (token2);
        if (type == CONST) {
            // T const XXX.
            is_const = true;
        } else {
            unget_token ();
        }

    } else if (type == CONST) {
        is_const = true;
        type = gettoken (token);
        if (type != NAME) {
            fail = true;
        }

    } else {
        fail = true;
    }

    if (fail) {
        dcl_error ("Missing data type of the declaration");
        unget_token ();
        ret--;
    }

    ret += declarator (result);
    strcat (result, " ");
    if (is_const) {
        strcat (result, "const ");
    }
    strcat (result, token);

    return ret;
}


int declarator (char* result)
{
    char tmp[MAXTOKEN];
    char token[MAXTOKEN];
    int type, ret;

    tmp[0] = '\0';
    for (type = gettoken (token); type  == '*'; 
         type = gettoken (token)) {
        type = gettoken (token);
        if (type == CONST) {
            strcat (tmp, " const pointer to");        
        } else {
            strcat (tmp, " pointer to");
            unget_token ();
        }
    }

    unget_token ();
    ret = direct_declarator (result);

    strcat (result, tmp);
    return ret;
}

int direct_declarator (char* result)
{
    // `fail' marks whether the last token failed to be matched or not.
    // If so, this token will be throwed away when it fails again.

    char token[MAXTOKEN];
    int type, ret;
    bool first, fail;

    ret = 0;
    fail = false;
    type = gettoken (token);
    if (type == '(') {
        ret += declarator (result);

        type = gettoken (token);
        if (type != ')') {
            dcl_error ("Missing ')'");
            unget_token ();
            fail = true;
            ret--;
        }

    } else if (type == NAME) {
        strcat (result, token);
        strcat (result, ":");

    } else {
        dcl_error ("Expected name or (declarator)");
        unget_token ();
        fail = true;
        ret--;
    }


    for (type = gettoken (token); 
         type == '[' || type == '(' || (type != ';' && fail); 
         type = gettoken (token)) {
        fail = false;
        if (type == '[') {
            strcat (result, " array");

            type = gettoken (token);
            if (type == NUMBER) {
                strcat (result, "[");
                strcat (result, token);
                strcat (result, "]");

                type = gettoken (token);
            } 

            if (type == ']') {
                strcat (result, " of");
            } else {
                dcl_error ("Missing ']'");
                unget_token ();
                fail = true;
                ret--;
            }
            
        } else if (type == '(') {
            strcat (result, " function");
            first = true;

            for (type = gettoken (token); type != ')' && type != ';' && type != EOF; ) {
                if (first) {
                    strcat (result, " with parameter [");
                    first = false;
                }

                unget_token ();
                ret += declaration (result);

                for (type = gettoken (token); 
                     type != ',' && type != ')' && type != ';' && type != EOF; 
                     type = gettoken (token)) {
                    dcl_error ("Expected ',' or ')' inside function parameter list");
                    ret--;
                }
                    
                if (type == ',') {
                    strcat (result, ", ");
                    type = gettoken (token);
                }
            }

            if (type != ')') {
                dcl_error ("Missing ')'");
                unget_token ();
                fail = true;
                ret--;
            }
            
            if (!first) {
                strcat (result, "]");
            }
            strcat (result, " returning");
        }
    }

    unget_token ();
    return ret;
}
