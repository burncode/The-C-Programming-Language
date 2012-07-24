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
#include "entab.h"

int getop (const char* arg, char* s)
{
    int ret;
    bool has_digit;

    ret = NUMBER;
    has_digit = false;
    if (*arg == BEGIN || *arg == INC) {
        ret = *arg;
        arg++;
    }

    while (isdigit (*arg)) {
        has_digit = true;
        *s++ = *arg++;
    }
    *s = '\0';
    
    if (*arg != '\0' || !has_digit) {
        ret = UNKNOWN;
    }

    return ret;
}

