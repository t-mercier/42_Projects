/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_algo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	_projection_down(t_fdf *fdf, t_vertex _0)
{
	t_vertex	_1;
	t_vertex	t;
	t_vertex	p;

	p.x = (fdf->p.x * fdf->tile_size);
	p.y = ((fdf->p.y + 1) * fdf->tile_size);
	p.z = fdf->p.z * (fdf->tile_size / 3);
	t = matrice_to_px(fdf->m, p, NULL);
	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
	drawline(fdf->img, _0, _1, GREEN);
}

static void	_projection_right(t_fdf *fdf, t_vertex _0)
{
	t_vertex	_1;
	t_vertex	t;
	t_vertex	p;

	p.x = ((p.x + 1) * fdf->tile_size);
	p.y = (p.y * fdf->tile_size);
	p.z = p.z * (fdf->tile_size / 3);
	t = matrice_to_px(fdf->m, p, NULL);
	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
	drawline(fdf->img, _0, _1, GREEN);
}

static void	_project_0(t_fdf *fdf, t_vector *row)
{
	t_vertex	t;
	t_vertex	p;

	fdf->p.z = ((int *)row->item)[fdf->p.x];
	p.x = fdf->p.x * fdf->tile_size;
	p.y = fdf->p.y * fdf->tile_size;
	p.z = fdf->p.z * (fdf->tile_size / 3);
	t = matrice_to_px(fdf->m, p, NULL);
	fdf->_0.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	fdf->_0.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
}

static void	_trace_lines(t_fdf *fdf, t_vector *map)
{
	t_vector	*row;

	row = ((t_vector **)map->item)[fdf->p.y];
	if (fdf->p.x < row->len - 1)
	{
		fdf->p.z = ((int *)row->item)[fdf->p.x + 1];
		_projection_right(fdf, fdf->_0);
	}
	if (fdf->p.y < map->len - 1)
	{
		row = ((t_vector **)map->item)[fdf->p.y + 1];
		fdf->p.z = ((int *)row->item)[fdf->p.x];
		_projection_down(fdf, fdf->_0);
	}
}

void	project(t_fdf *fdf)
{
	t_vector	*row;

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	ft_memset(fdf->img->pixels, 0, sizeof(int) * fdf->img->width * fdf->img->height);
	fdf->p = (t_vertex){};
	fdf->_0 = (t_vertex){};
	fdf->m = (t_matrice){};
	fdf->m = build_matrice(fdf->r);
	while (fdf->p.y < fdf->map->len)
	{
		row = ((t_vector **)fdf->map->item)[fdf->p.y];
		fdf->p.x = 0;
		while (fdf->p.x < row->len)
		{
			_project_0(fdf, row);
			_trace_lines(fdf, fdf->map);
			fdf->p.x++;
		}
		fdf->p.y++;
	}
}
