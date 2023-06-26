#include "lib_tournament_merge.h"

int merge_array_test_time ()
{
    int **Arrays = create_arrays(), *array;

    for (long int i = 1; i <= (long int)*Arrays; i++)
        tournament_sort(*(Arrays + i));

    double start = (double)clock();
    array = merge_array(Arrays);
    printf("\nВремя слияния 8 массивов (по 1000 элементов): %f\n", ((double)clock() - start) / 1000);

    for(int a = 2; a <= *array; a++) {
        if (*(array + a - 1) > *(array + a)) {
            printf("\nСортировка работает неправильно\n");
            break;
        }
    }
        
    return 0;
}


int merge_array_test ()
{
    int **Arrays = create_arrays_(), *array;

    for (long int i = 1; i <= (long int)*Arrays; i++)
        tournament_sort(*(Arrays + i));

    for (long int i = 1; i <= (long int)(*Arrays); i++)
    {
        printf("Array #%ld: ", i);
        for (int j = 1; j <=  *(*(Arrays + i)); j++)
        {
            printf("%d ", *(*(Arrays + i) + j));
        }
        printf("\n");
    }

    array = merge_array(Arrays);

    printf("\nMerged arrays: ");
    for(int i = 1; i <= *array; i++)
        printf("%d ", *(array + i));

    for(int a = 2; a <= *array; a++) {
        if (*(array + a - 1) > *(array + a)) {
            printf("\nСортировка работает неправильно\n");
            break;
        }
    }
        
    return 0;
}
