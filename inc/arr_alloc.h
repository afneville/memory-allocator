#ifndef arr_alloc_H
#define arr_alloc_H

// definitions & delcarations
#define ARR_SIZE 1000
#define HEADER_SIZE 24

typedef struct slot_header_T {
   int size;
   int in_use;
   struct slot_header_T * next;
   struct slot_header_T * prev;
   char end[1];
} slot_header;

extern void * arr;
extern slot_header * arr_head;

// initialisation methods
void init_arr_allocator();
void destroy_arr_allocator();

// allocator methods
void arr_divide_space(void * ptr, unsigned int size);
void arr_merge_space(void * ptr);
void * arr_find_space(unsigned int size);
void * arr_malloc(unsigned int size);
void * arr_calloc(unsigned int size);
void arr_free(void * ptr);

#endif // arr_alloc_H
