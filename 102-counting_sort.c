// 102-counting_sort.c
#include "sort.h"

/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *counting, *output;
    size_t i;
    int max = 0;

    if (array == NULL || size < 2)
        return;

    /* Find maximum element */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Create counting array */
    counting = malloc(sizeof(int) * (max + 1));
    if (counting == NULL)
        return;
    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(counting);
        return;
    }

    /* Initialize counting array */
    for (i = 0; i <= (size_t)max; i++)
        counting[i] = 0;

    /* Store count of each element */
    for (i = 0; i < size; i++)
        counting[array[i]]++;

    /* Calculate cumulative count */
    for (i = 1; i <= (size_t)max; i++)
        counting[i] += counting[i - 1];

    print_array(counting, max + 1);

    /* Build output array */
    for (i = size - 1; i < size; i--)
    {
        output[counting[array[i]] - 1] = array[i];
        counting[array[i]]--;
    }

    /* Copy output array to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(counting);
    free(output);
}
