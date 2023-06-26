#include "lib_tournament_merge.h"

#define SWAP_INT(a, b)  int temp = a;  \
                    a = b;         \
                    b = temp;     

#define LEAF_POS -(number_leaf - (deleted - tree))

int* merge_array(int** Arrays)
{
    int *tree, size = 0, *a_pos, *result, winner, *deleted;
    long int number_leaf = 1, index = (long int)*Arrays;

    if (Arrays == NULL) return NULL;

    while (number_leaf < (long int)*Arrays) {
        size += number_leaf;
        number_leaf *= 2;
    }
    size += number_leaf;

    if (!(tree = (int*)malloc(size * sizeof(int)))) return NULL; 
    for (long int i = 1; i <= size; i++) 
        *(tree + i) = INT_MAX;
    *tree = size;

    if (!(a_pos = (int*)malloc((long int)*Arrays * sizeof(int)))) return NULL;
    for (long int i = 0; i < (long int)*Arrays; i++) 
        *(a_pos + i) = 1;

    size = 0; 
    for (long int i = 1; i <= (long int)*Arrays; i++) 
        size += *(*(Arrays + i));
    if (!(result = (int*)malloc((size + 1) * sizeof(int)))) return NULL; 
    *result = size;

    for (int i = 1; i <= (long int)*Arrays; i++) {
        *(tree + *tree - number_leaf + i) = *(*(Arrays + i) + 1);
        *(a_pos + i - 1) += 1;
    }
    winner = get_winner(tree, number_leaf);


    index = 1;
    while (winner != INT_MAX) {
        *(result + index) = winner;
        index++;

        deleted = HEAPIFYDOWN(tree);
        if (*(a_pos + LEAF_POS) <= *(*(Arrays + 1 + LEAF_POS))) {
            *deleted = *(*(Arrays + 1 + LEAF_POS) + *(a_pos + LEAF_POS));
        }
        *(a_pos + LEAF_POS) += 1;
        
        winner = HEAPIFYUP(tree, deleted);
    }

    free(tree);
    free(a_pos);

    return result;
}

int** create_arrays()
{
    int **Arrays;
    Arrays = malloc(sizeof(int*) * ARRAY_NUMBER);

    *(Arrays) = (int*)ARRAY_NUMBER;

    for (int i = 1; i <= ARRAY_NUMBER; i++) {
        *(Arrays + i) = malloc(sizeof(int*) * SIZE_A + 1);
        **(Arrays + i) = SIZE_A;
        for (long int j = 1; j <= (long int)*(*(Arrays + i)); j++) 
            *(*(Arrays + i) + j) = rand() % MAX_VALUE;
    }
        
    return Arrays;
}

int** create_arrays_()
{
    int **Arrays;
    Arrays = malloc(sizeof(int*) * 4);

    *(Arrays) = (int*)3;

    *(Arrays + 1) = malloc(sizeof(int*) * 4);
    **(Arrays + 1) = 4;

    *(Arrays + 2) = malloc(sizeof(int*) * 2);
    **(Arrays + 2) = 2;

    *(Arrays + 3) = malloc(sizeof(int*) * 3);
    **(Arrays + 3) = 3;

    for (long int i = 1; i <= (long int)*Arrays; i++) 
        for (long int j = 1; j <= (long int)*(*(Arrays + i)); j++) 
            *(*(Arrays + i) + j) = rand() % 20;

    // for (long int i = 1; i <= (long int)*Arrays; i++) {
    //     printf("Array %ld: ", i);
    //     for (int j = 1; j <= *(*(Arrays + i)); j++) 
    //         printf("%d ", *(*(Arrays + i) + j));
    //     printf("\n");
    // }
        
    return Arrays;
}
