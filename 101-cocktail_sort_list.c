#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *iterator, *iterator2;
	int flag = 0;

	if (!list || !(*list))
		return;

	temp = *list;
	iterator = temp->next;
	iterator2 = temp->prev;

	while (iterator)
	{
		if (iterator->next == NULL)
			flag = 1;
		if (temp->n > iterator->n)
		{
			iterator2 = iterator;
			_swap(temp, iterator);
			if (*list == temp)
				*list = iterator;
			print_list(*list);
		}
		while (iterator2 && flag == 1)
		{
			if (iterator2->prev == NULL)
				flag = 0;
			if (temp->n < iterator2->n)
			{
				iterator = iterator2;
				_swap(iterator2, temp);
				if (*list == iterator2)
					*list = temp;
				print_list(*list);
			}
			temp = iterator2;
			iterator2 = temp->prev;
		}
		temp = iterator;
		iterator = iterator->next;
	}
}
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
