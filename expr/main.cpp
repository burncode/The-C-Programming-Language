// Author: jrjbear@gmail.com
// Date: Sun Oct 13 20:48:34 2013
//
// File: main.cpp
// Description: A simple reverse Polish expression processor


#include <stdio.h>
#include <stdlib.h>             // atof
#include <math.h>
#include "expr.h"

void print_usage();

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        print_usage();
        return -1;
    }

    double op = 0;
    while (--argc > 0) {
        int type = check_type (*++argv);
        switch (type) {
        case NUMBER:
            push(atof (*argv));
            break;

        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op = pop();
            push(pop() - op);
            break;
        case '%':
            op = pop();
            if (op == 0.0) {
                printf("Zero divisor\n");
            } else {
                push(fmod(pop(), op));
            }
            break;
        case '/':
            op = pop();
            if (op == 0.0) {
                printf("Zero divisor\n");
            } else {
                push(pop() / op);
            }
            break;
        case '^':
            op = pop();
            push(pow (pop(), op));
            break;

        case ERROR:
            printf("Wrong format of token: %s\n", *argv);
            print_usage();
            return -1;
        default:
            printf("Unknown token: %c\n\n", type);
            print_usage();
            return -1;
        }
    }
    
    op = pop();
    if (!empty()) {
        printf("Stack is not emtpy, bad expression\n");
        print_usage();
        return -1;
    }
    printf("Result is: %f\n", op);
    return 0;
}

void print_usage()
{
    printf("Usage: expr token1 token2 ... .\n\n");

    printf("This is a reverse Polish expression processor. Support digit numbers\n"
            "and negative numbers. Note that spaces are needed to separate tokens.\n"
            "Arithmetic commands: \'+\', \'-\', \'*\', \'/\', \'%%\', \'^\'.\n\n");
}
