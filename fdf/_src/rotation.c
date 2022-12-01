/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/12/01 21:55:00 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/fdf.h"

// Rotate axe Z
static void	_yaw(t_fdf *fdf, double n, bool clockwise)
{
	if (clockwise && fdf->r.yaw >= 360.)
		fdf->r.yaw -= 360.;
	if (!clockwise && fdf->r.yaw <= 0.)
		fdf->r.yaw += 360.;
	fdf->r.yaw += n;
}

// Rotate axe Y
static void	_pitch(t_fdf *fdf, double n, bool clockwise)
{
	if (clockwise && fdf->r.pitch >= 360.)
		fdf->r.pitch -= 360.;
	if (!clockwise && fdf->r.pitch <= 0.)
		fdf->r.pitch += 360.;
	fdf->r.pitch += n;
}

// Rotate axe X
static void	_roll(t_fdf *fdf, double n, bool clockwise)
{
	if (clockwise && fdf->r.roll >= 360.)
		fdf->r.roll -= 360.;
	if (!clockwise && fdf->r.roll <= 0.)
		fdf->r.roll += 360.;
	fdf->r.roll += n;
}

static void	_all(t_fdf *fdf, double n, bool clockwise)
{
	_pitch(fdf, 10., clockwise);
	_roll(fdf, 10., clockwise);
	_yaw(fdf, 10., clockwise);
}

void	rotations(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		return (_yaw(fdf, 10., true), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		return (_yaw(fdf, -10., false), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		return (_pitch(fdf, 10., true), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		return (_pitch(fdf, -10., false), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		return (_roll(fdf, 10., true), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		return (_roll(fdf, -10., false), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
		return (_all(fdf, -10., false), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
		return (_all(fdf, 10., true), project(fdf));
}
