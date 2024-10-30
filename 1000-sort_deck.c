#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_card_value - Get the numeric value of a card
 * @str: String value of the card
 *
 * Return: Numeric value of the card
 */
int get_card_value(const char *str)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @a: First node
 * @b: Second node
 * @deck: Pointer to the head of the list
 */
void swap_nodes(deck_node_t *a, deck_node_t *b, deck_node_t **deck)
{
	deck_node_t *prev_a = a->prev;
	deck_node_t *next_b = b->next;

	if (prev_a)
		prev_a->next = b;
	else
		*deck = b;

	if (next_b)
		next_b->prev = a;

	a->next = next_b;
	a->prev = b;
	b->next = a;
	b->prev = prev_a;
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *ptr;
	deck_node_t *last = NULL;

	if (deck == NULL || *deck == NULL)
		return;

	do {
		swapped = 0;
		ptr = *deck;

		while (ptr->next != last)
		{
			if (ptr->card->kind > ptr->next->card->kind ||
					(ptr->card->kind == ptr->next->card->kind &&
					 get_card_value(ptr->card->value) >
					 get_card_value(ptr->next->card->value)))
			{
				swap_nodes(ptr, ptr->next, deck);
				swapped = 1;
			}
			else
				ptr = ptr->next;
		}
		last = ptr;
	} while (swapped);
}
