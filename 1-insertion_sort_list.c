#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: Pointer to the first node
 * @right: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
		}
		current = next;
	}
}
