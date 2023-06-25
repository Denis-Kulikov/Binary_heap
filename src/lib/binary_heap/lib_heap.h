#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../src/lib/lib.h"

struct binary_heap_node
{
    int key;
    int value;
};

struct binary_heap
{
    int n; // число элементов
    int m; // размер массива n <= m
    struct binary_heap_node *nodes; 
};

#define SWAP_NODES(a, b)                    \
    {                                       \
        struct binary_heap_node temp = a;   \
        a = b;                              \
        b = temp;                           \
    }

void heapifyup (struct binary_heap_node *nodes, int index);
int heap_insert (struct binary_heap *heap, int key, int value);
int heap_init (struct binary_heap *heap, size_t size);
