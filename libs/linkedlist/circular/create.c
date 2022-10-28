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

#include "circular_linkedlist.h"

t_node	*create_node(void *data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->content = data;
	new->next = NULL;
	return (new);
}

void	add_last(t_list **list, t_node *new)
{
	if (!new)
		return ;
	if (!head(*list))
	{
		new->next = new;
		(*list)->head = new;
		(*list)->tail = new;
		return ;
	}
	(*list)->tail->next = new;
	(*list)->tail = new->next;
	new->next = (*list)->head;
}
