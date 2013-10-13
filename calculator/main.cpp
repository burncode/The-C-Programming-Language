// Author: jrjbear@gmail.com
// Date: Sun Oct  6 13:20:49 2013
//
// File: main.cpp
// Description: A simple calculator


#include <stdio.h>
#include <stdlib.h>             // atof
#include <string.h>             // strcmp
#include <math.h>
#include "calc.h"


int main(int argc, char* argv[])
{
    const int MAXOP = 1024;

    printf("-------------Welcome to Simple Caculator!--------------\n"
           "This caculator uses reverse Polish expression. Support digit\n"
           "numbers and negative numbers. Note that spaces are needed\n"
           "to separate elements.\n\n");
    printf("Arithmetic commands: \'+\', \'-\', \'*\', \'/\', \'%%\', \'^\'.\n"
           "Mathemetic commands: \'sin\', \'cos\', \'exp\'.\n"
           "Stack commands:\n"
           "\t\'t\' for printing the top element of the stack.\n"
           "\t\'d\' for duplicating the top element of the stack.\n"
           "\t\'s\' for swapping the top 2 element of the stack.\n"
           "\t\'c\' for clearing the stack.\n\n");
    printf("Use [A-Z] for variables to store results. You can assign\n"
           "values to variables. The assignment operator is '=' and\n"
           "it will take 2 operands. The first operand must be an alpha\n"
           "variable while the value of second one will be the result of\n"
           "this operation.The initial value of all variables is 0.\n\n");
    printf("Finally, 'v' stands for the result of the last expression.\n\n");

    double assignments[26];
    for (int i = 0; i < 26; i++) {
        assignments[i] = 0;
    }
  
    char s[MAXOP];
    char alpha = '\0';
    int type = EOF;
    bool fail = false;
    double op = 0;
    double last_val = 0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
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
                fail = true;
            } else {
                push(fmod(pop(), op));
            }
            break;
        case '/':
            op = pop();
            if (op == 0.0) {
                printf("Zero divisor\n");
                fail = true;
            } else {
                push(pop() / op);
            }
            break;
        case '^':
            op = pop();
            push(pow(pop(), op));
            break;
        case MATH:
            if (strcmp(s, "sin") == 0) {
                push(sin(pop()));
            } else if (strcmp(s, "cos") == 0) {
                push(cos(pop()));
            } else if (strcmp(s, "exp") == 0) {
                push(exp(pop()));
            } else {
                fail = true;
                printf("Unknown mathematic command: %s\n", s);
            }
            break;

        case 't':
            printf("Top of stack: %f\n", top());
            break;
        case 'd':
            dup();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;

        case ALPHA:
            push(assignments[s[0] - 'A'], s[0]);
            break;
        case VAL:
            push(last_val);
            break;
        case '=':
            op = pop();
            alpha = top_alpha();
            if (alpha < 'A' || alpha > 'Z') {
                printf("No alpha variable to assign\n");
                fail = true;
                break;
            }
            assignments[alpha - 'A'] = op;
            printf("Assignment complete: %c = %f\n", alpha, op);
            pop();
            push(op);
            break;
        case '\n':
            last_val = pop();
            if (!empty()) {
                printf("Stack is not emtpy, bad expression\n");
                clear();
                break;
            }
            printf("%16f\n\n", last_val);
            break;

        default:
            printf("Unknown token: %c\n", type);
            fail = true;
            break;
        }

        if (fail) {
            // Discard the whole line on failure.
            do {
                type = getop(s);
            } while (type != '\n' && type != EOF);
            clear();
            fail = false;
        }
    }

    return 0;
}
