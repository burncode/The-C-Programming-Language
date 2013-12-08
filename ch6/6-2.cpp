// Author: jrjbear@gmail.com
// Date: Wed Dec  4 23:33:43 2013
//
// File: 6-2.cpp
// Description: Print words that have identical leading characters

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>             // atoi
#include <getopt.h>
#include "utils/utils.h"

struct TreeNode {
    char* word;
    int count;
    TreeNode* left;
    TreeNode* right;
    TreeNode* prev;
    TreeNode* next;
};

int getword(char s[], int lim);
TreeNode* add_node(TreeNode* root, const char* word);
void print_tree(const TreeNode* root, int match_num);

void print_usage();

int main(int argc, char* argv[])
{
    const int DFTNUM = 6;
    const int MAXSIZE = 1024;

    int opt = -1;
    int match_num = DFTNUM;
    while ((opt = getopt_long(argc, argv, "+n:", NULL, NULL)) != -1) {
        switch (opt) {
        case 'n':
            match_num = atoi(optarg);
            break;
        case '?':
        default:
            print_usage();
            return -1;
        }
    }
    if (optind < argc) {
        print_usage();
        return -1;
    }

    char word[MAXSIZE];
    int c = -1;
    TreeNode* root = NULL;
    while ((c = getword(word, MAXSIZE)) != EOF) {
        if (isalpha(c) || c == '_') {
            root = add_node(root, word);
        }
    }
    print_tree(root, match_num);
    return 0;
}

void print_usage()
{
    printf("Usage: word-group [-n NUM].\n\n");
    printf("Read a C program and print words that have `NUM' identical\n"
           "leading characters. Default value is 6.\n");
}

enum CodeState {
    CODE = 0,
    LINE_COMMENT = 1,
    MULTI_COMMENT = 2,
};

int getword(char s[], int lim)
{
    if (lim <= 1) {
        return EOF;
    }

    int c = -1;
    int i = 0;
    CodeState state = CODE;
    while ((c = getchar()) != EOF) {
        if (state == CODE) {
            while (isspace(c)) {
                c = getchar();
            }
            if (c == '\"' || c == '\'') {
                int quote = c;
                while ((c = getchar()) != quote) {
                    if (c == '\\') {
                        // Skip escape characters
                        c = getchar();
                    } else if (c == '\n') {
                        printf("ERROR: Detected '\\n' inside quote\n");
                        return EOF;
                    } else if (c == EOF) {
                        printf("ERROR: Unclosed quote: %c\n", quote);
                        return EOF;
                    }
                }   
            } else if (c == '/') {
                c = getchar();
                if (c == '/') {
                    state = LINE_COMMENT;
                } else if (c == '*') {
                    state = MULTI_COMMENT;
                } else {
                    ungetc(c, stdin);
                }
            } else if (isalpha(c) || c == '_') {
                // These characters can be the beginning of a word in C
                do {
                    s[i++] = c;
                    c = getchar();
                } while (i < lim - 1 && (isalnum(c) || c == '_'));
                s[i] = '\0';
                ungetc(c, stdin);
                return s[0];
            } else {
                s[i] = c;
                s[i + 1] = '\0';
                return c;                
            }
        } else if (c == '\n' && state == LINE_COMMENT) {
            state = CODE;
        } else if (c == '*' && state == MULTI_COMMENT) {
            if (getchar() == '/') {
                state = CODE;
            }
        }
        // Comment area, don't care
    }
    
    return EOF;
}

TreeNode* add_node_impl(TreeNode* root, const char* word, 
                        TreeNode* prev, TreeNode* next);
TreeNode* add_node(TreeNode* root, const char* word)
{ return add_node_impl(root, word, NULL, NULL); }

void print_tree(const TreeNode* root, int match_num)
{
    const TreeNode* head = root;
    while (head != NULL && head->prev != NULL) {
        head = head->prev;
    }

    const TreeNode* p = head;
    while (p != NULL) {
        const TreeNode* q = p->next;
        for (bool first = true; q != NULL; q = q->next) {
            if (strncmp(p->word, q->word, match_num) == 0) {
                if (first) {
                    printf("%s\n", p->word);
                    first = false;
                } 
                printf("%s\n", q->word);
            } else {
                break;
            }
        }
        p = q;
    }
}

// Maintain a list of inorder traversal. During recursion, `prev'/`next' will
// be modified and passed in continuously so that we can insert the new node
// into the list
TreeNode* add_node_impl(TreeNode* root, const char* word, 
                        TreeNode* prev, TreeNode* next)
{
    if (root == NULL) {
        root = new TreeNode();
        root->word = (char*) alloc_mem(strlen(word) + 1);
        strcpy(root->word, word);
        root->count = 1;
        root->left = root->right = NULL;
        if (prev) {
            prev->next = root;
        }
        root->prev = prev;
        if (next) {
            next->prev = root;
        }
        root->next = next;
    } else {
        int ret = strcmp(root->word, word);
        if (ret < 0) {
            // root->word < word  =>  root can be the previous node
            root->right = add_node_impl(root->right, word, root, next);
        } else if (ret > 0) {
            // word < root->word  =>  root can be the next node
            root->left = add_node_impl(root->left, word, prev, root);
        } else {
            ++ root->count;
        }
    }
    return root;
}
