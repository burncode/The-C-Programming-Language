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
#include "detab.h"

int getop (const char* arg, char* s)
{
    int ret;

    ret = NUMBER;
    if (*arg == BEGIN || *arg == INC) {
        ret = *arg;
        arg++;
    }

    while (isdigit (*arg)) {
        *s++ = *arg++;
    }
    *s = '\0';
    
    if (*arg != '\0') {
        ret = UNKNOWN;
    }

    return ret;
}

