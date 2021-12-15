#ifndef arr_alloc_H
#define arr_alloc_H
#include "./gen_alloc.h"
// definitions & delcarations
#define ARR_SIZE 1000

extern void * arr;

// initialisation methods
void init_arr_allocator();
void destroy_arr_allocator();

// allocator methods
void * arr_malloc(unsigned int size);
void * arr_calloc(unsigned int size);

// debugging methods
// void print_slot_header(slot_header * ptr);
// void print_slot_headers(slot_header * head_ptr);

#endif // arr_alloc_H
