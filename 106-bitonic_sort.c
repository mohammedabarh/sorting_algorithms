#include "sort.h"

/**
 * bitonic_merge - Merges bitonic sequences
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction to sort (1 for ascending, 0 for descending)
 * @size: Size of the original array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t i, k = count / 2;
	int temp;

	if (count > 1)
	{
		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		bitonic_merge(array, low, k, dir, size);
		bitonic_merge(array, low + k, k, dir, size);
	}
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction to sort (1 for ascending, 0 for descending)
 * @size: Size of the original array
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count,
		int dir, size_t size)
{
	size_t k = count / 2;

	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", count, size,
				dir ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, low, k, 1, size);
		bitonic_sort_recursive(array, low + k, k, 0, size);
		bitonic_merge(array, low, count, dir, size);

		printf("Result [%lu/%lu] (%s):\n", count, size,
				dir ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array using bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2 || (size & (size - 1)) != 0)
		return;

	bitonic_sort_recursive(array, 0, size, 1, size);
}
