/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	_rotate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		if (fdf->r.yaw == 360)
			fdf->r.yaw = 0;
		fdf->r.yaw += 10.;

	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		if (fdf->r.yaw == 0)
			fdf->r.yaw = 360;
		fdf->r.yaw -= 10.;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		if (fdf->r.pitch == 360)
			fdf->r.pitch = 0;
		fdf->r.pitch += 10.;
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		if (fdf->r.pitch == 0)
			fdf->r.pitch = 360;
		fdf->r.pitch -= 10.;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		fdf->r.roll += 10.;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		fdf->r.roll -= 10.;
}

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

void	hook(t_fdf *fdf)
{
	_close(fdf);
	_zoom(fdf);
	_move(fdf);
	_rotate(fdf);
	_perspective(fdf);
	project(fdf, fdf->map);
}
