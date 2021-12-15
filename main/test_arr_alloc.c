
#include <stdio.h>
#include <stdlib.h>
#include "../inc/arr_alloc.h"

int main() {
    int * test1 = (int *) arr_malloc(sizeof(int) * 20);
    if (!test1) exit(0);
    // printf("%p\n", test1);
    // for (int i = 0; i < 5; i++) {
    //     test1[i]= i;
    // }
    // for (int i = 0; i < 5; i++) {
    //     printf("%d\n", test1[i]);
    // }
    int * test2 = (int *) arr_malloc(sizeof(int) * 5);
    if (!test2) exit(0);
    arr_free(test1);
    int * test3 = (int *) arr_malloc(sizeof(int) * 40);
    if (!test3) exit(0);
    int * test4 = (int *) arr_malloc(sizeof(int) * 5);
    if (!test4) exit(0);
    print_mem_layout((slot_header *) (((char *) test1) - HEADER_SIZE));
    // int * test3 = (int *) arr_malloc(sizeof(int) * 2);
    // if (!test3)
    //     exit(0);
    // printf("%p\n", test3);
    // int * test4 = (int *) arr_malloc(sizeof(int) * 2);
    // if (!test4)
    //     exit(0);
    // printf("%p\n", test4);
    return 0;
}
