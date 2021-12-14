#include "../inc/arr_alloc.h"
#include "stdlib.h"

// initialisation methods
void * init_arr_allocator() {
    void * ptr = malloc(ARR_SIZE);
    return ptr;
}

void destroy_arr_allocator(void * arr) {
    free(arr);
}

void arr_divide_space(void * start, unsigned int size) {};

void arr_merge_space(void * start) {};

void * arr_malloc(unsigned int size) {
    return NULL;
};

void * arr_calloc(unsigned int size) {
    return NULL;
};

void arr_free(void * ptr) {};
