// Author: jrjbear@gmail.com
// Date: Sat Nov 30 21:01:12 2013
//
// File: dcl.cpp
// Description: Parse tokens into declarations


#include <string.h>
#include <stdio.h>
#include "dcl.h"

// On reading a token, we try to match it to any possible rules at
// the current position. If that fails, this token will be given a
// second chance to match any rules at the next position. If it
// fails again, this token will be thrown away. As a result, errors
// such as missing one token or multiple redundant tokens can be
// handled well.

const int MAXTOKEN = 1024;

int declaration(char* result)
{
    char token[MAXTOKEN];
    char token2[MAXTOKEN];
    bool is_const = false;
    int type = -1;
    int ret = 0;
    
    ret -= try_tokens_until(&type, token, try_declaration, try_declarator, 
                            "Missing data type to form a declaration");
    if (type == NAME) {
        if (gettoken(token2) == CONST) {
            // T const XXX
            is_const = true;
        } else {
            unget_token();
        }

    } else if (type == CONST) {
        is_const = true;
        ret -= try_tokens_until(&type, token, try_name, try_declarator,
                                "Missing data type to form a declaration");
    } 

    ret += declarator(result);
    strcat(result, " ");
    if (is_const) {
        strcat(result, "const ");
    }
    strcat(result, token);
    return ret;
}


int declarator(char* result)
{
    char tmp[MAXTOKEN] = "";
    char token[MAXTOKEN];

    for (int type = gettoken(token); type == '*'; type = gettoken(token)) {
        type = gettoken(token);
        if (type == CONST) {
            strcat(tmp, " const pointer to");
        } else {
            strcat(tmp, " pointer to");
            unget_token();
        }
    }

    unget_token();
    int ret = direct_declarator(result);
    strcat(result, tmp);
    return ret;
}

int direct_declarator(char* result)
{
    char token[MAXTOKEN];
    int type = -1;
    int ret = 0;

    ret -= try_tokens_until(&type, token, try_direct_declarator,
                            try_func_array, "Missing declarator's name");
    if (type == '(') {
        ret += declarator(result);
        ret -= try_tokens_until(&type, token, try_right_paran, try_func_array,
                                "Missing ')' to close a declarator");
    } else if (type == NAME) {
        strcat(result, token);
        strcat(result, ":");
    }

    while (true) {
        type = gettoken(token);
        if (type == '[') {
            strcat(result, " array");
            ret -= try_tokens_until(&type, token, try_array, try_func_array,
                                    "Missing ']' to close an array");
            if (type == NUMBER) {
                strcat(result, "[");
                strcat(result, token);
                strcat(result, "]");
                ret -= try_tokens_until(&type, token, try_right_bracket, 
                                        try_func_array,
                                        "Missing ']' to close an array");
            }
            if (ret == 0) {
                strcat(result, " of");
            }
            
        } else if (type == '(') {
            strcat(result, " function");
            bool has_param = false;
            while (true) {
                ret -= try_tokens_until(&type, token, try_func_param, 
                                        try_func_array,
                                        "Missing ')' to close a function");
                if (try_declaration(type)) {
                    if (!has_param) {
                        strcat(result, " with parameter [");
                        has_param = true;
                    }
                    unget_token();
                    ret += declaration(result);
                    ret -= try_tokens_until(&type, token, try_func_comma, 
                                            try_func_array_dcl,
                                            "Missing ')' to close a function");
                    if (type == ',') {
                        strcat(result, ", ");
                        continue;
                    } else if (try_declaration(type)) {
                        continue;
                    } else {
                        // Fall through to break
                    }
                } 
                break;
            }
            if (ret == 0) {
                if (has_param) {
                    strcat(result, "]");
                }
                strcat(result, " returning");
            }

        } else {
            // Don't try to do error recovery here. Simply ends a
            // direct declarator and leaves the remaining tokens
            // to the outside.
            unget_token();
            break;
        }
    }

    return ret;
}
