/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:47:26 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/23 19:40:28 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linkedlist.h"

t_node	*create_node(void *data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->content = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void add_front(t_list** list, t_node *new)
{
	if ((*list)->head != NULL)
	{
		(*list)->head->prev = new;
		new->next = (*list)->head;
	}
	(*list)->head = new;
	(*list)->tail = new;
}

void add_after_node(t_node *node, t_node *new)
{
	if (node == NULL)
		return ;
	new->next = node->next;
	node->next = new;
	new->prev = node;
	if (new->next != NULL)
		new->next->prev = new;
}

void add_last(t_list **list, t_node *new)
{
	t_node *last;

	last = (*list)->tail;
	new->next = NULL;
	if ((*list)->head == NULL)
	{
		new->prev = NULL;
		(*list)->head = new;
		(*list)->tail = new;
		return;
	}
	(*list)->tail->next = new;
	new->prev = last;

	return ;
}