#pragma once

#include "../src/lib/lib.h"

#define MAX_VALUE 1000000
#define SIZE_A 1000
#define ARRAY_NUMBER 8
#define SIZE_TREE 7

#define SWAP_INT(a, b)  int temp = a;  \
                    a = b;         \
                    b = temp;     

#define PRINT_TREE(tree)    printf("\ntree: "); \
                            for (int i = 1; i <= *tree; i++) {  \
                                if (*(tree + i) != INT_MAX)     \
                                    printf("%d ", *(tree + i)); \
                                else                            \
                                    printf("* ");               \
                            }                                   \
                            getchar();  


int* find_winner(int *tree, int winner, int size);
int HEAPIFYUP(int* tree, int* pos);
int* HEAPIFYDOWN(int *tree);
void shift(int *tree, int** Arrays, int* a_pos, int winner);
int get_winner_tt(int* tree, int size);
int get_winner(int* tree, int size);
int** create_arrays();
int** create_arrays_();

// int* add_leaf(int* tree, int* t_pos, int* a_pos);
// int* tournament_sort_win_lose(int* arr);

int tournament_sort(int* arr);

int* merge_array(int** Arrays);
