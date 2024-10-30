#include "sort.h"

/**
 * sift_down - Repairs the heap whose root element is at index 'start'
 * @array: Array to sort
 * @start: Starting index
 * @end: Ending index
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child, swap;
    int temp;

    while ((root * 2 + 1) <= end)
    {
        child = root * 2 + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;
        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;
        if (swap == root)
            return;

        temp = array[root];
        array[root] = array[swap];
        array[swap] = temp;
        print_array(array, size);
        root = swap;
    }
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int temp;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2; i > 0; i--)
        sift_down(array, i - 1, size - 1, size);

    /* Extract elements from heap */
    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        sift_down(array, 0, i - 1, size);
    }
}
