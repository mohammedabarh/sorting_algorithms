#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merges a bitonic sequence in ascending order.
 *
 * @array: The array to be sorted
 * @low: The starting index
 * @cnt: The number of elements to merge
 * @dir: The direction of the merge (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        for (int i = low; i < low + k; i++)
        {
            if ((dir == 1 && array[i] > array[i + k]) || (dir == 0 && array[i] < array[i + k]))
            {
                swap(array, i, i + k);
            }
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts the array in a bitonic sequence.
 *
 * @array: The array to be sorted
 * @low: The starting index
 * @cnt: The number of elements to sort
 * @dir: The direction of the sort (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;

        bitonic_sort_recursive(array, low, k, 1); // Sort in ascending order
        bitonic_sort_recursive(array, low + k, k, 0); // Sort in descending order
        bitonic_merge(array, low, cnt, dir); // Merge the whole sequence
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1); // Sort in ascending order
}
