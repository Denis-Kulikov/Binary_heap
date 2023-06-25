#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../src/lib/lib.h"

#define HEAP_EMPTY NULL

struct binary_heap_nodes
{
    int key;
    int value;
};

struct binary_heap
{
    int n; // число элементов
    int m; // размер массива n <= m
    struct binary_heap_nodes *nodes; 
};

#define SWAP_NODES(a, b)                    \
    {                                       \
        struct binary_heap_nodes temp = a;   \
        a = b;                              \
        b = temp;                           \
    }

int checking_max_heap_property (struct binary_heap heap);
int heap_increase_key (struct binary_heap_nodes *nodes, int index, int key);
void heapifydown (struct binary_heap_nodes *nodes, int index, int n);
struct binary_heap_nodes* heap_delete_max (struct binary_heap *heap);
void heap_print_max (struct binary_heap heap);
struct binary_heap_nodes* heap_max (struct binary_heap heap);
void heap_print (struct binary_heap heap);
void heapifyup (struct binary_heap_nodes *nodes, int index);
int heap_insert (struct binary_heap *heap, int key, int value);
int heap_free (struct binary_heap *heap);
int heap_init (struct binary_heap *heap, size_t size);
