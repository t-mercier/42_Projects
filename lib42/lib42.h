/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:48:22 by tmercier      #+#    #+#                 */
/*   Updated: 2021/12/18 14:34:42 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB42_H
# define LIB42_H

# include "include/libft.h"
# include "include/single_linkedlist.h"
# include "MLX42/include/MLX42/MLX42.h"

# define EXIT_FAILURE    1

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

static void	mlx_error_exit(void)
{
	char    *s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif 