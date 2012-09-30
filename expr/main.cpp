/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "expr.h"

#define MAXOP 100

void print_help ();
void do_math_func (const char s[]);

int main (int argc, char* argv[])
{
    int type;
    double op2;

    if (argc <= 1) {
        print_help ();
        return -1;
    }

    while (--argc > 0) {
        type = check_type (*++argv);
        switch (type) {
        case NUMBER:
            push (atof (*argv));
            break;

        case '+':
            push (pop () + pop ());
            break;

        case '*':
            push (pop () * pop ());
            break;

        case '-':
            op2 = pop ();
            push (pop () - op2);
            break;

        case '%':
            op2 = pop ();
            if (op2 == 0.0) {
                printf ("Zero divisor\n");
            } else {
                push (fmod (pop (), op2));
            }
            break;

        case '/':
            op2 = pop();
            if (op2 == 0.0) {
                printf ("Zero divisor\n");
            } else {
                push (pop() / op2);
            }
            break;

        case MATH:
            do_math_func (*argv);
            break;

        case '^':
            op2 = pop ();
            push (pow (pop (), op2));
            break;

        case 't':
            printf ("Top of stack: %f\n", top ());
            break;
            
        case 'd':
            dup ();
            break;

        case 's':
            swap ();
            break;

        case 'c':
            clear ();
            break;
            
        case UNKNOWN:
            printf ("Unkonw token: %s\n\n", *argv);
            print_help ();
            return -1;

        default:
            printf ("Unknown command: %c\n\n", type);
            print_help ();
            return -1;
        }
    }
    
    printf ("%f\n", pop ());

    return 0;
}

void print_help ()
{
    printf ("This is a reverse Polish caculator.\n");
    printf ("Usage: expr token1 token2 ... .\n");
    printf ("Support digit numbers and negative numbers.\n");
    printf ("Note that spaces are needed to separate tokens.\n\n");

    printf ("Arithmetic commands: \'+\', \'-\', \'*\', "
            "\'/\', \'%%\', \'^\'.\n");
    printf ("Mathemetic commands: \'sin\', \'cos\', \'exp\'.\n");
    printf ("Stack commands:\n");
    printf ("\t\'t\' for printing the top element of the stack.\n");
    printf ("\t\'d\' for duplicating the top element of the stack.\n");
    printf ("\t\'s\' for swapping the top 2 element of the stack.\n");
    printf ("\t\'c\' for clearing the stack.\n\n");
}

void do_math_func (const char s[])
{
    if (strcmp (s, "sin") == 0) {
        push (sin (pop ()));
    } else if (strcmp (s, "cos") == 0) {
        push (cos (pop ()));
    } else if (strcmp (s, "exp") == 0) {
        push (exp (pop ()));
    } else {
        printf ("Unknown mathematic command: %s\n", s);
    }
}
