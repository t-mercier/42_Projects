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

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		exit(EXIT_FAILURE);
	new->content = data;
	new->next = new;
	return (new);
}

t_node	*create_silent_node(char	*move)
{
	t_node	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		exit(EXIT_FAILURE);
	new->move = move;
	new->content = 0;
	new->next = new;
	return (new);
}
