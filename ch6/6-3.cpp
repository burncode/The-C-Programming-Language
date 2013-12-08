// Author: jrjbear@gmail.com
// Date: Sat Dec  7 15:07:46 2013
//
// File: 6-3.cpp
// Description: Generate an index of all words followed by the
// line numbers on which each word occurs

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "utils/utils.h"

struct ListNode {
    int line;
    ListNode* next;
};

struct TreeNode {
    char* word;
    ListNode* line_list;
    TreeNode* left;
    TreeNode* right;
};

int getword(char s[], int lim, int* line);
int binary_search(const char* word, const char* arr[], int n);

TreeNode* add_node(TreeNode* root, const char* word, int line);
void print_tree(const TreeNode* root);

int main(int argc, char* argv[])
{
    // Noisy words sorted lexicographically
    const char* black_list[] = {
        "a", "am", "an", "and", "are",
        "be", "he", "her", "him", "his",
        "i", "is", "it", "me", "my", 
        "not", "or", "she", "the", 
        "their", "them", "they", "to",
        "was", "were", "you", "your",
    };
    const int NWORDS = sizeof(black_list) / sizeof(black_list[0]);
    const int MAXSIZE = 1024;

    char word[MAXSIZE];
    int c = -1;
    int line = -1;
    TreeNode* root = NULL;
    while ((c = getword(word, MAXSIZE, &line)) != EOF) {
        if (isalpha(c)) {
            for (char* c = word; *c != '\0'; ++c) {
                *c = tolower(*c);
            }
            if (binary_search(word, black_list, NWORDS) < 0) {
                root = add_node(root, word, line);
            }
        }
    }
    print_tree(root);
    return 0;
}

int getword(char s[], int lim, int* line)
{
    static const int MAXLINE = 1024;
    static char line_buf[MAXLINE] = "";
    static int pos = 0;
    static int nlines = 0;

    int c = line_buf[pos];
    int i = 0;
    s[i] = '\0';
    do {
        if (c == '\0') {
            pos = 0;
            if (my_getline(line_buf, MAXLINE) <= 0) {
                return EOF;
            }
            nlines++;
        }	

        do {
            c = line_buf[pos++];
        } while (c == ' ' || c == '\t');
    } while (c == '\0');

    if (isalpha(c)) {
        do {
            s[i++] = c;
            c = line_buf[pos++];
        } while (i < lim - 1 && (isalpha(c) || c == '\''));
        pos--;
        s[i] = '\0';
    } else {
        s[i] = c;
        s[i + 1] = '\0';
    }
    *line = nlines;
    return s[0];
}

TreeNode* add_node(TreeNode* root, const char* word, int line)
{
    if (root == NULL) {
        root = new TreeNode();
        root->word = (char*) alloc_mem(strlen(word) + 1);
        strcpy(root->word, word);
        root->line_list = new ListNode();
        root->line_list->line = line;
        root->line_list->next = NULL;
        root->left = root->right = NULL;
    } else {
        int ret = strcmp(root->word, word);
        if (ret < 0) {
            root->right = add_node(root->right, word, line);
        } else if (ret > 0) {
            root->left = add_node(root->left, word, line);
        } else {
            ListNode* tmp = new ListNode();
            tmp->line = line;
            tmp->next = root->line_list;
            root->line_list = tmp;
        }
    }
    return root;
 }

void print_tree(const TreeNode* root)
{
    if (root != NULL) {
        print_tree(root->left);
        printf("%20s    %d", root->word, root->line_list->line);
        for (ListNode* p = root->line_list->next; p != NULL; p = p->next) {
            printf(", %d", p->line);
        }
        printf("\n");
        print_tree(root->right);
    }
}

int binary_search(const char* word, const char* arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int ret = strcmp(word, arr[mid]);
        if (ret > 0) {
            low = mid + 1;
        } else if (ret < 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
