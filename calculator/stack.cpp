/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: stack.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push (double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf ("Stack is full, can't push %g\n", f);
    }
}

double pop ()
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf ("Stack is empty\n");
        return 0.0;
    }
}

double top ()
{
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("Stack is empty\n");
        return 0.0;
    }
}

void dup ()
{
    if (sp > 0) {
        push (top ());
    } else {
        printf ("Stack is empty\n");
    }
}

void swap ()
{
    double f1, f2;
    if (sp > 1) {
        f1 = val[sp - 1];
        f2 = val[sp - 2];
        val[sp - 1] = f2;
        val[sp - 2] = f1;
    } else {
        printf ("Not enough elements for swapping\n");
    }
}

void clear()
{ sp = 0; }
