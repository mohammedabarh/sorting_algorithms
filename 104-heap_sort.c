#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Maintains max heap property
 * @array: Array to heapify
 * @size: Size of the array
 * @i: Root index
 * @total_size: Original size of the array
 */
void heapify(int *array, size_t size, size_t i, size_t total_size)
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
        print_array(array, total_size);
        heapify(array, size, largest, total_size);
    }
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (!array || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    /* Extract elements from heap */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}
