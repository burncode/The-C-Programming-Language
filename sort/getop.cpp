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
#include "sort.h"

int getop (const char* arg, char* s)
{
    int ret;
    bool has_char;

    has_char = false;
    if (*arg == '-') {
        ret = FLAG;
        
        while (isalpha (*++arg)) {
            *s++ = *arg;
            has_char = true;
        }
        
    } else {
        ret = NUMBER;

        while (isdigit (*arg)) {
            *s++ = *arg++;
            has_char = true;
        }
    }

    *s = '\0';
    return (*arg == '\0' && has_char? ret: UNKNOWN);
}

