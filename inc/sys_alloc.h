#ifndef sys_alloc_H
#define sys_alloc_H

// divide, merge and find memory
#include "./gen_alloc.h"

extern void * brkpoint;

slot_header * increase_breakpoint(unsigned int size);
// array allocator methods
void * sys_malloc(unsigned int size);
void * sys_calloc(unsigned int size);
void sys_free(void * ptr);


#endif // arr_alloc_H
