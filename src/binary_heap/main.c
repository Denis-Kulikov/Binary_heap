#include "../lib/lib.h"

int main ()
{
    printf("\n\033[92mПроверка бинарной кучи:\033[39m\n");
    binary_heap_test (10);

    printf("\n\033[92mПроверка сортировки:\033[39m\n");
    tournament_sort_test ();
    tournament_sort_test_time ();

    printf("\n\033[92mПроверка слияния массивов:\033[39m\n");
    merge_array_test ();
    merge_array_test_time ();

    return 0;
}