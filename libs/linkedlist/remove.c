/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 12:15:31 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:56:28 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/single_linkedlist.h"

void	delete_one(t_node *lst)
{
	free(lst);
}

 #include <stdio.h>

void	clear_list(t_node **list)
{
	if (!list)
		return ;
	t_node	*node;
	t_node	*next;

	node = *list;
	while (node)
	{
		next = node->next;
		delete_one(node);
		node = next;
	}
	*list = 0;
}
