/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:37:19 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/02 15:37:19 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void isometry(t_xyz *p)
{
	int x;
	int y;
	int z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = (x - y) * cos(0.523599);
	p->y = -z + (x + y) * sin(0.523599);
}

static void	rotate_x(t_pixel *p)
{
	p->x = p->i.x;
	p->y = cos(rad(p->angle)) * p->i.y + sin(rad(p->angle)) * p->i.z;
	p->z = -sin(rad(p->angle)) * p->i.y + cos(rad(p->angle)) * p->i.z;
}

static void	rotate_y(t_pixel *p)
{
	p->x = cos(rad(p->angle)) * p->i.x + sin(rad(p->angle)) * p->i.z;
	p->y = p->i.y;
	p->z = -sin(rad(p->angle)) * p->i.x + cos(rad(p->angle)) * p->i.z;
}

static void	rotate_z(t_pixel *p)
{
	p->x = cos(rad(p->angle)) * p->i.x - sin(rad(p->angle)) * p->i.y;
	p->y = sin(rad(p->angle)) * p->i.x + cos(rad(p->angle)) * p->i.y;
	p->z = p->i.z;
}

void	rotate(t_pixel *p, double angle)
{
	p->angle = angle;
	rotate_x(p);
	rotate_y(p);
	rotate_z(p);
}

void		projection(t_xyz *p, t_fdf *fdf)
{
	fdf->map.p.x = p->x * fdf->set.zoom;
	fdf->map.p.y = p->y * fdf->set.zoom;
	fdf->map.p.z = p->z * fdf->set.zoom / fdf->set.z_divisor;
	fdf->map.p.x = p->x - (fdf->map.row->len * fdf->set.zoom) / 2;
	fdf->map.p.y = p->y - (fdf->map.grid->len * fdf->set.zoom) / 2;
	rotate(&fdf->map.p, fdf->set.angle);
	isometry(p);
	scale(fdf);
}

// https://en.wikipedia.org/wiki/Rotation_matrix

void	draw_map(t_fdf *fdf)
{
	int			i;
	int			j;
	t_pixel 	p;
	t_map		map;

	j = 0;
	ft_memset(&p, 0, sizeof(t_pixel));
	while (j < fdf->map.grid->len)
	{
		i = 0;
		map.row = ((t_vector **)fdf->map.grid->item)[j];
		while (i < fdf->map.row->len)
		{
			p.data = ((t_data *)map.row->item)[i];
			p._0.x = i;
			p._0.y = j;
			p._0.z = p.data.z;
			p._0.color = p.data.color;
			projection(&p._0, fdf);
			if (i + 1 < map.row->len)
			{
				p.data = ((t_data *)map.row->item)[i + 1];
				p._1.x = i + 1;
				p._1.y = j;
				p._1.z = p.data.z;
				p._1.color = p.data.color;
				projection(&p._1, fdf);
				trace(fdf->img, p._0, p._1, p._1.color);
			}
			if (j + 1 < map.grid->len)
			{
				map.row = ((t_vector **)fdf->map.grid->item)[j + 1];
				p.data = ((t_data *)map.row->item)[i];
				p._2.x = i;
				p._2.y = j + 1;
				p._2.z = p.data.z;
				p._2.color = p.data.color;
				projection(&p._2, fdf);;
				trace(fdf->img, p._0, p._2, p._2.color);
			}
			i++;
		}
		j++;
	}
}


//void	convert(t_pixel p, t_draw *d, t_set *a, int z)
//{

//	float cz = cos(rad(a->roll));
//	float cy = cos(rad(a->pitch));
//	float cx = cos(rad(a->yaw));
//	float sz = sin(rad(a->roll));
//	float sy = sin(rad(a->pitch));
//	float sx = sin(rad(a->yaw));
//	float dx = cy * (sz * p.y + cz * p.x) - sy * z;
//	float dy = sx * (cy * z + sy * (sz * p.y + cz * p.x)) + cx * (cz * p.y - sz * p.x);
//	float dz = cx * (cy * z + sy * (sz * p.y + cz * p.x)) - sx * (cz * p.y - sz * p.x);
//	o->x = dx * cos(α) + dy * cos(α + 120) + dz * cos(α - 120);
//	o->y = dx * sin(α) + dy * sin(α + 120) + o * sin(α - 120);
//	d->x = dx * cos(α) + dy * cos(α + 120) + dz * cos(α - 120);
//	d->y = dx * sin(α) + dy * sin(α + 120) + dz * sin(α - 120);
//}
