#ifndef gen_alloc_H
#define gen_alloc_H

#define HEADER_SIZE 24

typedef struct slot_header_T {
   int size;
   int in_use;
   struct slot_header_T * next;
   struct slot_header_T * prev;
   char end[1];
} slot_header;

extern slot_header * mem_head;

void divide_mem_space(void * ptr, unsigned int size);
void merge_mem_space(void * ptr);
void * find_mem_space(unsigned int size);

void print_mem_layout(slot_header * curr);

#endif // gen_alloc_H
