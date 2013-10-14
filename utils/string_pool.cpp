// Author: jrjbear@gmail.com
// Date: Mon Oct 14 22:31:07 2013
//
// File: string_pool.cpp
// Description: Memory pool to store strings of various length


#include <stdio.h>

// Header struct preceding one chunk of memory in this pool to record
// information of this chunk. `size' marks the total size of this chunk
// including Header itself. Note that this struct does not take alignment
// into account.
struct Header {
    Header* p_next;
    int size;
};

// Pointer to the first node of free chunk list.
static Header* p_free = NULL;

void* alloc_mem(int size);
void free_mem(void* ptr);


void* alloc_mem(int size)
{
    const int DFTSIZE = 1 << 20;

    // For convenience, the least memory unit is sizeof(Header).
    int required_num = (size + sizeof(Header) - 1) / sizeof(Header) + 1;
    
    // Search for an appropriate chunk in free list.
    Header* prev = NULL;
    Header* next = NULL;
    for (Header* p = p_free; p != NULL; prev = p, p = p->p_next) {
        if (p->size >= required_num) {
            if (p->size <= required_num + 1) {
                // Exactly fits, use this whole chunk.
                next = p->p_next;
                
            } else {
                // Split this chunk according to `size' and put the
                // remainder into free list.
                next = p + required_num;
                next->p_next = p->p_next;
                next->size = p->size - required_num;
                p->size = required_num;
            }
            
            if (prev == NULL) {
                // The first chunk in free list has been used so we
                // need to assign a new head.
                p_free = next;
            } else {
                prev->p_next = next;
            }

            p->p_next = NULL;
            return (p + 1);
        }
    }

    // Cannot find available chunks in free list, allocate a new chunk.
    int chunk_size = (required_num > DFTSIZE? required_num: DFTSIZE);
    Header* p = new Header[chunk_size];
    p->size = chunk_size;
 
    if (p->size > required_num + 1) {
        // There is empty space left, add them into free list.
        next = p + required_num;
        next->p_next = NULL;
        next->size = p->size - required_num;
        free_mem(next + 1);
    }

    p->p_next = NULL;
    p->size = required_num;
    return (p + 1);    
}

void free_mem(void* ptr)
{
    // Find the pointer to the header of `ptr'.
    Header* cur = (Header*)(ptr) - 1;
    Header* p = p_free;
    Header* prev = NULL;
    for (; p <= cur && p != NULL; prev = p, p = p->p_next) {
        // Search for the first point `p' that is larger than `cur'
        // in terms of the address of header it points to.
        ;
    }

    if (prev != NULL) {
        if (prev + prev->size == cur) {
            // `cur' can be merged into prev.
            prev->size += cur->size;
            cur = prev;
        } else {
            prev->p_next = cur;
        }

    } else {
        // `cur' should be the new head of the list.
        p_free = cur;
    }

    if (cur + cur->size == p) {
        // `p' can be merged into `cur'.
        cur->size += p->size;
        cur->p_next = p->p_next;
    } else {
        cur->p_next = p;
    }
}
