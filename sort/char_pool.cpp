#include <stdio.h>

#define DFTSIZE 1 << 10

// Header struct preceding one chunk of memory
// in this pool to record information of this chunk.
// `size' marks the total size of this chunk including Header itself.
// Note that this struct does not take alignment into account.
struct Header {
    Header* p_next;
    int size;
};

// Pointer to the first node of free chunk list.
static Header* p_free = NULL;

void free_mem (void* ptr)
{
    Header* p;
    Header* prev;
    Header* cur;
    
    // Find the pointer to the header of `ptr'.
    cur = (Header*) (ptr) - 1;

    for (p = p_free, prev = NULL; 
         p <= cur && p != NULL; 
         prev = p, p = p->p_next) {
        // Search for the first point `p'
        // that is larger than `cur' in terms of
        // the address of header they point to.
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

void* alloc_mem (int size)
{
    Header* p;
    Header* prev;
    Header* next;
    int nheader, num;

    // For convenience, the least memory unit is sizeof (Header).
    nheader = (size + sizeof (Header) - 1) 
        / sizeof (Header) + 1;
    
    // Search for an appropriate chunk in free list.
    for (p = p_free, prev = NULL; p != NULL; 
         prev = p, p = p->p_next) {
        if (p->size >= nheader) {
            if (p->size <= nheader + 1) {
                // Exactly fits, use this whole chunk.
                next = p->p_next;
                
            } else {
                // Split this chunk according to `size'
                // and put the remainder into free list.
                next = p + nheader;
                next->p_next = p->p_next;
                next->size = p->size - nheader;

                p->size = nheader;
            }
            
            if (prev == NULL) {
                // The first chunk in free list has been used
                // so we need to assign a new head.
                p_free = next;
            } else {
                prev->p_next = next;
            }

            p->p_next = NULL;
            return (p + 1);
        }
    }

    // Cannot find available chunks in free list,
    // allocate a new chunk.
    num = (nheader > DFTSIZE? nheader: DFTSIZE);
    p = new Header[num];
    p->size = num;
 
    if (p->size > nheader + 1) {
        // There is empty space left, put them into free lsit.
        next = p + nheader;
        next->p_next = NULL;
        next->size = p->size - nheader;
        free_mem (next + 1);
    }

    p->p_next = NULL;
    p->size = nheader;
    return (p + 1);    
}

