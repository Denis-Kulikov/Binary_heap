#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

enum ERRORS
{
    HEAP_OVERFLOW = 1,
    HEAP_INVALID_KEY,
};

int binary_heap_test ();
int tournament_sort_test ();
int tournament_sort_test_time ();
int merge_array_test ();
int merge_array_test_time ();
