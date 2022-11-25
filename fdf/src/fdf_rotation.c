/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_rotation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 22:28:06 by tmercier      ########   odam.nl         */
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

bool	rotate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		return (rotate_yaw(fdf, 2., true), true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		return (rotate_yaw(fdf, -2., false), true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		return (rotate_pitch(fdf, 2., true), true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		return (rotate_pitch(fdf, -2., false), true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		return (rotate_roll(fdf, 2., true), true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		return (rotate_roll(fdf, -2., false), true);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
	{
		rotate_pitch(fdf, -2., false);
		rotate_roll(fdf, -2., false);
		rotate_yaw(fdf, -2., false);
		return true;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
	{
		rotate_pitch(fdf, 2., true);
		rotate_roll(fdf, 2., true);
		rotate_yaw(fdf, 2., true);
		return true;
	}
	return false;
}
