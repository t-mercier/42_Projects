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

#include "../inc/linkedlist.h"
#include "../inc/storage_classes.h"

t_node	*llc_get_previous_end(t_list *list)
{
	t_node	*tmp;

	tmp = head(list);
	while (tmp->next != tail(list))
		tmp = tmp->next;
	return (tmp);
}

int	llc_list_size(t_list *list)
{
	int		i;
	t_node	*current;

	i = 1;
	if (!list)
		return (0);
	current = head(list);
	while (current != list->tail && i++)
		current = current->next;
	return (i);
}
