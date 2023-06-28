#include "sort.h"

/**
 * insertion_sort_list - Sorts one item at a time.
 * @list: Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp_node = NULL;
	listint_t *local;

	/* Checking if array is empty */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	local = *list;

	local = local->next;

	/* Insertion sort procedures */
	while (local)
	{
		while (local->prev && local->n < local->prev->n)
		{
			temp_node = local;
			if (local->next)
				local->next->prev = temp_node->prev;
			local->prev->next = temp_node->next;
			local = local->prev;
			temp_node->prev = local->prev;
			temp_node->next = local;
			if (local->prev)
				local->prev->next = temp_node;
			local->prev = temp_node;
			if (temp_node->prev == NULL)
				*list = temp_node;
			print_list(*list);
			local = local->prev;
		}
		local = local->next;
	}
}
