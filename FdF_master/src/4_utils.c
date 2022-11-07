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




void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

void	*check_malloc(void	*ptr)
{
	if (ptr != NULL)
		return (ptr);
	perror(NULL);
	return 0;
}

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	(void) param;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}


void error(void)
{
	char    *s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void exit_message(char *s, int code)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(code);
}

void exit_success_message(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}