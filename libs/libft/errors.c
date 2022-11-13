/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_errors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 10:48:50 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/13 10:48:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/MLX42/MLX42/MLX42.h"

void	mlx_error_exit(void)
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
