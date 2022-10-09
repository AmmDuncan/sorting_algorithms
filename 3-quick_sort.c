#include "sort.h"

/**
 * quick_sort - sort array on integers using quick sort
 *
 * @array: array to sort
 * @size: size of array to sort
 */
void quick_sort(int *array, size_t size)
{
	partition(array, size, 0, (int)size - 1);
}

/**
 * partition - sort array on integers using quick sort
 *
 * @array: array to sort
 * @size: size of array to sort
 * @start: start of part to partition
 * @end: end of part to partition
 */
void partition(int *array, size_t size, int start, int end)
{
	int lower_end, i, pivot;

	if (start >= end)
		return;

	pivot = array[end];
	lower_end = start - 1;
	for (i = start; i < end; i++)
	{
		if (array[i] > pivot)
			continue;
		else
		{
			lower_end++;
			if (lower_end != i)
				swap(array, size, lower_end, i);
		}
	}
	lower_end++;
	if (lower_end != end)
		swap(array, size, lower_end, end);

	partition(array, size, start, lower_end - 1);
	partition(array, size, lower_end + 1, end);
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

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	print_array(array, size);
}
