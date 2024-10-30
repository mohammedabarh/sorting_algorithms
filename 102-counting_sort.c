#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Memory allocation and initialization function
 * @nmemb: Number of elements to allocate
 * @size: Size in bytes of each element
 * Return: Pointer to allocated memory, NULL if failed
 *
 * Description: Allocates memory for an array and initializes to zero
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
        unsigned int i = 0;
        char *p;

        if (nmemb == 0 || size == 0)
                return ('\0');
        p = malloc(nmemb * size);
        if (p == '\0')
                return ('\0');
        for (i = 0; i < (nmemb * size); i++)
                p[i] = '\0';
        return (p);
}

/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Pointer to array to be sorted
 * @size: Size of the array
 *
 * Description: Implements counting sort algorithm to sort integers
 * in non-decreasing order. Prints counting array during process.
 */
void counting_sort(int *array, size_t size)
{
        int index, maximun = 0, *counter = '\0', *tmp = '\0';
        size_t i;

        if (array == '\0' || size < 2)
                return;
        /* Find maximum value in array */
        for (i = 0; i < size; i++)
                if (array[i] > maximun)
                        maximun = array[i];
        counter = _calloc(maximun + 1, sizeof(int));
        tmp = _calloc(size + 1, sizeof(int));
        /* Count occurrences of each element */
        for (i = 0; i < size; i++)
                counter[array[i]]++;
        /* Calculate cumulative count */
        for (index = 1; index <= maximun; index++)
                counter[index] += counter[index - 1];
        print_array(counter, maximun + 1);
        /* Build the sorted array */
        for (i = 0; i < size; ++i)
        {
                tmp[counter[array[i]] - 1] = array[i];
                counter[array[i]]--;
        }
        /* Copy sorted elements back to original array */
        for (i = 0; i < size; i++)
                array[i] = tmp[i];
        free(tmp);
        free(counter);
}
