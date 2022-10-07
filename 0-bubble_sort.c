#include "sort.h"

/**
 * bubble_sort - sort array using bubble sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		int swapped = 0;

		for (j = 0; j < size; j++)
		{
			if (j != size - 1 && array[j] > array[j + 1])
			{
				int temp;

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			};
		}
		if (!swapped)
			break;
	}
}
