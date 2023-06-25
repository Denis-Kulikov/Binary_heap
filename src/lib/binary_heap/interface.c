#include "lib_heap.h"

int heap_init (struct binary_heap *haep, size_t size)
{
    haep->m = size;
    haep->n = 0;
    haep->nodes = malloc(sizeof(struct binary_heap_node) * size);
    if (haep->nodes == NULL)
        return -1;
    
    return 0;
}