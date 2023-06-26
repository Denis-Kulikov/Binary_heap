#include <stdio.h>
#include <stdlib.h>

#include "lib_heap.h"

int binary_heap_test (size_t size)
{
    struct binary_heap heap;
    struct binary_heap_nodes *max_node;

    printf("Инициализация\n");
    heap_init (&heap, size);

    printf("\nДобавил 6 элементов\n");
    for (int i = 0; i  < 6; i++)
        heap_insert (&heap, rand() % 1000, i);

    if (checking_max_heap_property(heap)) printf("Нарушено свойство кучи\n");
    heap_print (heap);

    printf("\nДобавил 1 элемент\n");
    heap_insert (&heap, rand() % 1000, 10);
    if (checking_max_heap_property(heap)) printf("Нарушено свойство кучи\n");
    heap_print (heap);

    printf("\nУвеличил ключ у 6-го элемента\n");
    heap_increase_key (heap.nodes, 5, 555);
    if (checking_max_heap_property(heap))
        printf("Нарушено свойство кучи\n");
    heap_print (heap);

    printf("\nУдалил максимальный элемент\n");
    max_node = heap_delete_max (&heap);
    printf("Key: %d\nValue: %d\n", max_node->key, max_node->value);
    heap_print (heap);

    heap_free (&heap);
    free(max_node);

    return 0;
}