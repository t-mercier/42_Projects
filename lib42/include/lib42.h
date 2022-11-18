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

# include "libft.h"
# include "linkedlist.h"
# include "storage_classes.h"
# include "vectors.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define EXIT_FAILURE    1

static void	mlx_error_exit(void)
{
	char    *s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

#endif 