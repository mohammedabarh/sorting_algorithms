#include "sort.h"

/**
 * get_max - Gets the maximum element from an array
 * @array: Array to search
 * @size: Size of the array
 * Return: Maximum element
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_radix - Performs counting sort based on significant digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current significant digit (position)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output;
    int counting[10] = {0};
    size_t i;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    /* Store count of occurrences in counting[] */
    for (i = 0; i < size; i++)
        counting[(array[i] / exp) % 10]++;

    /* Change counting[i] to contain actual position */
    for (i = 1; i < 10; i++)
        counting[i] += counting[i - 1];

    /* Build the output array */
    for (i = size - 1; i < size; i--)
    {
        output[counting[(array[i] / exp) % 10] - 1] = array[i];
        counting[(array[i] / exp) % 10]--;
    }

    /* Copy output array to array[] */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array using radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}
