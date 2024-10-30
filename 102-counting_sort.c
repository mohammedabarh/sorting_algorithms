#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: Array to find max value from
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *counting_array, *output, max, i;

    if (!array || size < 2)
        return;

    max = get_max(array, size);
    counting_array = malloc(sizeof(int) * (max + 1));
    if (!counting_array)
        return;

    output = malloc(sizeof(int) * size);
    if (!output)
    {
        free(counting_array);
        return;
    }

    /* Initialize counting array */
    for (i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Count occurrences */
    for (i = 0; i < (int)size; i++)
        counting_array[array[i]]++;

    /* Calculate cumulative count */
    for (i = 1; i <= max; i++)
        counting_array[i] += counting_array[i - 1];

    print_array(counting_array, max + 1);

    /* Build output array */
    for (i = size - 1; i >= 0; i--)
    {
        output[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy output array to original array */
    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(counting_array);
    free(output);
}
