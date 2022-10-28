/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 11:14:22 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 11:14:22 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_integer(long num)
{
	return (num <= INT_MAX && num >= INT_MIN);
}

bool	is_duplicated(t_list *list, int n)
{
	t_node	*current;
	int		i;

	i = -1;
	current = list->head;
	if (list_size(list) > 1)
	{
		while (++i < list_size(list) - 1)
		{
			if (current->content == n)
				return (true);
			current = current->next;
		}
		if (current->next->content == n)
			return (true);
	}
	return (false);
}
