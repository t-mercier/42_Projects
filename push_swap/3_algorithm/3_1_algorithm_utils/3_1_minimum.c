/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimum.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 17:31:53 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/26 14:31:58 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

int	*find_min(t_list *list)
{
	t_node	*current;

	current = list->head;
	list->min = current->content;
	while (current->next != list->head)
	{
		if (current->content < list->min)
			list->min = current->content;
		current = current->next;
	}
	if (list->min > list->tail->content)
		list->min = list->tail->content;
	return (&list->min);
}

int	*find_next_min(t_list *list)
{
	t_node	*current;

	current = list->head;
	list->min = *find_min(list);
	list->next_min = current->content;
	if (current->content == list->min)
		list->next_min = current->next->content;
	while (current->next != list->head)
	{	
		if (current->content < list->next_min && current->content != list->min)
			list->next_min = current->content;
		current = current->next;
	}
	if (list->next_min > last(list) && last(list) != list->min)
		list->next_min = last(list);
	return (&list->next_min);
}

int	position_min(t_list *list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head(list);
	list->min = *find_min(list);
	while (++i)
	{
		if (tmp->content == list->min)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

int	position_next_min(t_list *list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head(list);
	list->next_min = *find_next_min(list);
	while (++i)
	{
		if (tmp->content == list->next_min)
			break ;
		tmp = tmp->next;
	}
	return (i);
}
