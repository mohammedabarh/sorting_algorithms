#include "sort.h"

/**
 * get_max - Gets the maximum element from an array
 * @array: Array to search
 * @size: Size of the array
 * Return: Maximum element
 */
int get_max(int *array, size_t size)
{
    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_radix - Performs counting sort on a specific digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current digit position
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output, *count;
    size_t i;

    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    count = malloc(sizeof(int) * 10);
    if (!count)
    {
        free(output);
        return;
    }

    /* Initialize count array */
    for (i = 0; i < 10; i++)
        count[i] = 0;

    /* Store count of occurrences */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] to contain actual position */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build output array */
    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy output array to array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

/**
 * radix_sort - Sorts an array using radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}
