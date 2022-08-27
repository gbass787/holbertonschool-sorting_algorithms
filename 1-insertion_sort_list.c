#include "sort.h"
/**
 * _swap - swaps nodes
 * @p: prev node
 * @h: current node
 * @head: head of list
 */
void _swap(listint_t *p, listint_t *h, listint_t **head)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	tmp1 = p->prev;
	tmp2 = h->next;
	if (tmp1)
		tmp1->next = h;
	if (tmp2)
		tmp2->prev = p;
	if (tmp1 == NULL)
		*head = h;
	p->prev = h;
	p->next = tmp2;
	h->prev = tmp1;
	h->next = p;
}
/**
 * insertion_sort_list - sorts doubly linked list of ints in ascending order
 * @list: pointer to head of doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int i;

	if (list == NULL)
		return;

	head = *list;

	while (head)
	{
		prev = head->prev;
		i = head->n;

		while (prev && prev->n > i)
		{
			_swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}

		head = head->next;
	}
}
