#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heapify - Transforms a subtree rooted at index i into a heap.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @i: The index of the root element
 */
void heapify(int *array, size_t size, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *              the Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        heapify(array, size, i - 1);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}
