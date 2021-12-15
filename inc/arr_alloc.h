#ifndef arr_alloc_H
#define arr_alloc_H

// divide, merge and find memory
#include "./gen_alloc.h"

// definitions & delcarations
#define ARR_SIZE 1000

extern void * arr;
extern slot_header * arr_head;

// initialisation methods for array allocator
void init_arr_allocator();
void destroy_arr_allocator();

// array allocator methods
void * arr_malloc(unsigned int size);
void * arr_calloc(unsigned int size);
void arr_free(void * ptr);

#endif // arr_alloc_H
