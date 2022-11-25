/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 22:47:59 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static bool	_perspective(t_fdf *fdf)
{
	fdf->r.yaw = 0;
	fdf->r.pitch = 0;
	fdf->r.roll = 0;
	fdf->depth = 1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_DIVIDE))
	{
		fdf->r.yaw = 315.;
		fdf->r.pitch = 0.;
		fdf->r.roll = 315.;
		fdf->depth = 0;
		return true;
	}
	else
		return false;
}

static bool	_move(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		return (fdf->offset.y -= 20, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		return (fdf->offset.y += 20, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		return (fdf->offset.x -= 20, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		return (fdf->offset.x += 20, true);
	return false;
	
}

static bool	_zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		return (fdf->tile_size += 2, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		return (fdf->tile_size -= 2, true);
	return false;
}

static bool _depth(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT_BRACKET))
		return (fdf->depth += 0.3, true);	
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_BRACKET))
		return (fdf->depth -= 0.3, true);
	return false;	
}

void	hook(t_fdf *fdf, mlx_key_data_t keydata)
{
	_zoom(fdf);
	_move(fdf);
	_perspective(fdf);
	rotate(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_SPACE))
		unable_usage(fdf);
	else
		disable_usage(fdf);
	if (fdf->render)
		project(fdf, fdf->map);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}
