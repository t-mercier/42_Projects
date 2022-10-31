/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_algo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


static bool _min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	set_camera(t_fdf *g, t_vector *y, t_vector *x)
{
	g->view.zoom = _min(WIDTH / x->len / 1.5, HEIGHT / y->len / 1.5);
	g->view.z_axis = 10;
}


void	ft_key_hook(mlx_key_data_t keydata, void* param)
{
	(void) param;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}

void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}