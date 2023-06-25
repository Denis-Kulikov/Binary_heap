#include <stdio.h>
#include <stdlib.h>

#include "lib_heap.h"

int binary_heap_test (size_t size)
{
    struct binary_heap heap;
    struct binary_heap_node *nodes;
    heap_init (&heap, size);

    for (int i = 0; i  < size; i++)
        heap_insert (&heap, rand() % 1000, i);

    heap_print (heap);
    heap_print_max (heap);

    return 0;
}