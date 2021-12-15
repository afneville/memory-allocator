#include "../inc/arr_alloc.h"
#include "gen_alloc.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

// setup / teardown

void * arr = NULL;

void init_arr_allocator() {
    arr = malloc(ARR_SIZE);
    arr_head = arr;
    memset(arr, 0, ARR_SIZE);
}

void destroy_arr_allocator() {
    free(arr);
}

// allocator methods
void * arr_malloc(unsigned int size) {
    if (!arr_head) {
        init_arr_allocator();
        arr_head->size = ARR_SIZE - HEADER_SIZE;
        arr_head->prev = NULL;
        arr_head->next = NULL;
        arr_head->in_use = 0;
    }
    slot_header * new = find_mem_space(size);
    if (!new)
        return NULL;
    divide_mem_space(new, size);
    new->in_use = 1;
    return new->end;
};

void * arr_calloc(unsigned int size) {
    void * ptr = arr_malloc(size);
    memset(ptr, 0, size);
    return ptr;
};
