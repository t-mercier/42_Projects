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


void	convert(t_pixel p, t_draw *d, int z)
{
	double a = 115;
	double b = 320;
	int x = p.x;
	int y = p.y;

	x *= TILE_W;
	y *= TILE_H;
	d->x = x * cos(a / 180) + y * cos((a + b) / 180) + z * cos((a - b) / 180);
	d->y = x * sin(a / 180) + y * sin((a + b) / 180) + z * sin((a - b) / 180);

}

void trace(mlx_image_t *image, t_draw p0, t_draw p1, uint32_t color) {

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

t_pixel	iso(t_pixel p, t_fdf *g, t_vector *map, t_vector *row)
{
//	p.x *= (int)g->view.zoom;
//	p.y *= (int)g->view.zoom;
//	p.z.p *= (int)(g->view.zoom / g->view.z_axis);
//	p.x -= (int)(((double)row->len * g->view.zoom) / 2);
//	p.y -= (int)(((double)map->len * g->view.zoom) / 2);
//	convert(&p, p.z.p);
//	p.x += WIDTH / 2 + g->view.x;
//	p.y += HEIGHT / 2 + g->view.y;


	return (p);
}


void	projection(t_vector *map, t_fdf *m)
{
	t_pixel	p0;
	t_pixel	p1;
	t_draw	d0;
	t_draw	d1;
	int		j;
	int		i;
	int 	color;

	j = 0;
	ft_memset(&p0, 0, sizeof(t_pixel));
	ft_memset(&p1, 0, sizeof(t_pixel));
	while (j < map->len)
	{
		i = 0;
		ft_memset(&d0, 0, sizeof(t_draw));
		ft_memset(&d1, 0, sizeof(t_draw));
		t_vector *row = ((t_vector **)map->data)[j];
		while (i < row->len)
		{
			p0.x = i;
			p0.y = j;
			p0.z = ((t_data *)row->data)[i];
			convert(p0, &d0, p0.z.p);
			d0.x += X_OFFSET;
			d0.y += Y_OFFSET;
			if (i + 1 < row->len)
			{
				p1.x = i + 1;
				p1.y = j;
				p1.z = ((t_data *)row->data)[i + 1];
				color = p1.z.c;
				convert(p1, &d1, p1.z.p);
				d1.x += X_OFFSET;
				d1.y += Y_OFFSET;
				trace(m->img, d0, d1, color);
			}
			if (j + 1 < map->len)
			{
				p1.x = i;
				p1.y = j + 1;
				t_vector *nr = ((t_vector **)map->data)[j + 1];
				p1.z = ((t_data *)nr->data)[i];
				convert(p1, &d1, p1.z.p);
				color = p1.z.c;
				d1.x += X_OFFSET;
				d1.y += Y_OFFSET;
				trace(m->img, d0, d1, color);
			}
			i++;
		}
		j++;
	}
}