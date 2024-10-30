#include "deck.h"

/**
 * get_card_value - Gets numeric value of a card
 * @card: Card to evaluate
 * Return: Numeric value of the card
 */
int get_card_value(const card_t *card)
{
    int i;
    char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
                      "8", "9", "10", "Jack", "Queen", "King"};

    for (i = 0; i < 13; i++)
    {
        if (strcmp(card->value, values[i]) == 0)
            return i;
    }
    return 0;
}

/**
 * compare_cards - Compares two cards
 * @a: First card
 * @b: Second card
 * Return: Comparison result
 */
int compare_cards(const void *a, const void *b)
{
    deck_node_t *node_a = *(deck_node_t **)a;
    deck_node_t *node_b = *(deck_node_t **)b;

    if (node_a->card->kind != node_b->card->kind)
        return node_a->card->kind - node_b->card->kind;

    return get_card_value(node_a->card) - get_card_value(node_b->card);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    deck_node_t **array;
    size_t i, count = 0;

    if (deck == NULL || *deck == NULL)
        return;

    current = *deck;
    while (current)
    {
        count++;
        current = current->next;
    }

    array = malloc(sizeof(deck_node_t *) * count);
    if (array == NULL)
        return;

    current = *deck;
    for (i = 0; i < count; i++)
    {
        array[i] = current;
        current = current->next;
    }

    qsort(array, count, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < count - 1; i++)
    {
        array[i]->next = array[i + 1];
        array[i + 1]->prev = array[i];
    }

    array[0]->prev = NULL;
    array[count - 1]->next = NULL;
    *deck = array[0];

    free(array);
}
