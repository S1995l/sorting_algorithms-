#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 *
 * Description:
 * This function sorts a doubly linked list in ascending order using the
 * Cocktail Shaker Sort algorithm. It swaps nodes and prints the list after
 * each swap. The process continues until the list is soted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (1)
	{
		swapped = 0;

		/* Left to right pass */
		for (current = start; current != end && current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				/* Swap nodes and print the list after each swap */
				swap_nodes(list, current, current->next);
				swapped = 1;
			}
		}

		/* If no swaps occurred in the left-to-right pass, the list is sorted */
		if (!swapped)
		{
			break;
		}

		/* Update the end node for the next pass */
		end = current;

		/* Right to left pass */
		for (current = end; current != NULL && current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				/* Swap nodes and print the list after each swap */
				swap_nodes(list, current->prev, current);
				swapped = 1;
			}
		}

		/* Update the start node for the next pass */
		start = (swapped) ? start : current->next;
	}
}


/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 * @node1: A pointer to the first node to be swapped.
 * @node2: A pointer to the second node to be swapped.
 *
 * Description:
 * This function swaps the positions of two nodes in a doubly linked list
 * and prints the list after each swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	/* Check for valid nodes before swapping */
	if (node1 == NULL || node2 == NULL)
	{
		return;
	}

	/* Update the next pointer of the previous node of node1 */
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		/* If node1 is the head, update the head of the list */
		*list = node2;
	}

	/* Update the prev pointer of the next node of node2 */
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	/* Update the next and prev pointers of node1 and node2 */
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	/* Print the list after each swap */
	print_list(*list);
}
