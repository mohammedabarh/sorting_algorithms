#include "deck.h"

/**
 * get_card_value - Gets numerical value of a card
 * @card: Card to evaluate
 * Return: Numerical value of the card
 */
int get_card_value(const card_t *card)
{
    int i;
    char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
                      "8", "9", "10", "Jack", "Queen", "King"};

    for (i = 0; i < 13; i++)
        if (strcmp(card->value, values[i]) == 0)
            return i;
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
    deck_node_t *array[52];
    deck_node_t *current;
    int i;

    if (!deck || !*deck)
        return;

    current = *deck;
    for (i = 0; i < 52; i++)
    {
        array[i] = current;
        current = current->next;
    }

    qsort(array, 52, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < 52; i++)
    {
        array[i]->prev = i > 0 ? array[i - 1] : NULL;
        array[i]->next = i < 51 ? array[i + 1] : NULL;
    }

    *deck = array[0];
}
