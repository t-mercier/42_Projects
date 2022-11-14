/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 14:11:24 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:57:04 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/single_linkedlist.h"

bool is_empty(t_node *list)
{
	return (list == NULL);
}

int	list_size(t_node *list)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

void	list_iterate(t_node *lst, void (*f)(int))
{
	while (lst)
	{
		f(*(int *)lst->content);
		lst = lst->next;
	}
}
