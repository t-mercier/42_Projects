/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 20:22:31 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	_perspective(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_P))
	{
		fdf->isometry = false;
		fdf->angle = 120;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		fdf->isometry = true;
}

static void	_move(t_fdf *fdf)
{

	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->offset.y -= 20;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->offset.y += 20;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->offset.x -= 20;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->offset.x += 20;
	
}

static void	_zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		fdf->tile_size += 2;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		fdf->tile_size -= 2;
}

static void	_close(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	hook(t_fdf *fdf, mlx_key_data_t keydata)
{
	_close(fdf);
	_zoom(fdf);
	_move(fdf);
	rotate(fdf);
	_perspective(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_HOME))
		disable_usage(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_END))
		unable_usage(fdf);
	project(fdf, fdf->map);
}
