#include "sort.h"

/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *counting_array, *output;
    size_t i;
    int max = 0;

    if (!array || size < 2)
        return;

    /* Find maximum element */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

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
    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    /* Store count of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Update counting array to store actual positions */
    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];

    print_array(counting_array, max + 1);

    /* Build output array */
    for (i = size - 1; i < size; i--)
    {
        output[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy output array to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(counting_array);
    free(output);
}
