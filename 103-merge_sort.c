#include "sort.h"

/**
 * merge - Merges two subarrays
 * @array: Original array
 * @left: Left subarray
 * @left_size: Size of left subarray
 * @right: Right subarray
 * @right_size: Size of right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc(sizeof(int) * (left_size + right_size));

    if (!temp)
        return;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < left_size)
        temp[k++] = left[i++];

    while (j < right_size)
        temp[k++] = right[j++];

    for (i = 0; i < left_size + right_size; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);
    free(temp);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
    size_t mid, i;
    int *left, *right;

    if (size < 2)
        return;

    mid = size / 2;
    left = array;
    right = array + mid;

    merge_sort_recursive(left, mid);
    merge_sort_recursive(right, size - mid);
    merge(array, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    merge_sort_recursive(array, size);
}
