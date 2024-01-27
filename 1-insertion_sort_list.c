#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @k: A pointer to the head of the doubly-linked list.
 * @a1: A pointer to the first node to swap.
 * @a2: The second node to swap.
 */
void swap_nodes(listint_t **k, listint_t **a1, listint_t *a2)
{
	(*a1)->next = a2->next;
	if (a2->next != NULL)
		a2->next->prev = *a1;
	a2->prev = (*a1)->prev;
	a2->next = *a1;
	if ((*a1)->prev != NULL)
		(*a1)->prev->next = a2;
	else
		*k = a2;
	(*a1)->prev = a2;
	*a1 = a2->prev;
}



/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: A pointer to the head of the doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}

	}


}
