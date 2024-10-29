#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort_for_radix - Sorts an array of integers using Counting sort
 *                            based on the digit represented by exp.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The digit position to sort by
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *               the Radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_for_radix(array, size, exp);
}
