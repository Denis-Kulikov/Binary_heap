#include "lib_heap.h"

int heap_increase_key (struct binary_heap_nodes *nodes, int index, int key)
{
    if (nodes[index].key > key)
        return HEAP_INVALID_KEY;

    nodes[index].key = key;
    heapifyup(nodes, index);

    return 0;
}

void heapifydown (struct binary_heap_nodes *nodes, int index, int n)
{
    int largest;
    n--;

    while (index < n)
    {
        largest = index;
        if ((index * 2 + 1 <= n) && (nodes[index * 2 + 1].key > nodes[largest].key)) // левый потомок
            largest = index * 2 + 1;
            
        if ((index * 2 + 2 <= n) && (nodes[index * 2 + 2].key > nodes[largest].key)) // правый
            largest = index * 2 + 2;

        if (&nodes[largest] == &nodes[index])
            break;

        SWAP_NODES(nodes[index], nodes[largest]);
        index = largest;
    }
}

struct binary_heap_nodes* heap_delete_max (struct binary_heap *heap)
{
    struct binary_heap_nodes *max;

    if (heap->m == 0)
        return HEAP_EMPTY;
    max = &heap->nodes[0];
    heap->n -= 1;
    heap->nodes[0] = heap->nodes[heap->n];
    heapifydown(heap->nodes, 0, heap->n);

    return max;
}

void heap_print_max (struct binary_heap heap)
{
    struct binary_heap_nodes *nodes;
    nodes = heap_max (heap);
    if (nodes != NULL)
        printf("\nKey = %d\nValue = %d\n", nodes->key, nodes->value);
    else
        printf("\nНет узлов\n");
}

struct binary_heap_nodes* heap_max (struct binary_heap heap)
{
    if (heap.n == 0)
        return HEAP_EMPTY;
    
    return &heap.nodes[0];
}

void heap_print (struct binary_heap heap)
{
    printf("\nHeap: ");
    for (int i = 0; i < heap.n; i++)
        printf("%d ", heap.nodes[i].key);
    printf("\n");
}

void heapifyup (struct binary_heap_nodes *nodes, int index)
{
    while (nodes[index].key > nodes[(index - 1) / 2].key && index > 0)
    {
        SWAP_NODES(nodes[index], nodes[(index - 1) / 2]);
        index = (index - 1) / 2;
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

int heap_free (struct binary_heap *heap)
{
    if (heap == NULL || heap->nodes == NULL)
        return 1;
    free(heap->nodes);

    return 0;
}

int heap_init (struct binary_heap *heap, size_t size)
{
    heap->m = size;
    heap->n = 0;
    heap->nodes = malloc(sizeof(struct binary_heap_nodes) * size);
    if (heap->nodes == NULL)
        return -1;
    
    return 0;
}
