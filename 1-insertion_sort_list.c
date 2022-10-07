#include "sort.h"

/**
 * insertion_sort_list - sort doubly linked list
 * Description: sort doubly linked list using
 * insertion sort
 *
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *next;

	if (*list)
		return;

	cur = *list;
	next = cur->next;
	while (cur)
	{
		if (cur->prev)
		{
			compare_prevs(cur, list);
		}
		cur = next;
		if (cur)
			next = cur->next;
	}
}

/**
 * compare_prevs - compare node to preceeding nodes and swap
 * @node: current list node
 * @list: list to print
 */
void compare_prevs(listint_t *node, listint_t **list)
{
	listint_t *prev;

	prev = node->prev;
	/*printf("Comparing %d and %d\n", prev->n, node->n);*/
	if (prev && prev->n > node->n)
	{
		/*printf("----%d is less than %d\nSwap\n", node->n, prev->n);*/
		remove_node(node);
		insert_bef_n_aft(node, prev, prev->prev);
		if (prev == *list)
			*list = node;
		print_list(*list);
		if (node->prev)
			compare_prevs(node, list);
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
	before->prev = node;
}
