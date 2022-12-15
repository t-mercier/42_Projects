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

#include "../inc/fdf.h"

static void	_translate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP) ||
		mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
	{
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
			fdf->offset.y -= 30;
		else
			fdf->offset.y += 30;
		project(fdf);
	}

	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT) ||
		mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
	{
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
			fdf->offset.x -= 30;
		else
			fdf->offset.x += 30;
		project(fdf);
	}
}

static void	_zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		return (fdf->depth += 0.05, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		return (fdf->depth -= 0.05, project(fdf));
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

void	l_hook(t_fdf *fdf)
{
	_zoom(fdf);
	_translate(fdf);
	_switch(fdf);
	rotations(fdf);
	if (fdf->_color)
	{
		fdf->rgba.r -= rand() % 3;
		fdf->rgba.g += rand() % 3;
		fdf->rgba.b -= rand() % 3;
		fdf->rgba.a += rand() % 3;
		project(fdf);
	}
	else if (fdf->_blink)
	{
		fdf->rgba.r -= rand() % 30;
		fdf->rgba.g -= rand() % 30;
		fdf->rgba.b += rand() % 30;
		project(fdf);
	}
}
