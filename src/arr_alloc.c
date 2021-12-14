#include "../inc/arr_alloc.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

// setup / teardown

void * arr = NULL;
slot_header * arr_head = NULL;

void init_arr_allocator() {
    arr = malloc(ARR_SIZE);
    arr_head = arr;
    memset(arr, 0, ARR_SIZE);
}

void destroy_arr_allocator() {
    free(arr);
}

// allocator methods
void arr_divide_space(void * ptr, unsigned int size) {
    slot_header * start = (slot_header *) ptr;
    slot_header * new = (slot_header *) (start->end + size);
    new->size = start->size - size - HEADER_SIZE;
    new->prev = start;
    new->next = start->next;
    new->in_use = 0;
    if (new->next)
        new->next->prev = new;
    start->size = size;
    start->next = new;
};

void arr_merge_space(void * ptr) {
    slot_header * freed = (slot_header *) ptr;
    slot_header * next = freed->next;
    if (next && next->in_use == 0) {
        freed->next = next->next;
        if (next->next)
            next->next->prev = freed;
        freed->size = freed->size + next->size + HEADER_SIZE;
    }
    slot_header * prev = freed->prev;
    if (prev && prev->in_use == 0) {
        prev->size = prev->size + freed->size + HEADER_SIZE;
        prev->next = freed->next;
        if(freed->next)
          (freed->next)->prev = prev;
    }

};

void * arr_find_space(unsigned int size) {
    slot_header * curr = arr_head;
    while (curr) {
        if (curr->in_use == 0 && curr->size >= size + HEADER_SIZE) // space will be split into two chunks, so it must be large enough for size and a new header.
            return curr;
        curr = curr->next; 
    }
    return NULL;
};

void * arr_malloc(unsigned int size) {
    if (!arr_head) {
        init_arr_allocator();
        arr_head->size = ARR_SIZE - HEADER_SIZE;
        arr_head->prev = NULL;
        arr_head->next = NULL;
        arr_head->in_use = 0;
    }
    slot_header * new = arr_find_space(size);
    if (!new)
        return NULL;
    arr_divide_space(new, size);
    new->in_use = 1;
    return new->end;
};

void * arr_calloc(unsigned int size) {
    void * ptr = arr_malloc(size);
    memset(ptr, 0, size);
    return ptr;
};

void arr_free(void * ptr) {
    slot_header * header = (slot_header *) ((char *) ptr) - HEADER_SIZE;
    if (header >= arr_head && header <= (slot_header *) ((char *) arr) + ARR_SIZE) {
       header->in_use = 0; 
    }
};


void print_slot_header(slot_header * ptr) {
    printf("%d %d\n", ptr->in_use, ptr->size);
};

void print_slot_headers(slot_header * head_ptr);
