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

#include "../inc/linkedlist.h"

void	lls_delete_one(t_node *lst)
{
	free(lst);
}

void	lls_clear_list(t_node **list)
{
	t_node	*node;
	t_node	*next;

	if (!list)
		return ;
	node = *list;
	while (node)
	{
		next = node->next;
		lls_delete_one(node);
		node = next;
	}
	*list = 0;
}
