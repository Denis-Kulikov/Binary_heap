#include "lib_tournament_sort.h"

int* add_leaf(int* tree, int* t_pos, int* a_pos)
{
    if (*(tree + (t_pos - tree) / 2) <= *a_pos) {
        SWAP_INT(*t_pos, *a_pos)
    } else {
        *t_pos = *(tree + (t_pos - tree) / 2);
        *(tree + (t_pos - tree) / 2) = *a_pos;
    }
    
    return tree + (t_pos - tree) / 2;
}

int* find_winner(int *tree, int winner, int size)
{
    int *pos = tree + *tree - size + 1;
    while (pos <= tree + *tree) {
        if (*pos == winner) 
            return pos;

        pos++;
    }

    return NULL;
}

int* HEAPIFYDOWN(int *tree)
{
    int *cur = tree + 1; 

    while (tree + (cur - tree) * 2 < tree + *tree) {
        if (*(tree + (cur - tree) * 2) == *cur) 
            cur = tree + (cur - tree) * 2;
        else 
            cur = tree + (cur - tree) * 2 + 1;

    }
    *cur = INT_MAX;

    return cur;
}

void shift(int *tree, int** Arrays, int* a_pos, int winner)
{
    for (long int i = 1; i <= (long int)*Arrays ; i++) {
        if (*(*(Arrays + i) + *(a_pos + i - 1)) == winner) {
            (*(a_pos + i - 1))++;
            break;
        }
    }
}

int HEAPIFYUP(int* tree, int* pos)
{
    pos = tree + (pos - tree) / 2;

    while (pos > tree) {
        if (*(tree + (pos - tree) * 2) <= *(tree + (pos - tree) * 2 + 1)) 
            *pos = *(tree + (pos - tree) * 2);
        else 
            *pos = *(tree + (pos - tree) * 2 + 1);


        pos = tree + (pos - tree) / 2;
    }

    return *(tree + 1);
}

int get_winner(int* tree, int leaves)
{
    int *cur = tree + *tree - leaves; 

    while (cur > tree) {
        if (*(tree + (cur - tree) * 2) <= *(tree + (cur - tree) * 2 + 1)) 
            *cur = *(tree + (cur - tree) * 2);
        else 
            *cur = *(tree + (cur - tree) * 2 + 1);

        cur--;
    }

    return *(tree + 1);
}

int get_winner_(int* tree, int size)
{
    int *cur = tree + *tree - size, winner; 

    while (cur > tree) {
        if (*(tree + (cur - tree) * 2) <= *(tree + (cur - tree) * 2 + 1)) {
            if (*cur > *(tree + (cur - tree) * 2)) {
                SWAP_INT(*cur, *(tree + (cur - tree) * 2));
            }
        } else {
            if (*cur > *(tree + (cur - tree) * 2 + 1)) {
                SWAP_INT(*cur, *(tree + (cur - tree) * 2 + 1));
            }
        }

        cur--;
    }

    winner = *(tree + 1);
    *(tree + 1) = INT_MAX;

    return winner;
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
            *(*(Arrays + i) + j) = rand() % MAX_VALUE;

    for (long int i = 1; i <= (long int)*Arrays; i++) {
        printf("Array %ld: ", i);
        for (int j = 1; j <= *(*(Arrays + i)); j++) 
            printf("%d ", *(*(Arrays + i) + j));
        printf("\n");
    }
        
    return Arrays;
}

int tournament_sort(int* arr)
{
    int *tree, number_leaf  = 1, size = 0, *pos = 0, index = *arr, winner;

    if (arr == NULL) return 0;

    while (number_leaf <= *arr) {
        size += number_leaf;
        number_leaf *= 2;
    }
    size += number_leaf;

    if (!(tree = (int*)malloc(size * sizeof(int)))) return 0;
    for (long int i = 1; i <= size; i++) 
        *(tree + i) = INT_MAX;
    *tree = size;

    pos = tree + *tree - number_leaf;
    for (int i = 1; i <= *arr; i++)
        *(pos + i) = *(arr + i);

    winner = get_winner(tree, number_leaf);

    index = 1;
    while (winner != INT_MAX && index <= *arr) {
        *(arr + index) = winner;
        index++;

        winner = HEAPIFYUP(tree, HEAPIFYDOWN(tree));

    }

    free(tree);
    
    return 1;
}
