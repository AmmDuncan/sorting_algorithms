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
	int i, pivot = end;

	if (start >= end)
		return;

	for (i = pivot; i >= start; i--)
	{
		if (array[pivot] < array[i])
		{
			int temp;

			temp = array[pivot];
			array[pivot] = array[i];
			pivot = pivot - 1;
			array[i] = array[pivot];
			array[pivot] = temp;
		}
	}
	print_array(array, size);
	partition(array, size, start, pivot - 1);
	partition(array, size, pivot + 1, end);
}
