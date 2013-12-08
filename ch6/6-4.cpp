// Author: jrjbear@gmail.com
// Date: Sat Dec  7 17:31:11 2013
//
// File: 6-4.cpp
// Description: Print words in decreasing order of frequency

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "utils/utils.h"

struct TreeNode {
    char* word;
    int count;
    TreeNode* left;
    TreeNode* right;
};

int getword(char s[], int lim);
void qsort(TreeNode* v[], int left, int right);

// Return the address of the new TreeNode. NULL if no TreeNode
// has been created
TreeNode* add_node(TreeNode* root, const char* word);

int main(int argc, char* argv[])
{
    const int MAXWORDS = 1 << 20;
    const int MAXSIZE = 1024;

    int c = -1;
    int pos = 0;
    char word[MAXSIZE];
    TreeNode* nodes[MAXWORDS];
    TreeNode* root = NULL;
    TreeNode* node = NULL;
    while ((c = getword(word, MAXSIZE)) != EOF) {
        if (isalpha(c)) {
            for (char* c = word; *c != '\0'; ++c) {
                *c = tolower(*c);
            }
            
            node = add_node(root, word);
            if (node) {
                root = (root? root: node);
                if (pos >= MAXWORDS) {
                    printf("Max words reached: %d\n", MAXWORDS);
                    break;
                }
                nodes[pos++] = node;
            } 
        }
    }
    qsort(nodes, 0, pos - 1);
    for (int i = pos - 1; i >= 0; --i) {
        printf("%4d %s\n", nodes[i]->count, nodes[i]->word);
    }
    return 0;
}

int getword(char s[], int lim)
{
    static const int MAXLINE = 1024;
    static char line[MAXLINE] = "";
    static int pos = 0;

    int c = line[pos];
    int i = 0;
    s[i] = '\0';
    do {
        if (c == '\0') {
            pos = 0;
            if (my_getline(line, MAXLINE) <= 0) {
                return EOF;
            }
        }	

        do {
            c = line[pos++];
        } while (c == ' ' || c == '\t');
    } while (c == '\0');

    if (isalpha(c)) {
        do {
            s[i++] = c;
            c = line[pos++];
        } while (i < lim - 1 && (isalpha(c) || c == '\''));
        pos--;
        s[i] = '\0';
    } else {
        s[i] = c;
        s[i + 1] = '\0';
    }
    return s[0];
}

TreeNode* add_node(TreeNode* root, const char* word)
{
    if (root == NULL) {
        root = new TreeNode();
        root->word = (char*) alloc_mem(strlen(word) + 1);
        strcpy(root->word, word);
        root->count = 1;
        root->left = root->right = NULL;
        return root;
    } else {
        int ret = strcmp(root->word, word);
        if (ret < 0) {
            TreeNode* n = add_node(root->right, word);
            if (root->right == NULL) {          
                root->right = n;
            }
            return n;
        } else if (ret > 0) {
            TreeNode* n = add_node(root->left, word);
            if (root->left == NULL) {          
                root->left = n;
            }
            return n;
        } else {
            ++ root->count;
            return NULL;
        }
    }
}

void swap(TreeNode* v[], int i, int j);
void qsort(TreeNode* v[], int left, int right)
{
    if (left >= right) {
        return;
    }

    // Select the middle element as the pivot.
    swap(v, left, (left + right) / 2);

    // `last' marks the rightmost element that is less than or equal to pivot.
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if (v[i]->count < v[left]->count) {
            swap(v, ++last, i);
        } 
    }
    
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(TreeNode* v[], int i, int j)
{
    TreeNode* temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
