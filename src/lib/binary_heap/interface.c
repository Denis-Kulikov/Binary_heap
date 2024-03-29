#include "lib_heap.h"

int checking_max_heap_property (struct binary_heap heap)
{
    for (int i = 0; i < heap.n; i++)
    {
        if ((   (heap.nodes[i].key < heap.nodes[i * 2 + 1].key) && (i * 2 + 1) < heap.n)
            || ((heap.nodes[i].key < heap.nodes[i * 2 + 2].key) && (i * 2 + 2) < heap.n))
            return 1;
    }

    return 0;
}

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
    struct binary_heap_nodes *max = malloc(sizeof(struct binary_heap_nodes));

    if (heap->m == 0)
    {
        free(max);
        return HEAP_EMPTY;
    }
    max->key = heap->nodes[0].key;
    max->value = heap->nodes[0].value;
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
    printf("Heap: ");
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
    heap->m = size - 1;
    heap->n = 0;
    heap->nodes = malloc(sizeof(struct binary_heap_nodes) * size);
    if (heap->nodes == NULL)
        return -1;
    
    return 0;
}
