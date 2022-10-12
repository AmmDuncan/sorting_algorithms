#include "sort.h"

/**
 * cocktail_sort_list - sort list with cocktail sort algo
 *
 * @list: points to start of list to be sortedå
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *iter, *iter_next, *iter_prev, *end;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	end = *list;
	while (end->next)
		end = end->next;
	while (swapped)
	{
		swapped = 0;
		cur = *list;
		while (cur)
		{
			iter = cur;
			while (iter->next && iter->n > cur->next->n)
			{
				iter_next = iter->next;
				swap_list(list, &end, iter_next, iter, iter->prev);
				swapped = 1;
				print_list(*list);
			}

			cur = cur->next;
		}
		cur = end;
		while (cur)
		{
			iter = cur;
			while (iter->prev && iter->n < cur->prev->n)
			{
				iter_prev = iter->prev;
				swap_list(list, &end, iter, iter_prev, iter_prev->prev);
				swapped = 1;
				print_list(*list);
			}

			cur = cur->prev;
		}
	}
}

/**
 * swap_list - swap nodes in a list
 *
 * @list: list
 * @end: end of list
 * @node: node to move
 * @bef: to insert before
 * @aft: to insert after
 */
void swap_list(
		listint_t **list,
		listint_t **end,
		listint_t *node,
		listint_t *bef,
		listint_t *aft)
{
	remove_node(node);
	insert_bef_n_aft(node, bef, aft);
	if (bef == *list)
		*list = node;
	if (node == *end)
		*end = bef;
}

/**
 * remove_node - remove node from current position
 * Description:	set "previous.next" to "node.next"
 *		and "next.previous" to "node.prev"
 * @node: current list node
 */
void remove_node(listint_t *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
}

/**
 * insert_bef_n_aft - insert before and after
 *
 * Description:	insert node in between two nodes
 *
 * @node: node to insert
 * @before: node to insert before
 * @after: node to insert after
 */
void insert_bef_n_aft(listint_t *node, listint_t *before, listint_t *after)
{
	if (after)
		after->next = node;
	node->prev = after;
	node->next = before;
	if (before)
		before->prev = node;
}
