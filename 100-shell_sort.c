#include "sort.h"

/**
 * shell_sort - sort array using shell sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j;

	gap = 1;
	while ((size_t)gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; (size_t)i < size; i++)
		{
			j = i;
			while (j >= gap && array[j] < array[j - gap])
			{
				swap(array, size, j, j - gap);
				j = j - gap;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

/**
 * swap - swap elements at positions
 * @array: array to swap elements
 * @size: size of array to swap
 * @first: first position
 * @second: second position
 */
void swap(int *array, size_t size, int first, int second)
{
	int temp;
	if (size < 0)
		return;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}
