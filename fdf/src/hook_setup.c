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


static void rotate_x(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = degree_to_radians(fdf->r.yaw);
	p->x = t.x;
	p->y = t.y * cos(angle) + t.z * -sin(angle);
	p->z = t.y * sin(angle) + t.z * cos(angle);
}

static void rotate_y(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = degree_to_radians(fdf->r.pitch);
	p->x = t.x * cos(angle) + t.z * sin(angle);
	p->y = t.y;
	p->z = t.x * -sin(angle) + t.z * cos(angle);
}

static void rotate_z(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = degree_to_radians(fdf->r.roll);
	p->x = t.x * cos(angle) + t.y * -sin(angle);
	p->z = t.x * sin(angle) + t.y * cos(angle);
	p->y = t.z;
}

static void	_rotate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		fdf->r.roll += 10;
		rotate_x(fdf, p)
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->r.roll -= 10;
	if (mlx_is_key_down(fdf->mlx,  MLX_KEY_A))
		fdf->r.pitch += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->r.pitch -= 10;
//	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
//		fdf->r.yaw += 10;
//	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
//		fdf->r.yaw -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		fdf->angle -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		fdf->angle += 10;
}

static void	_move(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->y_offset -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->y_offset += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->x_offset -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->x_offset += 10;
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
	project(fdf->map, fdf);
}
