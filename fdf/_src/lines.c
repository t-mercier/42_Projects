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

#include "../_inc/fdf.h"

static void	_projection_down(t_fdf *fdf, t_vertex _0, t_index i)
{
	t_point		p0;
	t_point		p1;
	t_vertex	t;
	t_vertex	d;
	t_vertex	_1;

	d.x = i.x * fdf->tile_size;
	d.y = (i.y + 1) * fdf->tile_size;
	d.z = i.z * (fdf->tile_size / 5. * fdf->depth);
	t = matrix_to_px(fdf->m, d, NULL);
	_1 = isometry_projection(fdf->offset, &t, fdf->angle);
	p0 = cast_points(_0);
	p1 = cast_points(_1);
	fdf->color = get_color(fdf, (int)d.z) + (fdf->zzz << 8);
	if (fdf->_invert)
		fdf->color = INT32_MAX - fdf->color | 0xff;
	drawline(fdf->img, p0, p1, fdf->color);
}

static void	_projection_right(t_fdf *fdf, t_vertex _0, t_index i)
{
	t_point		p0;
	t_point		p1;
	t_vertex	t;
	t_vertex	d;
	t_vertex	_1;

	d.x = (i.x + 1) * fdf->tile_size;
	d.y = i.y * fdf->tile_size;
	d.z = i.z * (fdf->tile_size / 5. * fdf->depth);
	t = matrix_to_px(fdf->m, d, NULL);
	_1 = isometry_projection(fdf->offset, &t, fdf->angle);
	p0 = cast_points(_0);
	p1 = cast_points(_1);
	fdf->color = get_color(fdf, (int)d.z) + (fdf->zzz << 8);
	if (fdf->_invert)
		fdf->color = INT32_MAX - fdf->color | 0xff;
	drawline(fdf->img, p0, p1, fdf->color);
}

static void	_project_0(t_fdf *fdf, t_vector *row, t_vertex *_0, t_index i)
{
	t_vertex	t;
	t_vertex	d;

	i.z = ((int *)row->item)[i.x];
	d.x = (double)i.x * fdf->tile_size;
	d.y = (double)i.y * fdf->tile_size;
	d.z = (double)i.z * (fdf->tile_size / 5 * fdf->depth);
	t = matrix_to_px(fdf->m, d, NULL);
	*_0 = isometry_projection(fdf->offset, &t, fdf->angle);
}

static void	_project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_index i)
{
	t_vector	*row;

	row = ((t_vector **)map->item)[i.y];
	if (i.x < row->len - 1 && i.x >= 0)
	{
		i.z = ((int *)row->item)[i.x + 1];
		_projection_right(fdf, _0, i);
	}
	if (i.y < map->len - 1 && i.y >= 0)
	{
		row = ((t_vector **)map->item)[i.y + 1];
		i.z = ((int *)row->item)[i.x];
		_projection_down(fdf, _0, i);
	}
}

void	project(t_fdf *fdf)
{
	t_vector	*row;
	t_index		i;
	t_vertex	p;

	p = (t_vertex){};
	fdf->m = build_matrix(fdf->r);
	ft_memset(fdf->img->pixels, 0, sizeof(int) * fdf->img->width
			* fdf->img->height);
	i.y = 0;
	while (i.y < fdf->map->len)
	{
		row = ((t_vector **)fdf->map->item)[i.y];
		i.x = 0;
		while (i.x < row->len)
		{
			_project_0(fdf, row, &p, i);
			_project_1(fdf, fdf->map, p, i);
			i.x++;
		}
		i.y++;
	}
}
