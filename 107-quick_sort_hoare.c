#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array
 * @array: Array containing elements
 * @i: First index
 * @j: Second index
 */
void swap_elements(int *array, size_t i, size_t j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * hoare_partition - Implements Hoare partition scheme
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_elements(array, i, j);
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare_recursive - Recursive function for quicksort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);
        quick_sort_hoare_recursive(array, low, pivot, size);
        quick_sort_hoare_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array using quicksort with Hoare partition
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursive(array, 0, size - 1, size);
}
