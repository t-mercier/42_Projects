/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_trace.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void	background(mlx_t	*mlx)
{
	mlx = mlx_init(256, 256, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
}


int32_t	to_isometric_2d(double x, double y,double z, double *u, double*v)
{
	*u = (x - z) / sqrt(2);
	*v = (x + 2 * y + z) / sqrt(6);
	return 0;
}


void	conversion(t_pixel *p, int z)
{
	int x;
	int y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(0.523599);
	p->y = -z + (x + y) * sin(0.523599);
}

void trace(mlx_image_t *image, t_pixel p0, t_pixel p1, uint32_t color) {

	if (p0.x > image->width || p1.x > image->width ||
		p0.y > image->height || p1.y > image->height)
		return;
	int dx = abs(p1.x - p0.x);
	int sx = p0.x < p1.x ? 1 : -1;
	int dy = -abs(p1.y - p0.y);
	int sy = p0.y < p1.y ? 1 : -1;
	int error = dx + dy;

	while (1) {
		mlx_put_pixel(image, abs(p0.x), abs(p0.y), color);
		if (p0.x == p1.x && p0.y == p1.y)
			break;
		int e2 = 2 * error;
		if (e2 >= dy) {
			if (p0.x == p1.x)
				break;
			error += dy;
			p0.x += sx;
		}
		if (e2 <= dx) {
			if (p0.y == p1.y)
				break;
			error += dx;
			p0.y += sy;
		}
	}
}

t_pixel	line(t_pixel p, t_fdf *g, t_vector *x, t_vector *y)
{
	p.x *= (int)g->view.zoom;
	p.y *= (int)g->view.zoom;
	p.z *= (int)(g->view.zoom / g->view.z_axis);
	p.x -= (int)(((double)x->len * g->view.zoom) / 2);
	p.y -= (int)(((double)y->len * g->view.zoom) / 2);
	conversion(&p, p.z);
	p.x += WIDTH / 2 + g->view.x;
	p.y += HEIGHT / 2 + g->view.y;
	return (p);
}


void	projection(t_vector *map, t_fdf *m)
{
	t_pixel	p0;
	t_pixel	p1;
	t_pixel	p2;
	int		j;
	int		i;

	j = 0;
	ft_memset(&p0, 0, sizeof(t_pixel));
	ft_memset(&p1, 0, sizeof(t_pixel));
	while (j < map->len)
	{
		i = 0;
		t_vector *row = ((t_vector **)map->data)[j];
		t_vector *color = ((t_vector **)row->data)[i];
		while (i < row->len)
		{
			p0.z = ((int *)row->data)[i];
			if (i < row->len)
			{
				p1.x = i + 1;
				p1.y = j;
				p1.z = ((int *)row->data)[i + 1];
				p1.c = ((int *)color->data)[i + 1];
				trace(m->img, line(p0, m, map, row),
					  line(p1, m, map, row), p1.c);
			}
			if (j < map->len - 1)
			{
				p2.x = i;
				p2.y = j + 1;
				t_vector *nr = ((t_vector **)map->data)[j + 1];
				t_vector *nc = ((t_vector **)nr->data)[j + 1];
				p2.z = ((int *)nr->data)[i];
				p2.c = ((int *)nc->data)[i];
				trace(m->img, line(p0, m, map, row),
					  line(p2, m, map, row), p2.c);
			}
			i++;
		}
		j++;
	}
}