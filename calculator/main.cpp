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
#include "calc.h"

#define MAXOP 100

void do_math_func (char s[]);

int main ()
{
    // begin marks whether it's the beginning of a line.
    int type, i, index;
    bool begin, assign;
    double op, op2, val;
    char s[MAXOP];
    double assignments[26];
	
    for (i = 0; i < 26; i++) {
        assignments[i] = 0;
    }
    begin = true;
    assign = false;
    index = -1;
    val = 0;

    printf ("Welcome to Simple Caculator!\n");
    printf ("This caculator uses reverse Polish notation.\n");
    printf ("Support digit numbers and negative numbers.\n");
    printf ("Note that spaces are needed to separate elements.\n\n");

    printf ("Arithmetic commands: \'+\', \'-\', \'*\', "
            "\'/\', \'%%\', \'^\'.\n");
    printf ("Mathemetic commands: \'sin\', \'cos\', \'exp\'.\n");
    printf ("Stack commands:\n");
    printf ("\t\'t\' for printing the top element of the stack.\n");
    printf ("\t\'d\' for duplicating the top element of the stack.\n");
    printf ("\t\'s\' for swapping the top 2 element of the stack.\n");
    printf ("\t\'c\' for clearing the stack.\n\n");

    printf ("Use [A-Z] for variables to store results.\n");
    printf ("You can assign values to variables, note that\n");
    printf ("in this case variable must appear as the first element\n");
    printf ("and '=' must appear as the last element.\n");
    printf ("For example, \"A ***** =\" is legal so that\n");
    printf ("A will be set to the value of expression in the middle.\n\n");

    printf ("Finally, 'v' stands for the result of the last expression.\n\n");

    while ((type = getop (s)) != EOF) {
        switch (type) {
        case NUMBER:
            push (atof (s));
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
            do_math_func (s);
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
            
        case ALPHA:
            if (begin) {
                index = s[0] - 'A';
            }

            op = assignments[s[0] - 'A'];
            push (op);
            break;
       
        case VAL:
            push (val);
            break;

        case '=':
            if (getop (s) != '\n') {
                printf ("Assignment operator must be the "
                        "last element\n");
                break;
            }

            if (index < 0) {
                printf ("Cannot find symbol to assgin to\n");
            } else {
                assign = true;
            }
            // Fall through since element is '\n' here.

        case '\n':
            val = pop ();
            if (assign) {
                printf ("Assign %f to %c\n", 
                        val, index + 'A');
                assignments[index] = val;
            }
            printf ("%16f\n\n", val);

            index = -1;
            begin = true;
            assign = false;
            clear();

            // continue to escape "begin = false".
            continue;

        default:
            printf ("Unknown command: %c\n", type);
            break;
        }

        begin = false;
    }

    return 0;
}

void do_math_func (char s[])
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
