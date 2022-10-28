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

#include "single_linkedlist.h"

bool is_empty(t_node *list)
{
	return (list == NULL);
}

int	list_size(t_node *list)
{
	int	n;

	n = 0;
	while (list)
	{
		list = list->next;
		n++;
	}
	return (n);
}
