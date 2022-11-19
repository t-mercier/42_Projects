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

static void	projection_down(t_fdf *fdf, t_vertex _0, t_vertex p)
{
	t_vertex	_1;
	t_vertex	t;

	t.x = (p.x * fdf->tile_size);
	t.y = ((p.y + 1) * fdf->tile_size);
	t.z = p.data.z * (fdf->tile_size / 3);
	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
	drawline(fdf->img, _0, _1, GREEN);
}

static void	projection_right(t_fdf *fdf, t_vertex _0, t_vertex p)
{
	t_vertex	_1;
	t_vertex	t;

	t.x = ((p.x + 1) * fdf->tile_size);
	t.y = (p.y * fdf->tile_size);
	t.z = p.data.z * (fdf->tile_size / 3);
	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
	drawline(fdf->img, _0, _1, GREEN);
}

static void	project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_vertex p)
{
	t_vector	*row;

	row = ((t_vector **)map->item)[p.y];
	if (p.x < row->len - 1)
	{
		p.data = ((t_data *)row->item)[p.x + 1];
		projection_right(fdf, _0, p);
	}
	if (p.y < map->len - 1)
	{
		row = ((t_vector **)map->item)[p.y + 1];
		p.data = ((t_data *)row->item)[p.x];
		projection_down(fdf, _0, p);
	}
}

static void	project_0(t_fdf *fdf, t_vector *row, t_vertex *_0, t_vertex p)
{
	t_vertex	t;

	p.data = ((t_data *)row->item)[p.x];
	t.x = (p.x * fdf->tile_size);
	t.y = (p.y * fdf->tile_size);
	t.z = p.data.z * (fdf->tile_size / 3);
	_0->x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_0->y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;
}

void	projection(t_vector *map, t_fdf *fdf)
{
	t_vertex	p;
	t_vertex	_0;
	t_vector	*row;

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	_0 = (t_vertex){};
	ft_memset(fdf->img->pixels, 0, sizeof(int) * \
	fdf->img->width * fdf->img->height);
	p.y = 0;
	while (p.y < map->len)
	{
		row = ((t_vector **)map->item)[p.y];
		p.x = 0;
		while (p.x < row->len)
		{
			project_0(fdf, row, &_0, p);
			project_1(fdf, map, _0, p);
			p.x++;
		}
		p.y++;
	}
}
