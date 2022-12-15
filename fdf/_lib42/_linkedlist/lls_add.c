/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:47:26 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:17:41 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/linkedlist.h"

void	lls_add_front(t_node **list, t_node *new)
{
	new->next = *list;
	*list = new;
}

void	lls_add_back(t_node **list, t_node *new)
{
	if (!*list)
		*list = new;
	else
		lls_get_last(*list)->next = new;
}
