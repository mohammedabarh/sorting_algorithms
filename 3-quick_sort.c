#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned
 * @low: The starting index
 * @high: The ending index
 * 
 * Return: The final position of the pivot
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick sort.
 *
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quick_sort_recursive(array, low, pi - 1);
        quick_sort_recursive(array, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *               the Quick sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}
