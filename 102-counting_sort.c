#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets maximum value in array
 * @array: Array to find max value from
 * @size: Size of array
 * Return: Maximum integer in array
 */
int get_max(int *array, size_t size)
{
        size_t i;
        int max;

        max = array[0];
        for (i = 1; i < size; i++)
        {
                if (array[i] > max)
                        max = array[i];
        }
        return (max);
}

/**
 * counting_sort - Sorts array of integers using Counting sort algorithm
 * @array: Array to sort
 * @size: Size of array
 * Description: Prints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
        int *count, *output;
        int max, i;
        size_t j;

        if (!array || size < 2)
                return;

        max = get_max(array, size);
        count = malloc(sizeof(int) * (max + 1));
        if (!count)
                return;

        output = malloc(sizeof(int) * size);
        if (!output)
        {
                free(count);
                return;
        }

        for (i = 0; i <= max; i++)
                count[i] = 0;

        for (j = 0; j < size; j++)
                count[array[j]]++;

        for (i = 1; i <= max; i++)
                count[i] += count[i - 1];

        print_array(count, max + 1);

        for (i = size - 1; i >= 0; i--)
        {
                output[count[array[i]] - 1] = array[i];
                count[array[i]]--;
        }

        for (j = 0; j < size; j++)
                array[j] = output[j];

        free(count);
        free(output);
}
