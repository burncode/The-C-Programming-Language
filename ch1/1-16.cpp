#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int my_getline (char line[], int lim);
void copy (char dst[], char src[]);

// Enlarge *p_buf, which means we also copy
// the existing string in *p_buf into the
// new space.
int resize (char** p_buf, int size);

int main () 
{
    int len, max_len, total_len, size;
    bool need_resize;

    total_len = max_len = 0;
    need_resize = false;
    size = MAXLINE;

    char* longest = new char[size];
    char* buffer = new char[size];

    // Read input into buffer + total_len because we
    // may read serveral times for very long lines.
    while ((len = my_getline 
            (buffer + total_len, size)) > 0) {
        total_len += len;
        if (buffer[total_len - 1] == '\n') {
            // The whole line has been read into buffer.
            if (total_len > max_len) {
                max_len = total_len;
                if (need_resize) {
                    delete [] longest;
                    longest = new char[size];
                }
                copy (longest, buffer);
            }
            total_len = 0;
            need_resize = false;

        } else {
            // We need more space to store the whole line.
            size = resize (&buffer, size);
            need_resize = true;
        }
    }

    if (max_len > 0) {
        printf ("%d\n", max_len);
        printf ("%s", longest);
    }

    delete [] longest;
    delete [] buffer;
    return 0;
}

int my_getline (char s[], int lim)
{
    int c, i;

    // i < lim - 1 because we should leave at least
    // one space for \0.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        // Here i can never be lim - 1, because
        // the loop condition above has already
        // check i < lim - 1 when c == \n.
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy (char dst[], char src[]) 
{
    int i = 0;
    while ((dst[i] = src[i]) != '\0') {
        i++;
    }
}

int resize (char** p_buf, int size)
{
    char* tmp = new char[size * 2];
    copy (tmp, *p_buf);
    delete [] *p_buf;
    *p_buf = tmp;
    return size * 2;
}
