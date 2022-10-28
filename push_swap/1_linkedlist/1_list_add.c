/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_add.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 17:05:17 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/21 17:05:17 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	add_last_silent(t_list **list, t_node *new)
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
