#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * card_value - Returns the value of a card for sorting.
 *
 * @card: Pointer to the card
 * 
 * Return: Integer value representing the card's value
 */
int card_value(const card_t *card)
{
    if (card->value[0] == 'A')
        return 1;
    if (card->value[0] == 'K')
        return 13;
    if (card->value[0] == 'Q')
        return 12;
    if (card->value[0] == 'J')
        return 11;

    return atoi(card->value); // Convert string to int for numerical values
}

/**
 * compare_cards - Compares two cards for sorting.
 *
 * @a: First card
 * @b: Second card
 * 
 * Return: Negative if a < b, positive if a > b, zero if equal
 */
int compare_cards(const void *a, const void *b)
{
    const deck_node_t *card_a = *(const deck_node_t **)a;
    const deck_node_t *card_b = *(const deck_node_t **)b;

    int value_a = card_value(card_a->card);
    int value_b = card_value(card_b->card);

    if (value_a != value_b)
        return value_a - value_b;

    return card_a->card->kind - card_b->card->kind;
}

/**
 * sort_deck - Sorts a deck of cards.
 *
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t **array;
    deck_node_t *current;
    size_t size, i;

    // Count the number of nodes in the deck
    for (current = *deck, size = 0; current; current = current->next)
        size++;

    // Allocate memory for the array of pointers to nodes
    array = malloc(size * sizeof(deck_node_t *));
    if (!array)
        return;

    // Fill the array with the nodes
    for (current = *deck, i = 0; current; current = current->next, i++)
        array[i] = current;

    // Sort the array using qsort
    qsort(array, size, sizeof(deck_node_t *), compare_cards);

    // Re-link the sorted nodes
    for (i = 0; i < size; i++)
    {
        array[i]->prev = (i > 0) ? array[i - 1] : NULL;
        array[i]->next = (i < size - 1) ? array[i + 1] : NULL;
    }
    *deck = array[0]; // Update the head of the deck

    free(array); // Free the temporary array
}
