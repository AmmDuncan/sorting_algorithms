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
	int lower_end, i, pivot, temp;

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
			{
				temp = array[i];
				array[i] = array[lower_end];
				array[lower_end] = temp;
				print_array(array, size);
			}
		}
	}
	lower_end++;
	if (lower_end != end)
	{
		temp = array[lower_end];
		array[lower_end] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	partition(array, size, start, lower_end - 1);
	partition(array, size, lower_end + 1, end);
}
