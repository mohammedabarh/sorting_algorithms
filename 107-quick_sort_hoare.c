#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in the array.
 *
 * @array: The array of integers
 * @i: The index of the first element
 * @j: The index of the second element
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme.
 *
 * @array: The array to be partitioned
 * @low: The starting index
 * @high: The ending index
 * 
 * Return: The final position of the pivot
 */
int hoare_partition(int *array, int low, int high)
{
    int pivot = array[low];
    while (1)
    {
        while (array[high] > pivot)
            high--;
        while (array[low] < pivot)
            low++;
        if (low >= high)
            return high;
        swap(array, low, high);
    }
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
        int p = hoare_partition(array, low, high);
        quick_sort_recursive(array, low, p);
        quick_sort_recursive(array, p + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                     the Quick sort algorithm with Hoare partition scheme.
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}
