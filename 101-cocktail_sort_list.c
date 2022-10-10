#include "sort.h"

/**
 * cocktail_sort_list - sort list with cocktail sort algo
 *
 * @list: points to start of list to be sortedå
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *next, *iter, *iter_next, *iter_prev, *end;
	int swapped;

	if (list == NULL || *list == NULL)
		return;

	end = *list;
	while (end->next)
		end = end->next;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		cur = *list;
		while ((next = cur->next))
		{
			iter = cur;
			while (iter->next && iter->n > cur->next->n)
			{
				iter_next = iter->next;
				/*printf("Comparing: %d and %d\n", iter->n, iter_next->n);*/
				remove_node(iter_next);
				insert_bef_n_aft(iter_next, iter, iter->prev);
				swapped = 1;
				if (iter == *list)
					*list = iter->prev;
				if (iter_next == end)
					end = iter;
				print_list(*list);
			}

			if (swapped)
			{
				iter = end->prev;
				while (iter->prev && iter->n < iter->prev->n)
				{
					iter_prev = iter->prev;
					/*printf("Comparing: %d and %d\n", iter->n, iter_prev->n);*/
					remove_node(iter);
					insert_bef_n_aft(iter, iter_prev, iter_prev->prev);
					swapped = 1;
					if (iter_prev == *list)
						*list = iter;
					if (iter == end)
						end = iter_prev;
					print_list(*list);
				}
			}
			cur = next;
		}
	}
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
