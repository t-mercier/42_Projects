/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 14:11:24 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/01 14:11:24 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linkedlist.h"

bool is_empty(t_node *list)
{
	return (list == NULL);
}

t_node	*get_previous_end(t_list *list)
{
	t_node	*tmp;

	tmp = head(list);
	while (tmp->next != tail(list))
		tmp = tmp->next;
	return (tmp);
}

int	list_size(t_list *list)
{
	int		i;
	t_node	*current;

	if (!list)
		return (0);
	list->size = 1;
	current = head(list);
	while (current != list->tail && list->size)
		current = current->next;
	return (list->size);
}

void	free_list(t_list *list)
{
	t_node	*tmp;

	tmp = (list)->head;
	if (!tmp)
		return ;
	while (tmp != list->tail)
	{
		tmp = (list)->head->next;
		free(list->head);
		list->head = tmp;
	}
	if (list->tail)
		free(list->tail);
}
