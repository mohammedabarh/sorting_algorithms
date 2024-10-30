#include "sort.h"

/**
 * bitonic_compare - Compares and swaps elements based on direction
 * @array: Array to sort
 * @i: First index
 * @j: Second index
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t i, size_t j, int dir)
{
    int temp;

    if (dir == (array[i] > array[j]))
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * bitonic_merge - Merges bitonic sequences
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction of sorting
 * @size: Size of the full array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
    size_t k, i;

    if (count > 1)
    {
        k = count / 2;
        for (i = low; i < low + k; i++)
            bitonic_compare(array, i, i + k, dir);
        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction of sorting
 * @size: Size of the full array
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir, size_t size)
{
    size_t k;

    if (count > 1)
    {
        k = count / 2;
        printf("Merging [%lu/%lu] (%s):\n", count, size,
               (dir == 1) ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, low, k, 1, size);
        bitonic_sort_recursive(array, low + k, k, 0, size);
        bitonic_merge(array, low, count, dir, size);

        printf("Result [%lu/%lu] (%s):\n", count, size,
               (dir == 1) ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array using bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || (size & (size - 1)) != 0)
        return;

    bitonic_sort_recursive(array, 0, size, 1, size);
}
