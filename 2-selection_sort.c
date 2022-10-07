#include "sort.h"

/**
 * selection_sort - sort an array of integers with selection sort
 * @array: array to test
 * @size: size of array to test
 */
void selection_sort(int *array, size_t size)
{
	int i;

	for (i = 0; (size_t)i < size; i++)
	{
		int min_index;

		min_index = (int)find_min_index(array, size, (size_t)i);
		/*printf("min_number from %d is %d\n", i, array[min_index]);*/
		if (min_index != i)
		{
			int temp;

			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}

/**
 * find_min_index - find index of min element in array from some ind
 * @array: array to test
 * @size: size of array to test
 * @start: index to start search from
 * Return: index of minimum
 */
size_t find_min_index(int *array, size_t size, size_t start)
{
	int min;
	size_t index, i;

	min = array[start];
	index = start;

	for (i = (int)start; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			index = i;
		}
	}

	return (index);
}
