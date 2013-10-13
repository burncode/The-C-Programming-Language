// Author: jrjbear@gmail.com
// Date: Sun Oct 13 15:18:24 2013
//
// File: stack.cpp
// Description: Stack operations


#include <stdio.h>
#include "expr.h"

static const int MAXVAL = 100;

static int sp = 0;
static double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("Stack is full, can't push %g\n", f);
    }
}

double pop()
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Stack is empty\n");
        return 0.0;
    }
}

double top()
{
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("Stack is empty\n");
        return 0.0;
    }
}

bool empty()
{ return sp == 0; }

void clear()
{ sp = 0; }
