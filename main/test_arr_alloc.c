#include <stdio.h>
#include <stdlib.h>
#include "../inc/arr_alloc.h"

int main() {
    int * test1 = (int *) arr_malloc(sizeof(int) * 20);
    if (!test1) exit(0);
    int * test2 = (int *) arr_malloc(sizeof(int) * 5);
    if (!test2) exit(0);
    arr_free(test1);
    int * test3 = (int *) arr_malloc(sizeof(int) * 40);
    if (!test3) exit(0);
    int * test4 = (int *) arr_malloc(sizeof(int) * 5);
    if (!test4) exit(0);
    print_mem_layout((slot_header *) (((char *) test1) - HEADER_SIZE));
    arr_free(test4);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    print_mem_layout((slot_header *) (((char *) test1) - HEADER_SIZE));
    printf("\n");
    void * valid = arr_malloc(1000);
    if (!valid)
        printf("invalid request returns NULL\n");
    return 0;
}
