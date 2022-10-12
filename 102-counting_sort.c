#include "sort.h"

/**
 * counting_sort - sort array using counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i = 0;
	int *count_arr, *copy;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	while (i < size)
	{
		copy[i] = array[i];
		if (array[i] > max)
			max = array[i];
		i++;
	}
	count_arr = malloc(sizeof(int) * (max + 1));

	for (i = 0; i <= (size_t)max; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		int current_count = count_arr[array[i]];

		count_arr[array[i]] = current_count + 1;
	}
	for (i = 1; i <= (size_t)max; i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, (size_t)max + 1);

	for (i = 0; i < size; i++)
	{
		int index = count_arr[copy[i]] - 1;

		array[index] = copy[i];
	}

	free(count_arr);
	free(copy);
}
