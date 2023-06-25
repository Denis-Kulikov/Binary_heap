#pragma once

#include <stdio.h>
#include <stdlib.h>

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

int heap_init (struct binary_heap *haep, size_t size);
