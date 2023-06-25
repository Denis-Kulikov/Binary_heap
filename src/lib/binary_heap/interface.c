#include "lib_heap.h"


void heap_print_max (struct binary_heap heap)
{
    struct binary_heap_node *nodes;
    nodes = heap_max (heap);
    if (nodes != NULL)
        printf("\nKey = %d\nValue = %d\n", nodes->key, nodes->value);
    else
        printf("\nНет узлов\n");
}


struct binary_heap_node* heap_max (struct binary_heap heap)
{
    if (heap.n == 0)
        return HEAP_EMPTY;
    
    return &heap.nodes[0];
}

void heap_print (struct binary_heap heap)
{
    printf("\nHeap: ");
    for (int i = 0; i < heap.m; i++)
        printf("%d ", heap.nodes[i].key);
    printf("\n");
}

void heapifyup (struct binary_heap_node *nodes, int index)
{
    while ((nodes[index].key > nodes[index / 2].key) && (index > 0))
    {
        SWAP_NODES(nodes[index], nodes[index / 2]);
        index /= 2;
    }
}

int heap_insert (struct binary_heap *heap, int key, int value)
{
    if (heap->n == heap->m)
        return HEAP_OVERFLOW;
    
    heap->nodes[heap->n].key    = key;
    heap->nodes[heap->n].value  = value;
    
    heapifyup (heap->nodes, heap->n);

    heap->n += 1;        

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
