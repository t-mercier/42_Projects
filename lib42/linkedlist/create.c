/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:47:26 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:17:41 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/single_linkedlist.h"

t_node	*create_node(void *content)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}

void	add_front(t_node **list, t_node *new)
{
	new->next = *list;
	*list = new;
}

t_node	*get_last(t_node *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_back(t_node **list, t_node *new)
{
	if (!*list)
		*list = new;
	else
		get_last(*list)->next = new;
}
