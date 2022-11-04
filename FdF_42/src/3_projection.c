/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   6_colors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometry(t_xyz *p, t_fdf *fdf)
{
	int x;
	int y;
	int z;

	x = p->x;
	y = p->y;
	z = p->z;
	double a = 90;
	double b = 130;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	fdf->d.x = x * cos(a / 180) + y * cos((a + b) / 180) + z * cos((a - b) / 180);
	fdf->d.y = x * sin(a / 180) + y * sin((a + b) / 180) + z * sin((a - b) / 180);
}

void		projection(t_xyz *p, t_fdf *fdf)
{
//	p->x *= fdf->map.zoom;
//	p->y *= fdf->map.zoom;
//	p->z *= fdf->map.zoom;
//	p->x -= (int)(fdf->map.width * fdf->map.zoom) / 2;
//	p->y -= (int)(fdf->map.height * fdf->map.zoom) / 2;
//	rotate(&p);
	isometry(p, fdf);
}

void	draw_map(t_fdf *fdf)
{
	int			i;
	int			j;
	t_vector	*v;
	t_pixel		p;


	j = 0;
	ft_memset(&p, 0, sizeof(t_pixel));
	while (j < fdf->grid->len)
	{
		i = 0;
		v = ((t_vector **)fdf->grid->item)[j];
		while (i < fdf->grid->len)
		{
			p.data = ((t_data *)v->item)[i];
			p._0.x = i;
			p._0.y = j;
			p._0.z = p.data.z;
			projection(&p._0, fdf);
			scale(fdf);
			fdf->u = fdf->d;
			if (i + 1 < v->len)
			{
				p.data = ((t_data *)v->item)[i + 1];
				p._1.x = i + 1;
				p._1.y = j;
				p._1.z = p.data.z;
				p._1.color = p.data.color;
				projection(&p._1, fdf);
				scale(fdf);
				fdf->v = fdf->d;
				trace(fdf->img, fdf->u, fdf->v, p._1.color);
			}
			if (j + 1 < fdf->grid->len)
			{
				v = ((t_vector **)fdf->grid->item)[j + 1];
				p.data = ((t_data *)v->item)[i];
				p._2.x = i;
				p._2.y = j + 1;
				p._2.z = p.data.z;
				p._2.color = p.data.color;
				projection(&p._2, fdf);
				scale(fdf);
				fdf->v = fdf->d;
				trace(fdf->img, fdf->u, fdf->v, p._2.color);
			}
			i++;
		}
		j++;
	}
}

