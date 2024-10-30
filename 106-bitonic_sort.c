#include "sort.h"

/**
 * bitonic_compare - Compares and swaps elements in bitonic sequence
 * @array: Array to sort
 * @start: Starting index
 * @seq: Sequence size
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t start, size_t seq, int dir)
{
    size_t jump = seq / 2;
    size_t i;
    int temp;

    for (i = start; i < start + jump; i++)
    {
        if ((array[i] > array[i + jump]) == dir)
        {
            temp = array[i];
            array[i] = array[i + jump];
            array[i + jump] = temp;
        }
    }
}

/**
 * bitonic_merge - Recursively merges bitonic sequences
 * @array: Array to sort
 * @start: Starting index
 * @seq: Sequence size
 * @dir: Direction (1 for ascending, 0 for descending)
 * @size: Size of the full array
 */
void bitonic_merge(int *array, size_t start, size_t seq, int dir, size_t size)
{
    size_t cut = seq / 2;

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size,
               (dir == 1) ? "UP" : "DOWN");
        print_array(array + start, seq);

        bitonic_compare(array, start, seq, dir);
        bitonic_merge(array, start, cut, dir, size);
        bitonic_merge(array, start + cut, cut, dir, size);
    }
}

/**
 * bitonic_seq - Creates bitonic sequences
 * @array: Array to sort
 * @start: Starting index
 * @seq: Sequence size
 * @dir: Direction (1 for ascending, 0 for descending)
 * @size: Size of the full array
 */
void bitonic_seq(int *array, size_t start, size_t seq, int dir, size_t size)
{
    size_t cut = seq / 2;

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size,
               (dir == 1) ? "UP" : "DOWN");
        print_array(array + start, seq);

        bitonic_seq(array, start, cut, 1, size);
        bitonic_seq(array, start + cut, cut, 0, size);
        bitonic_merge(array, start, seq, dir, size);
    }
}

/**
 * bitonic_sort - Sorts an array using bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2 || (size & (size - 1)) != 0)
        return;

    bitonic_seq(array, 0, size, 1, size);
}
