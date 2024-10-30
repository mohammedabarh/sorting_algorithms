#include "sort.h"

/**
 * merge - Merges two subarrays
 * @array: Original array
 * @left: Left subarray
 * @right: Right subarray
 * @size: Size of original array
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2 || array == NULL)
		return;

	mid = size / 2;

	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));

	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}

	for (size_t i = 0; i < mid; i++)
		left[i] = array[i];
	for (size_t i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);

	free(left);
	free(right);
}
