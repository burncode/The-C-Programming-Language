// Author: jrjbear@gmail.com
// Date: Thu Oct  3 01:11:58 2013
//
// File: 1-16.cpp
// Description: Print the longest line


#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"

// Double the size of `buf', and then copy the existing string in it.
// Finally returns the address of the new buffer. Note that the
// memory in older `buf' will be freed inside the function.
char* double_size(char* buf, int size);

int main(int argc, char* argv[])
{
    const int MAXLINE = 10;

    int len = 0;
    int total_len = 0;
    int max_len = 0;
    int size = MAXLINE;
    bool need_resize = false;

    char* longest = new char[size];
    char* buffer = new char[size];

    // Read input into `buffer + total_len' because we
    // may read serveral times for very long lines.
    while ((len = my_getline(buffer + total_len, size - total_len)) > 0) {
        total_len += len;
        if (buffer[total_len - 1] == '\n') {
            // The whole line has been read into `buffer'.
            if (total_len > max_len) {
                max_len = total_len;
                if (need_resize) {
                    delete [] longest;
                    longest = new char[size];
                }
                snprintf(longest, size, "%s", buffer);
            }
            total_len = 0;
            need_resize = false;

        } else if (size == total_len + 1) {
            // We need more space to store the whole line.
            buffer = double_size(buffer, size);
            size *= 2;
            need_resize = true;
        } 
    }

    // Handles the last line ended with EOF rather than '\n'.
    if (total_len > max_len) {
        max_len = total_len;
        if (need_resize) {
            delete [] longest;
            longest = new char[size];
        }
        snprintf(longest, size, "%s", buffer);
    }

    if (max_len > 0) {
        printf("%d\n", max_len);
        printf("%s", longest);
    }

    delete [] longest;
    delete [] buffer;
    return 0;
}

char* double_size(char* buf, int size)
{
    char* tmp = new char[size * 2];
    snprintf(tmp, size * 2, "%s", buf);
    delete [] buf;
    return tmp;
}
