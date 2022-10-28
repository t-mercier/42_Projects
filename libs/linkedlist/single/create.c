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

#include "single_linkedlist.h"

t_node	*create_node(void *data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!a)
		return (new);
	new->content = data;
	new->next = NULL;
	return (new);
}

void	add_front(t_node **list, t_node *new)
{
	new->next = *list;
	*list = new;
}

t_node	*get_last(t_node *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	add_back(t_node **list, t_node *new)
{
	get_last(*list)->next = new;
}