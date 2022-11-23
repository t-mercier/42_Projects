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

static void	_projection_down(t_fdf *fdf, t_vertex _0, t_vertex p)
{
	t_vertex	_1;
	t_vertex	t;
	t_vertex	d;

//	t_matrice m = build_matrice(fdf->r);
	d.x = (p.x * fdf->tile_size);
	d.y = ((p.y + 1) * fdf->tile_size);
	d.z = p.z * (fdf->tile_size / 3);
	t = matrice_to_px(fdf->m, d, NULL);
	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
	drawline(fdf->img, _0, _1, GREEN);
}

static void	_projection_right(t_fdf *fdf, t_vertex _0, t_vertex p)
{
	t_vertex	_1;
	t_vertex	t;
	t_vertex	d;

	d.x = ((p.x + 1) * fdf->tile_size);
	d.y = (p.y * fdf->tile_size);
	d.z = p.z * (fdf->tile_size / 3);
	t = matrice_to_px(fdf->m, d, NULL);
	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
	drawline(fdf->img, _0, _1, GREEN);
}

static void	_project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_vertex p)
{
	t_vector	*row;

	row = ((t_vector **)map->item)[p.y];
	if (p.x < row->len - 1)
	{
		p.z = ((int *)row->item)[p.x + 1];
		_projection_right(fdf, _0, p);
	}
	if (p.y < map->len - 1)
	{
		row = ((t_vector **)map->item)[p.y + 1];
		p.z = ((int *)row->item)[p.x];
		_projection_down(fdf, _0, p);
	}
}

static void	_project_0(t_fdf *fdf, t_vector *row, t_vertex *_0, t_vertex p)
{
	t_vertex	t;
	t_vertex	d;

//	fdf->m = build_matrice(fdf->r);

	p.z = ((int *)row->item)[p.x];
	d.x = p.x * fdf->tile_size;
	d.y = p.y * fdf->tile_size;
	d.z = p.z * (fdf->tile_size / 3);
	t = matrice_to_px(fdf->m, d, NULL);
	_0->x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_0->y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
}

void	project(t_fdf *fdf, t_vector *map)
{
	t_vector	*row;
	t_vertex	p;
	t_vertex	_0;

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	_0 = (t_vertex){};
	fdf->m = build_matrice(fdf->r);
	ft_memset(fdf->img->pixels, 0, sizeof(int) * \
	fdf->img->width * fdf->img->height);
	p.y = 0;
	while (p.y < fdf->map->len)
	{
		row = ((t_vector **)map->item)[p.y];
		p.x = 0;
		while (p.x < row->len)
		{
			_project_0(fdf, row, &_0, p);
			_project_1(fdf, map, _0, p);
			p.x++;
		}
		p.y++;
	}

}
