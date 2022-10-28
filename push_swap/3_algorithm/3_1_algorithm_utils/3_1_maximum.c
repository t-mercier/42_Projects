/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maximum.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 17:35:18 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/31 17:20:27 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

int	*find_max(t_list *list)
{
	t_node	*current;

	current = list->head;
	list->max = current->content;
	while (current->next != list->head)
	{
		if (current->content > list->max)
			list->max = current->content;
		current = current->next;
	}
	if (list->max < last(list))
		list->max = last(list);
	return (&list->max);
}

int	*find_prev_max(t_list *list)
{
	t_node	*current;

	current = list->head;
	list->max = *find_max(list);
	list->prev_max = current->content;
	if (current->content == list->max)
		list->prev_max = current->next->content;
	while (current->next != list->head)
	{
		if (current->content > list->prev_max && current->content != list->max)
			list->prev_max = current->content;
		current = current->next;
	}
	if (list->prev_max < last(list) && last(list) != list->max)
		list->prev_max = last(list);
	return (&list->prev_max);
}

int	position_max(t_list *list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head(list);
	list->max = *find_max(list);
	while (++i)
	{
		if (tmp->content == list->max)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

int	position_prev_max(t_list *list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head(list);
	list->prev_max = *find_prev_max(list);
	while (++i)
	{
		if (tmp->content == list->prev_max)
			break ;
		tmp = tmp->next;
	}
	return (i);
}
