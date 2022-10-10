#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void compare_prevs(listint_t *node, listint_t **list);
void remove_node(listint_t *node);
void insert_bef_n_aft(listint_t *node, listint_t *before, listint_t *after);
void selection_sort(int *array, size_t size);
size_t find_min_index(int *array, size_t size, size_t start);
void quick_sort(int *array, size_t size);
void partition(int *array, size_t size, int start, int end);
void swap(int *array, size_t size, int first, int second);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

#endif
