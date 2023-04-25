#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: a pointer that points to the header
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *crnt, *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;

	crnt = (*list)->next;
	while (crnt)
	{
		tmp = crnt;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (!tmp->prev)
				(*list) = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		crnt = crnt->next;
	}
}
