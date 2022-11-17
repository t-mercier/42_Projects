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

#include "../include/linkedlist.h"

t_node	*lls_create_node(void *content)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}
