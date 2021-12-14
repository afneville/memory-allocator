
#include <stdio.h>
#include "../inc/arr_alloc.h"

int main() {
    int * test = (int *) arr_malloc(sizeof(int) * 5);
    if (test) {
        printf("%p\n", test);
        print_slot_header((slot_header *) ( ((char *) test) - HEADER_SIZE));
        print_slot_header((slot_header *) ( ((char *) test) + sizeof(int) * 5));
    }
        
    return 0;
}
