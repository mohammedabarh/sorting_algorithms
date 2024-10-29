#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start, *end;

    if (list == NULL || *list == NULL)
        return;

    start = *list;
    end = NULL;

    while (swapped)
    {
        swapped = 0;
        for (; start->next != end; start = start->next)
        {
            if (start->n > start->next->n)
            {
                swap(start);
                swapped = 1;
            }
        }
        end = start;

        for (; start->prev != NULL; start = start->prev)
        {
            if (start->n < start->prev->n)
            {
                swap(start->prev);
                swapped = 1;
            }
        }
    }
}
