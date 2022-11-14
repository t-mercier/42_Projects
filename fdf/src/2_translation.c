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


void	projection_down(t_fdf *fdf, t_vertex _0, t_index i)
{
	t_vertex _1;

	fdf->map.x = (i.x * fdf->tile_size);
	fdf->map.y = ((i.y + 1) * fdf->tile_size);
	fdf->map.z = i.z * (fdf->tile_size / 3);
	_1.x = (fdf->map.x - fdf->map.y) * cos(0.523599);
	_1.y = -fdf->map.z + (fdf->map.x + fdf->map.y) * sin(0.523599);
	_1.x += fdf->x_off;
	_1.y += fdf->y_off;
	line(fdf->img, _0.x, _0.y, _1.x, _1.y, BLUE);
}

void	projection_right(t_fdf *fdf, t_vertex _0, t_index i)
{
	t_vertex _1;

	fdf->map.x = ((i.x + 1) * fdf->tile_size);
	fdf->map.y = (i.y * fdf->tile_size);
	fdf->map.z = i.z * (fdf->tile_size / 3);
	_1.x = (fdf->map.x - fdf->map.y) * cos(0.523599);
	_1.y = -fdf->map.z + (fdf->map.x + fdf->map.y) * sin(0.523599);
	_1.x += fdf->x_off;
	_1.y += fdf->y_off;
	line(fdf->img, _0.x, _0.y, _1.x, _1.y, BLUE);
}


void	project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_index i)
{
	t_vector	*row;

	row = ((t_vector **)map->item)[i.y];
	if (i.x < row->len)
	{
		i.z = ((int *)row->item)[i.x + 1];
		projection_right(fdf, _0, i);
	}
	if (i.y < map->len - 1)
	{
		row = ((t_vector **)map->item)[i.y + 1];
		i.z = ((int *)row->item)[i.x];
		projection_down(fdf, _0, i);
	}
}

void	project_0(t_fdf *fdf, t_vector *row, t_vertex *_0, t_index i)
{
	i.z = ((int *)row->item)[i.x];
	fdf->map.x = (i.x * fdf->tile_size);
	fdf->map.y = (i.y * fdf->tile_size);
	fdf->map.z = i.z * (fdf->tile_size / 3);
	_0->x = (fdf->map.x - fdf->map.y) * cos(0.523599);
	_0->y = -fdf->map.z + (fdf->map.x + fdf->map.y) * sin(0.523599);
	_0->x += fdf->x_off;
	_0->y += fdf->y_off;
}

void	projection(t_vector *map, t_fdf *fdf)
{
	t_vertex	_0;
	t_index		i;
	t_vector	*row;

	i.y = 0;
	ft_memset(&_0, 0, sizeof(t_vertex));
	ft_memset(fdf->img->pixels, 0, sizeof(int) * fdf->img->width * fdf->img->height);
	while (i.y < fdf->size.y)
	{
		i.x = 0;
		row = ((t_vector **)map->item)[i.y];
		while (i.x < fdf->size.x)
		{
			project_0(fdf, row, &_0, i);
			project_1(fdf, map, _0, i);
			i.x++;
		}
		i.y++;
	}
}
