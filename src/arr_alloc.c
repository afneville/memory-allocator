#include "../inc/arr_alloc.h"
#include "stdlib.h"
#include <string.h>

// setup / teardown

void * arr = NULL;
slot_header * arr_head = NULL;

void init_arr_allocator() {
    arr = malloc(ARR_SIZE);
    arr_head = arr;
    memset(arr, 0, ARR_SIZE);
}

void destroy_arr_allocator() {
    free(arr);
}

// allocator methods
void arr_divide_space(void * ptr, unsigned int size) {};

void arr_merge_space(void * ptr) {
    slot_header * freed = (slot_header *) ptr;
    slot_header * next = freed->next;
    if (next && next->in_use == 0) {
        freed->next = next->next;
        if (next->next)
            next->next->prev = freed;
        freed->size = freed->size + next->size + HEADER_SIZE;
    }
    slot_header * prev = freed->prev;
    if (prev && prev->in_use == 0) {
        prev->size = prev->size + freed->size + HEADER_SIZE;
        prev->next = freed->next;
        if(freed->next)
          (freed->next)->prev = prev;
    }

};

void * arr_find_space(unsigned int size) {
    return NULL;
};

void * arr_malloc(unsigned int size) {
    return NULL;
};

void * arr_calloc(unsigned int size) {
    void * ptr = arr_malloc(size);
    memset(ptr, 0, size);
    return ptr;
};

void arr_free(void * ptr) {
    slot_header * header = (slot_header *) ((char *) ptr) - HEADER_SIZE;
    if (header >= arr_head && header <= (slot_header *) ((char *) arr) + ARR_SIZE) {
        
    }
};
