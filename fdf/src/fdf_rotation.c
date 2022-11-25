/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 14:46:10 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Rotate axe Z 
static void	rotate_yaw(t_fdf *fdf, double n, bool clockwise)
{
		if (clockwise && fdf->r.yaw == 360)
			fdf->r.yaw = 0;
		if (!clockwise && fdf->r.yaw == 0)
			fdf->r.yaw = 360;
		fdf->r.yaw += n;
}

// Rotate axe Y
static void	rotate_pitch(t_fdf *fdf, double n, bool clockwise)
{
		if (clockwise && fdf->r.pitch == 360)
			fdf->r.pitch = 0;
		if (!clockwise && fdf->r.pitch == 0)
			fdf->r.pitch = 360;
		fdf->r.pitch += n;
}

// Rotate axe X
static void	rotate_roll(t_fdf *fdf, double n, bool clockwise)
{
		if (clockwise && fdf->r.roll == 360)
			fdf->r.roll = 0;
		if (!clockwise && fdf->r.roll == 0)
			fdf->r.roll = 360;
		fdf->r.roll += n;
}

void	rotate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		rotate_yaw(fdf, 10., true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		rotate_yaw(fdf, -10., false);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		rotate_pitch(fdf, 10., true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		rotate_pitch(fdf, -10., false);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		rotate_roll(fdf, 10., true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		rotate_roll(fdf, -10., false);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
		{
			rotate_pitch(fdf, -10., false);
			rotate_roll(fdf, -10., false);
			rotate_yaw(fdf, -10., false);
		}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
		{
			rotate_pitch(fdf, 10., true);
			rotate_roll(fdf, 10., true);
			rotate_yaw(fdf, 10., true);
		}
}
