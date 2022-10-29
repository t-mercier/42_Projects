/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   src.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#define WIDTH 1000
#define HEIGHT 1000

void conversion(int x, int y, int z, int *u, int *v)
{
	double a = 15;
	double b = 60;
	*u = x * cos(a / 180) + y * cos((a + b) / 180) + z * cos((a - b) / 180);
	*v = x * sin(a / 180) + y * sin((a + b) / 180) + z * sin((a - b) / 180);
}
//
//void line(mlx_image_t *img, t_draw *d, uint32_t color)
//{
//	int e2;
//
//	if (d->u0 > img->width || d->u1 > img->width || \
//	d->v0 > img->height || d->v1 > img->height)
//		return ;
//	int dx = abs(d->u1 - d->u0);
//	int sx = d->u0 < d->u1 ? 1 : -1;
//	int dy = -abs(d->v1 - d->v0);
//	int sy = d->v0 < d->v1 ? 1 : -1;
//	int error = dx + dy;
//
//	while (1)
//	{
//		mlx_put_pixel(img, abs(d->u0), abs(d->v0), color);
//		if (d->u0 == d->u1 && d->v0 == d->v1)
//			break ;
//		e2 = 2 * error;
//		if (e2 >= dy)
//		{
//			if (d->u0 == d->u1)
//				break;
//			error += dy;
//			d->u0 += sx;
//		}
//		if (e2 <= dx)
//		{
//			if (d->v0 == d->v1)
//				break;
//			error += dx;
//			d->v0 += sy;
//		}
//	}
//}
void line(mlx_image_t *image, int x0, int y0, int x1, int y1, uint32_t color) {

	if (x0 > image->width || x1 > image->width || y0 > image->height ||
		y1 > image->height)
		return;
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;

	while (1) {
		mlx_put_pixel(image, abs(x0), abs(y0), color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * error;
		if (e2 >= dy) {
			if (x0 == x1)
				break;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			if (y0 == y1)
				break;
			error += dx;
			y0 += sy;
		}
	}
}

void	projection(t_vector *map, t_fdf *m)
{
	t_draw	d;
	t_point	p;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (j < map->len)
	{
		t_vector *x_y0 = ((t_vector **)map->data)[j];
		while (i < x_y0->len)
		{
			int cur = ((int *)x_y0->data)[i];
			ft_memset(&d, 0, sizeof(t_draw));
			p.x0 = i * TILESIZE;
			p.y0 = j * TILESIZE;
			conversion(p.x0, p.y0, cur, &d.u0, &d.v0);
			if (i + 1 < x_y0->len)
			{
				int zx = ((int *)x_y0->data)[i + 1];
				p.x1 = (i + 1) * TILESIZE;
				p.y1 = j * TILESIZE;
				conversion(p.x1, p.y1, zx, &d.u1, &d.v1);
				line(m->img, d.u0 + OFFSET, d.v0 + OFFSET,
					 d.u1 + OFFSET, d.v1 + OFFSET, BLUE);
			}
			if (j + 1 < map->len)
			{
				t_vector *x_y1 = ((t_vector **)map->data)[j + 1];
				int zy = ((int *)x_y1->data)[i];
				p.x2 = i * TILESIZE;
				p.y2 = (j + 1) * TILESIZE;
				conversion(p.x2, p.y2, zy, &d.u1, &d.v1);
				line(m->img, d.u0 + OFFSET, d.v0 + OFFSET,
					 d.u1 + OFFSET, d.v1 + OFFSET, BLUE);
			}
			i++;
		}
		j++;
	}
}

int32_t	main(int ac, char **av)
{
	t_vector	*map;
	t_vector	*row;
	t_fdf		m;
	int cur;
	int			fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		error();
	ft_memset(&m.mlx, 0, sizeof(mlx_t *));
	ft_memset(&map, 0, sizeof(struct s_vector *));
	ft_memset(&row, 0, sizeof(struct s_vector *));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("ERROR [ Empty map ]\n", 1);
	map = open_read_file(fd);
	m.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!m.mlx)
		exit(EXIT_FAILURE);
	m.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);   // Creates a new image.
	mlx_image_to_window(m.mlx, m.img, 0, 0);// Draw the image at coordinate (0, 0).
	projection(map, &m);
	mlx_key_hook(m.mlx, &my_keyhook, NULL);
	mlx_loop(m.mlx);
//	mlx_key_hook(mlx, key_hook, mlx);
//	mlx_delete_image(mlx, img); // Once the application request an exit, cleanup
	mlx_terminate(m.mlx);
	return (EXIT_SUCCESS);
}

//	while (i.y0 < map->len)
//	{
//		row = ((t_vector **) map->data)[i.y0];
//		fprintf(stderr, "row y%d \n", i.y0);
//		while (i.x0 < row->len)
//		{
//			int zx = ((int *) row->data)[i.x0];
//			fprintf(stderr, "z[y%d][x%d] %d ", i.y0, i.x0, zx);
//			i.x0++;
//		}
//		fprintf(stderr, "\n");
//		i.y0++;
//	}

//	for (int j = 0; j < map->len; j++)
//	{
//		t_vector *row2 = ((t_vector **) map->data)[j];
//		for (int i = 0; i < row2->len; i++)
//		{
//			int zx = ((int *) row2->data)[i];
//			fprintf(stderr, "%d ", zx);
//		}
//		fprintf(stderr, "\n");
//	}
//	ft_memset(&p, 0, sizeof(t_map));