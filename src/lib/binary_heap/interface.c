#include "lib_heap.h"

void heapifyup (struct binary_heap_node *nodes, int index)
{
    while ((nodes[index].key > nodes[index / 2].key) && (index > 1))
    {
        SWAP_NODES(nodes[index], nodes[index / 2]);
        index /= 2;
    }
}

int heap_insert (struct binary_heap *heap, int key, int value)
{
    if (heap->n == heap->m)
        return HEAP_OVERFLOW;
    heap->n += 1;        
    
    heap->nodes[heap->n].key    = key;
    heap->nodes[heap->n].value  = value;

    heapifyup (heap->nodes, heap->n);

    return 0;
}

int heap_init (struct binary_heap *heap, size_t size)
{
    heap->m = size;
    heap->n = 0;
    heap->nodes = malloc(sizeof(struct binary_heap_node) * size);
    if (heap->nodes == NULL)
        return -1;
    
    return 0;
}
