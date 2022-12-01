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
	t_vertex	t;
	t_vertex	d;
	t_vertex	_1;

	d.x = i.x * fdf->tile_size;
	d.y = (i.y + 1) * fdf->tile_size;
	d.z = i.z * (fdf->tile_size / 5. * fdf->depth);
	t = matrix_to_px(fdf->m, d, NULL);
	_1 = isometry_projection(fdf->offset, &t, fdf->angle);
	fdf->p0 = cast_points(_0);
	fdf->p1 = cast_points(_1);
	if (fdf->_color)
		fdf->color = (int)color(fdf, (int)fdf->c.z, (int)i.z);
	else
		fdf->color = (int)get_color(fdf, (int)i.z);
	if (fdf->_invert)
		fdf->color = INT32_MAX - fdf->color | 0xff;
	drawline(fdf->img, fdf->p0, fdf->p1, fdf->color);
}

static void	_projection_right(t_fdf *fdf, t_vertex _0, t_index i)
{
	t_vertex	t;
	t_vertex	d;
	t_vertex	_1;

	d.x = (i.x + 1) * fdf->tile_size;
	d.y = i.y * fdf->tile_size;
	d.z = i.z * (fdf->tile_size / 5. * fdf->depth);
	t = matrix_to_px(fdf->m, d, NULL);
	_1 = isometry_projection(fdf->offset, &t, fdf->angle);
	fdf->p0 = cast_points(_0);
	fdf->p1 = cast_points(_1);
	if (fdf->_color)
		fdf->color = (int)color(fdf, (int)fdf->c.z, (int)i.z);
	else
		fdf->color = (int)get_color(fdf, (int)i.z);
	if (fdf->_invert)
		fdf->color = INT32_MAX - fdf->color | 0xff;
	drawline(fdf->img, fdf->p0, fdf->p1, fdf->color);
}

static void	_project_0(t_fdf *fdf, t_vertex *_0, t_index i)
{
	t_vertex	t;
	t_vertex	d;

	i.z = ((int *)fdf->row->item)[i.x];
	d.x = (double)i.x * fdf->tile_size;
	d.y = (double)i.y * fdf->tile_size;
	d.z = (double)i.z * (fdf->tile_size / 5 * fdf->depth);
	t = matrix_to_px(fdf->m, d, NULL);
	fdf->c.z = d.z;
	*_0 = isometry_projection(fdf->offset, &t, fdf->angle);
}

static void	_project_1(t_fdf *fdf, t_vertex _0, t_index i)
{
	t_vector	*row;

	row = ((t_vector **)fdf->map->item)[i.y];
	if (i.x < row->len - 1 && i.x >= 0)
	{
		i.z = ((int *)row->item)[i.x + 1];
		_projection_right(fdf, _0, i);
	}
	if (i.y < fdf->map->len - 1 && i.y >= 0)
	{
		row = ((t_vector **)fdf->map->item)[i.y + 1];
		i.z = ((int *)row->item)[i.x];
		_projection_down(fdf, _0, i);
	}
}

void	project(t_fdf *fdf)
{
	t_index		i;
	t_vertex	p;

	p = (t_vertex){};
	fdf->m = build_matrix(fdf->r);
	ft_memset(fdf->img->pixels, 0, sizeof(int)
		* fdf->img->width * fdf->img->height);
	i.y = 0;
	while (i.y < fdf->map->len)
	{
		fdf->row = ((t_vector **)fdf->map->item)[i.y];
		i.x = 0;
		while (i.x < fdf->row->len)
		{
			_project_0(fdf, &p, i);
			_project_1(fdf, p, i);
			i.x++;
		}
		i.y++;
	}
}
