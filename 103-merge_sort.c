#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array.
 *
 * @array: The array to be sorted
 * @left: The starting index of the left subarray
 * @mid: The ending index of the left subarray
 * @right: The ending index of the right subarray
 */
void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while (i < n1)
        array[k++] = L[i++];

    while (j < n2)
        array[k++] = R[j++];

    free(L);
    free(R);
}

/**
 * merge_sort_recursive - Recursively sorts the array using Merge sort.
 *
 * @array: The array to be sorted
 * @left: The starting index
 * @right: The ending index
 */
void merge_sort_recursive(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(array, left, mid);
        merge_sort_recursive(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *               the Merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}
