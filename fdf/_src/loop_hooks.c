/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_hooks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/12/01 21:34:58 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/fdf.h"

static void	_translate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		return (fdf->offset.y -= 30, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		return (fdf->offset.y += 30, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		return (fdf->offset.x -= 30, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		return (fdf->offset.x += 30, project(fdf));
}

static void	_zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		return (fdf->depth += 0.1, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		return (fdf->depth -= 0.1, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		return (fdf->depth += 0.1, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		return (fdf->depth -= 0.1, project(fdf));
}

static void	_switch(t_fdf *fdf)
{
	int			i;
	const int	n[] = {MLX_KEY_1, MLX_KEY_2, MLX_KEY_3,
		MLX_KEY_4, MLX_KEY_5, MLX_KEY_6, MLX_KEY_7, MLX_KEY_8};

	i = 0;
	while (i < (int)(sizeof(n) / sizeof(int)))
		if (mlx_is_key_down(fdf->mlx, n[i++]))
			return (fdf->palette = i, project(fdf));
}

static void	_warning(t_fdf *fdf)
{
	if (fdf->w > 50 && fdf->t_s >= 40.)
		return (fdf->warning->enabled = true, project(fdf));
	if (fdf->h <= 50 && fdf->t_s >= 70.)
		return (fdf->warning->enabled = true, project(fdf));
}

void	l_hook(t_fdf *fdf)
{
	_zoom(fdf);
	_translate(fdf);
	_switch(fdf);
	rotations(fdf);
	_warning(fdf);
	if (fdf->_color)
	{
		fdf->rgb.r -= rand() % 3;
		fdf->rgb.g += rand() % 3;
		fdf->rgb.b -= rand() % 3;
		fdf->rgb.a += rand() % 3;
		project(fdf);
	}
	else if (fdf->_blink)
	{
		fdf->rgb.r -= rand() % 30;
		fdf->rgb.g -= rand() % 30;
		fdf->rgb.b += rand() % 30;
		project(fdf);
	}
}
