#include "lib_tournament_sort.h"

int tournament_sort_test_time ()
{
    int *array;
    size_t size = 25000;
    double start;
    
    printf("\nЧисло элементов / время работы\n");
    for (int i = 1; i <= 10; i++)
    {
        array = malloc (sizeof(int) * size * i + sizeof(int));
        *array = size * i;
        for (int j = 1; j <= size * i; j++) 
            array[j] = rand();
        start = (double)clock();
        tournament_sort(array);
        printf("%ld\t%f\t%d\n", size * i, ((clock() - start) / 1000000), i);
        for (int j = 2; j <= size * i; j++)
        {
            if (array[j] < array[j - 1])
            {
                printf("Сортировка работает неправильно\n");
                return -1;
            }
        }

        free(array);
    }

    return 0;
}

int tournament_sort_test ()
{
    int array[SIZE_A + 1];
    array[0] = SIZE_A;
    for (int i = 1; i <= SIZE_A; i++) 
        array[i] = rand() % MAX_VALUE + 1;

    printf("\nArray:\t");
    for(int i = 1; i <= array[0]; i++)
        printf("%d ", array[i]);
    
    tournament_sort(array);

    printf("\nSorted array:\t");
    for(int i = 1; i <= array[0]; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}