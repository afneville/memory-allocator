#ifndef arr_alloc_H
#define arr_alloc_H

#define ARR_SIZE 1000

typedef struct slot_header_H {
   int size;
   int in_use;
   struct slot_header_H * next;
   struct slot_header_H * prev;
} slot_header;

// initialisation methods
void * init_arr_allocator();
void destroy_arr_allocator(void * arr);

// allocator methods
void arr_divide_space(void * start, unsigned int size);
void arr_merge_space(void * start);
void * arr_malloc(unsigned int size);
void * arr_calloc(unsigned int size);
void arr_free(void * ptr);

#endif // arr_alloc_H
