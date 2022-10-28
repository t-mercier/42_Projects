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

#include "doubly_linkedlist.h"

bool is_empty(t_node *list)
{
	return (list == NULL);
}

int	list_size(t_list *list)
{
	list->size = 0;
	t_node *current;

	current = list->head;
	while (current != NULL)
	{
		list->size++;
		current = current->next;
	}
	return list->size;
}
