/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: getop.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <ctype.h>
#include "tail.h"

int getop (const char* arg, char* s)
{
    if (*arg != '-') {
        return UNKNOWN;
    }

    ++arg;
    while (isdigit (*arg)) {
        *s++ = *arg++;
    }
    *s = '\0';
    
    return (*arg == '\0'? NUMBER: UNKNOWN);
}

