/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:47:26 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/23 19:40:28 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"

t_node	*llc_create_node(void *data)
{
	t_node	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		exit(EXIT_FAILURE);
	new->content = data;
	new->next = new;
	return (new);
}
