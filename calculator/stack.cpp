// Author: jrjbear@gmail.com
// Date: Sun Oct  6 13:23:11 2013
//
// File: stack.cpp
// Description: Stack operations

#include <stdio.h>
#include "calc.h"

static const int MAXVAL = 100;

struct StackItem {
    double val;
    char alpha;
};

static int sp = 0;
static StackItem val[MAXVAL];

void push(double f, char c)
{
    if (sp < MAXVAL) {
        StackItem s = {f, c};
        val[sp++] = s;
    } else {
        printf("Stack is full, can't push %g\n", f);
    }
}

double pop()
{
    if (sp > 0) {
        return val[--sp].val;
    } else {
        printf("Stack is empty\n");
        return 0.0;
    }
}

double top()
{
    if (sp > 0) {
        return val[sp - 1].val;
    } else {
        printf("Stack is empty\n");
        return 0.0;
    }
}

char top_alpha()
{
    if (sp > 0) {
        return val[sp - 1].alpha;
    } else {
        printf("Stack is empty\n");
        return '\0';
    }
}

void dup()
{
    if (sp > 0) {
        push(top(), top_alpha());
    } else {
        printf("Stack is empty\n");
    }
}

void swap()
{
    if (sp > 1) {
        StackItem s1 = val[sp - 1];
        StackItem s2 = val[sp - 2];
        val[sp - 1] = s2;
        val[sp - 2] = s1;
    } else {
        printf("Not enough elements for swapping\n");
    }
}

bool empty()
{ return sp == 0; }

void clear()
{ sp = 0; }
