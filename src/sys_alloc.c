#include "../inc/sys_alloc.h"
#include "gen_alloc.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void * brkpoint = NULL;

slot_header * increase_breakpoint(unsigned int size) {
    brkpoint = sbrk(0);
    slot_header * rv = brkpoint;
    if(sbrk((10 * size) + HEADER_SIZE) == (void *) -1) return NULL;
    rv->in_use = 0;
    rv->next = NULL;
    rv->prev = mem_tail;
    rv->size = 10 * size;
    mem_tail->next = rv;
    mem_tail = rv;
    return rv;
};

void * sys_malloc(unsigned int size) {
    brkpoint = sbrk(0);
    if (!mem_head) {
        if(sbrk((10 * size) + HEADER_SIZE) == (void *) -1) return NULL;
        mem_head = brkpoint;
        mem_head->in_use = 0;
        mem_head->next = NULL;
        mem_head->prev = NULL;
        mem_head->size = 10 * size; 
        mem_tail = brkpoint;
    }
    slot_header * new = find_mem_space(size);
    if (!new) {
        new = increase_breakpoint(size);
        if (!new) return NULL;
        slot_header * prev = new->prev;
        if (prev->in_use == 0) merge_mem_space(new);
        new = prev;
    }
    divide_mem_space(new, size);
    new->in_use = 1;
    return new->end;
};

void * sys_calloc(unsigned int size) {
    void * ptr = sys_malloc(size);
    memset(ptr, 0, size);
    return ptr;
};

void sys_free(void * ptr) {
    slot_header * header = (slot_header *) (((char *) ptr) - HEADER_SIZE);
    if (header >= mem_head && header <= (slot_header *) brkpoint) {
        header->in_use = 0;
        merge_mem_space(header);
    }
};
