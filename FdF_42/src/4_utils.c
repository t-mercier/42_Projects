/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*check_malloc(void	*ptr)
{
	if (ptr != NULL)
		return (ptr);
	perror(NULL);
	return 0;
}

void    error(void)
{
	char    *s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void    exit_message(char *s, int code)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(code);
}