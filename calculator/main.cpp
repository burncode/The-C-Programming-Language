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

int main ()
{
    // `begin' marks whether it's the beginning of a line.
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

    printf ("-------------Welcome to Simple Caculator!--------------\n"
            "This caculator uses reverse Polish notation. Support digit\n"
            "numbers and negative numbers. Note that spaces are needed\n"
            "to separate elements.\n\n");

    printf ("Arithmetic commands: \'+\', \'-\', \'*\', \'/\', \'%%\', \'^\'.\n"
            "Mathemetic commands: \'sin\', \'cos\', \'exp\'.\n"
            "Stack commands:\n"
            "\t\'t\' for printing the top element of the stack.\n"
            "\t\'d\' for duplicating the top element of the stack.\n"
            "\t\'s\' for swapping the top 2 element of the stack.\n"
            "\t\'c\' for clearing the stack.\n\n");

    printf ("Use [A-Z] for variables to store results. You can assign\n"
            "values to variables, note that in this case variable must\n"
            "appear as the first element and '=' must appear as the\n"
            "last element. For example, \"A ***** =\" is legal so that\n"
            "A will be set to the value of expression in the middle.\n\n");

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

            // continue to escape `begin = false'.
            continue;

        default:
            printf ("Unknown command: %c\n", type);
            break;
        }

        begin = false;
    }

    return 0;
}
