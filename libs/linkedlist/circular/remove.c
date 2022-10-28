/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delete.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 12:15:31 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 12:15:31 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linkedlist.h"

void	delete_first(t_list **list)
{
	if ((*list)->head == NULL)
		return ;
	if (list_size((*list)) == 1)
	{
		list = NULL;
		return ;
	}
	(*list)->tail->next = (*list)->head->next;
	free((*list)->head);
	(*list)->head = (*list)->tail->next;
}

void	delete_last(t_list *node)
{
	t_node	*list;

	if (!node)
		return ;
	list = head(node);
	while (list->next != tail(node))
		list = list->next;
	list->next = node->head;
	node->tail = list;
	free(node->tail);
}

void	delete_node(t_list *list, int position)
{
	int		i;
	t_node	*prev;
	t_node	*del;

	i = 0;
	prev = list->head;
	if (prev == NULL)
		return ;
	if (tail(list) == prev || position == 1)
	{
		delete_first(&list);
		return ;
	}
	while (1)
	{
		if (i + 1 == position - 1)
			break ;
		prev = prev->next;
		i++;
	}
	del = prev->next;
	prev->next = prev->next->next;
	free(del);
	del = NULL;
}
