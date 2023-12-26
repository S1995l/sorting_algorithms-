#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                       the insertion sort algorithm.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		back = current->prev;

		while (back && back->n > current->n)
		{
			temp = back->prev;

			back->next = current->next;
			if (current->next != NULL)
				current->next->prev = back;

			current->next = back;
			current->prev = temp;

			if (temp != NULL)
				temp->next = current;
			else
				*list = current; /* Update the head if needed */

			back->prev = current;

			/* Print the list after swap */
			print_list(*list);

			/* Traverse result list and compare every node with our current node. */
			back = temp;
		}
	}
}
