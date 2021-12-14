#include <stdio.h>
#include "../inc/arr_alloc.h"

int main() {
    printf("#1#\n");
    init_arr_allocator();
    printf("#2#\n");
    destroy_arr_allocator();
    printf("#3#\n");
    return 0;
}
