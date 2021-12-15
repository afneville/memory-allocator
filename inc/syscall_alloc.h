#ifndef syscall_alloc_H
#define syscall_alloc_H

// divide, merge and find memory
#include "./gen_alloc.h"

extern void * brkpoint;

slot_header * increase_breakpoint(unsigned int size);
// array allocator methods
void * syscall_malloc(unsigned int size);
void * syscall_calloc(unsigned int size);
void syscall_free(void * ptr);


#endif // syscall_alloc_H
