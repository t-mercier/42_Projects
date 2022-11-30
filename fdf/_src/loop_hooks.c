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

#include "../_inc/fdf.h"

static bool	_move(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		return (fdf->offset.y -= 30, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		return (fdf->offset.y += 30, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		return (fdf->offset.x -= 30, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		return (fdf->offset.x += 30, true);
	return (false);
}

static bool	_zoom(t_fdf *fdf)
{
	if (fdf->tile_size <= 5.)
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
			return (fdf->tile_size += 0.05, true);
	if (fdf->tile_size <= 5.)
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
			return (fdf->tile_size -= 0.05, true);
	if (fdf->tile_size > 5.)
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
			return (fdf->tile_size += 0.5, true);
	if (fdf->tile_size > 5.)
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
			return (fdf->tile_size -= 0.5, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		return (fdf->depth += 0.5, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
		return (fdf->depth -= 0.5, true);
	return (false);
}

static bool	_color_switch(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		return (fdf->palette = 1, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		return (fdf->palette = 2, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
		return (fdf->palette = 3, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_4))
		return (fdf->palette = 4, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_5))
		return (fdf->palette = 5, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_6))
		return (fdf->palette = 6, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_7))
		return (fdf->palette = 7, true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		return (fdf->palette = 0, true);
	return (false);
}

void	l_hook(t_fdf *fdf)
{
	if (fdf->width > 50 && fdf->tile_size >= 40.)
		fdf->warning->enabled = true;
	if (fdf->width <= 50 && fdf->tile_size >= 70.)
		fdf->warning->enabled = true;
	if (_zoom(fdf) || _move(fdf) || _color_switch(fdf) || rotations(fdf)
		|| fdf->_render)
		1;
	fdf->zzz++;
	project(fdf);
}
