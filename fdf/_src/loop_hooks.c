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

static bool	_switch(t_fdf *fdf)
{
	int			i;
	const int	n[] = {MLX_KEY_1, MLX_KEY_2, MLX_KEY_3, MLX_KEY_4,
		MLX_KEY_5, MLX_KEY_6, MLX_KEY_7, MLX_KEY_8};

	i = 0;
	while (n[i])
		if (mlx_is_key_down(fdf->mlx, n[i++]))
			return (fdf->palette = i, true);
	return (false);
}

static bool	_warning(t_fdf *fdf)
{
	if (fdf->width > 50 && fdf->tile_size >= 40.)
		return (fdf->warning->enabled = true, true);
	if (fdf->width <= 50 && fdf->tile_size >= 70.)
		return (fdf->warning->enabled = true, true);
	return (false);
}

void	l_hook(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (_zoom(fdf) || _move(fdf) || _switch(fdf) || rotations(fdf)
		|| _warning(fdf))
		project(fdf);
	if (fdf->_color)
	{
		fdf->rgb.r += rand() % 3;
		fdf->rgb.g -= rand() % 3;
		fdf->rgb.b *= rand() % 3;
		project(fdf);
	}
}
