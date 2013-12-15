// Author: jrjbear@gmail.com
// Date: Sat Dec 14 18:40:07 2013
//
// File: cdefine.h
// Description: Global declarations

#ifndef CDEFEINE_CDEFINE_H_
#define CDEFEINE_CDEFINE_H_

// hash_table.cpp
const char* lookup(const char* s);
// Returns 0 on success, -1 otherwise
int install(const char* name, const char* defn);
int undef(const char* name);

// consume_input.cpp
int getword(char s[], int lim);
int getdefine(char s[], int lim);

// consume_xxx will also put all the characters it read to stdout
// Returns 0 on success, -1 on error
int consume_quote(char quote);
int consume_line_comment();
int consume_multi_comment();
int consume_blanks();

#endif // CDEFEINE_CDEFINE_H_
