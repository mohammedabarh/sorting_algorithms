#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets maximum value in array
 * @array: Array to find max value from
 * @size: Size of array
 * Return: Maximum integer in array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts array of integers using Counting sort algorithm
 * @array: Array to sort
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max, i;
	size_t j;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	/* Initialize count array with zeros */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Store count of each element */
	for (j = 0; j < size; j++)
		count[array[j]]++;

	/* Update count[i] to store actual position */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Print counting array */
	print_array(count, max + 1);

	/* Build output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy output array to original array */
	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}
