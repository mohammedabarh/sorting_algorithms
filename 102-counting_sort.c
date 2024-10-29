#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max = array[0];
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = calloc(max + 1, sizeof(int));
    output = malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
        count[array[i]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--)
        output[count[array[i - 1]] - 1] = array[i - 1];

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
