#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Implements Hoare partition scheme
 * @array: Array to be partitioned
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		if (i != j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * quick_sort_hoare_recursive - Recursive function for quick sort
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = hoare_partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, partition, size);
		quick_sort_hoare_recursive(array, partition + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using quick sort with Hoare partition
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
