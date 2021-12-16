#include <stdio.h>
#include <stdlib.h>
#include "../inc/syscall_alloc.h"

int main() {
//    int * test1 = (int *) sys_malloc(sizeof(int) * 20);
//    if (!test1) exit(0);
//    int * test2 = (int *) sys_malloc(sizeof(int) * 5);
//    if (!test2) exit(0);
//    sys_free(test1);
//    int * test3 = (int *) sys_malloc(sizeof(int) * 40);
//    if (!test3) exit(0);
//    int * test4 = (int *) sys_malloc(sizeof(int) * 5);
//    if (!test4) exit(0);
//    sys_free(test4);
//    print_mem_layout((slot_header *) (((char *) test1) - HEADER_SIZE));
//    printf("\n");
//    printf("\n");
//    printf("\n");
//    printf("\n");
//    char * test5 = (char *) sys_malloc(500);
//    if (!test5) exit(0);
//    print_mem_layout((slot_header *) (((char *) test1) - HEADER_SIZE));
//

    char * start = (char *) syscall_malloc(1000);
    print_mem_layout((slot_header *) (((char *) start) - HEADER_SIZE));
    printf("\n\n\n");
    syscall_free(start);
    print_mem_layout((slot_header *) (((char *) start) - HEADER_SIZE));
    printf("\n\n\n");
    char * one = (char *) syscall_malloc(100);
    char * two = (char *) syscall_malloc(10);
    print_mem_layout((slot_header *) (((char *) start) - HEADER_SIZE));
    printf("\n\n\n");
    syscall_free(one);
    char * three = (char *) syscall_malloc(10);
    char * four = (char *) syscall_malloc(100);
    print_mem_layout((slot_header *) (((char *) start) - HEADER_SIZE));
    printf("\n\n\n");
    return 0;
}
