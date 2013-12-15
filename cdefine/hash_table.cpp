// Author: jrjbear@gmail.com
// Date: Sun Dec  8 19:11:39 2013
//
// File: hash_table.cpp
// Description: A simple open hash table

#include <string.h>
#include "utils/utils.h"

const int HASHSIZE = 1572869;

struct DefEntry {
    DefEntry* next;
    char* name;
    char* defn;
};

static DefEntry* hashtab[HASHSIZE];


static size_t hash(const char* s)
{
    size_t val = 0;
    for (; *s != '\0'; ++s) {
        val = *s + 31 * val;
    }
    return val % HASHSIZE;
}

const char* lookup(const char* s)
{
    for (DefEntry* e = hashtab[hash(s)]; e != NULL; e = e->next) {
        if (strcmp(e->name, s) == 0) {
            return e->defn;
        }
    }
    return NULL;
}

int install(const char* name, const char* defn)
{
    DefEntry* e = NULL;
    size_t hashval = hash(name);
    for (e = hashtab[hashval]; e != NULL; e = e->next) {
        if (strcmp(e->name, name) == 0) {
            break;
        }
    }
    if (e) {
        free_mem(e->defn);
    } else {
        e = new DefEntry();
        e->next = hashtab[hashval];
        e->name = (char*) alloc_mem(strlen(name) + 1);
        strcpy(e->name, name);
        hashtab[hashval] = e;
    }
    e->defn = (char*) alloc_mem(strlen(defn) + 1);
    strcpy(e->defn, defn);
    return 0;
}

int undef(const char* name) 
{
    size_t hashval = hash(name);
    DefEntry* prev = NULL;
    DefEntry* e = NULL;
    for (e = hashtab[hashval]; e != NULL; e = e->next, prev = e) {
        if (strcmp(e->name, name) == 0) {
            break;
        }
    }
    if (e) {
        free_mem(e->name);
        free_mem(e->defn);
        if (prev) {
            prev->next = e->next;
        } else {
            hashtab[hashval] = NULL;
        }
        delete e;
    }
    return 0;   
}
