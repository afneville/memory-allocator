#include "../inc/gen_alloc.h"
#include <stdlib.h>
#include <stdio.h>

slot_header * mem_head = NULL;
slot_header * mem_tail = NULL;

void merge_mem_space(void * ptr) {
    slot_header * freed = (slot_header *) ptr;
    slot_header * next = freed->next;
    if (next && next->in_use == 0) {
        freed->next = next->next;
        if (next->next)
            next->next->prev = freed;
        freed->size = freed->size + next->size + HEADER_SIZE;
        if (next == mem_tail)
            mem_tail = freed;
    }
    slot_header * prev = freed->prev;
    if (prev && prev->in_use == 0) {
        prev->size = prev->size + freed->size + HEADER_SIZE;
        prev->next = freed->next;
        if (freed->next)
          (freed->next)->prev = prev;
        if (freed == mem_tail)
            mem_tail = prev;
    }

};

void * find_mem_space(unsigned int size) {
    slot_header * curr = mem_head;
    while (curr) {
        if (curr->in_use == 0 && curr->size >= size + HEADER_SIZE)
            return curr;
        curr = curr->next; 
    }
    return NULL;
};

void divide_mem_space(void * ptr, unsigned int size) {
    slot_header * start = (slot_header *) ptr;
    slot_header * new = (slot_header *) (start->end + size);
    new->size = start->size - size - HEADER_SIZE;
    new->prev = start;
    new->next = start->next;
    new->in_use = 0;
    if (new->next)
        new->next->prev = new;
    if (mem_tail == start)
        mem_tail = new;
    start->size = size;
    start->next = new;
};

void print_mem_layout(slot_header * curr) {
    printf("+----------------+\n");
    printf("| %p |\n", curr);
    printf("| %d\n", curr->size);
    printf("| %d              |\n", curr->in_use);
    printf("+----------------+\n");
    if (curr->next) {
        printf("\n");
        print_mem_layout(curr->next);
    }
    return;
}
