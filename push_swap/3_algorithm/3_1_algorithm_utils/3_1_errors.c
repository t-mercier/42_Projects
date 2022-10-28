/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:45:54 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/19 17:37:19 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

void	exit_error(t_list *a, t_list *b)
{
	if (head(a))
		free_list(a);
	if (head(b))
		free_list(b);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
