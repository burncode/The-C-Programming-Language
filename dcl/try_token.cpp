// Author: jrjbear@gmail.com
// Date: Mon Dec  2 01:04:05 2013
//
// File: try_token.cpp
// Description: Functions that try to match a given type

#include <stdio.h>
#include "dcl.h"

bool try_name(int type)
{ return type == NAME; }

bool try_array_dcl(int type)
{ return (type == '[' || type == NUMBER); }

bool try_right_paran(int type)
{ return type == ')'; }

bool try_right_bracket(int type)
{ return type == ']'; }

bool try_func_array(int type)
{ return (type == '(' || type == '['); }

bool try_func_array_dcl(int type)
{ return (type == '(' || type == '[' || try_declaration(type)); }

bool try_func_param(int type)
{ return (try_declaration(type) || type == ')'); }

bool try_func_comma(int type)
{ return (type == ',' || type == ')'); }

bool try_declaration(int type)
{ return (type == CONST || type == NAME); }

bool try_declarator(int type)
{
    if (type == '*') {
        return true;  
    }
    return try_direct_declarator(type);    
}

bool try_direct_declarator(int type)
{ return (type == '(' || type == NAME); }

int try_tokens_until(char token[], TryFn expect, 
                     TryFn next_expect, const char* err)
{
    const int MAXSIZE = 1024;
    char err_buf[MAXSIZE];
    int type = -1;
    while (true) {
        type = gettoken(token);
        if ((*expect)(type)) {
            break;
        } else if ((*next_expect)(type) || type == EOF || type == '\n') {
            dcl_error(err);
            unget_token();
            break;
        } else {
            sprintf(err_buf, "Unknown token: %s", token);
            dcl_error(err_buf);
        }
    }
    return type;
}
