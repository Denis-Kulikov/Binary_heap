#include <stdio.h>
#include <stdlib.h>

#include "lib_heap.h"

int binary_heap_test (size_t size)
{
    struct binary_heap heap;
    heap_init (&heap, size);

    for (int i = 0; i  < size; i++)
        heap_insert (&heap, rand() % 1000, 0);
        // heap_insert (&heap, i, 0);

    heap_print(heap);

    return 0;
}