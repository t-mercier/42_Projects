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

void isometric_conversion(int x, int y, int z, int *u, int *v)
{
	double a = 15;
	double b = 60;
	*u = x * cos(a / 180) + y * cos((a + b) / 180) + z * cos((a - b) / 180);
	*v = x * sin(a / 180) + y * sin((a + b) / 180) + z * sin((a - b) / 180);
}

void line(mlx_image_t *img, t_draw *d, uint32_t color)
{
	int e2;

	if (d->u0 > img->width || d->u1 > img->width || \
	d->v0 > img->height || d->v1 > img->height)
		return ;
	int dx = abs(d->u1 - d->u0);
	int sx = d->u0 < d->u1 ? 1 : -1;
	int dy = -abs(d->v1 - d->v0);
	int sy = d->v0 < d->v1 ? 1 : -1;
	int error = dx + dy;

	while (1)
	{
		mlx_put_pixel(img, abs(d->u0), abs(d->v0), color);
		if (d->u0 == d->u1 && d->v0 == d->v1)
			break ;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (d->u0 == d->u1)
				break;
			error += dy;
			d->u0 += sx;
		}
		if (e2 <= dx)
		{
			if (d->v0 == d->v1)
				break;
			error += dx;
			d->v0 += sy;
		}
	}
}

int32_t	main(int ac, char **av)
{
	t_vector	*map;
	t_vector	*row;
	t_fdf		m;
	t_map 		p;
	int cur;
	int			fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		error();
	ft_memset(&m.mlx, 0, sizeof(mlx_t *));
	ft_memset(&map, 0, sizeof(struct s_vector *));
	ft_memset(&row, 0, sizeof(struct s_vector *));
	m.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	m.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);   // Creates a new image.
	mlx_image_to_window(m.mlx, m.img, 0, 0);	// Draw the image at coordinate (0, 0).
	mlx_key_hook(m.mlx, &my_keyhook, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("ERROR [ Empty map ]\n", 1);
	map = open_read_file(fd);
	close(fd);
	t_index i;
	t_draw d;
	i.x0 = 0;
	i.y0 = 0;
	i.x1 = 1;
	i.y1 = 1;
	ft_memset(&p, 0, sizeof(t_map));
	while (i.y0 < map->len)
	{
		row = ((t_vector **)map->data)[i.y0];
		while (i.x0 < row->len)
		{
//			ft_memset(&d, 0, sizeof(t_draw));
			cur = ((int *)row->data)[i.x0];
			p.x0 = i.x0 * GRIDSIZE;
			p.y0 = i.y0 * GRIDSIZE;
			isometric_conversion(p.x0, p.y0, cur, &d.u0, &d.v0);
			if (i.x1 < row->len)
			{
				int zx = ((int *)row->data)[i.x1];
				p.x1 = i.x1 * GRIDSIZE;
				p.y1 = i.y0 * GRIDSIZE;
				isometric_conversion(p.x1, p.y1, zx, &d.u1, &d.v1);
				d.u0 += OFFSET;
				d.v0 += OFFSET;
				d.u1 += OFFSET;
				d.v1 += OFFSET;
				line(m.img, &d, BLUE);
			}
			if (i.y1 < map->len)
			{
				row = ((t_vector **)map->data)[i.y1];
				int zy = ((int *)row->data)[i.x0];
				p.x2 = i.x0 * GRIDSIZE;
				p.y2 = i.y1 * GRIDSIZE;
				isometric_conversion(p.x2, p.y2, zy, &d.u1, &d.v1);
				d.u0 += OFFSET;
				d.v0 += OFFSET;
				d.u1 += OFFSET;
				d.v1 += OFFSET;
				line(m.img, &d, BLUE);
			}
			i.x0++;
			i.x1++;
		}
		i.y0++;
		i.y1++;
	}
	mlx_loop(m.mlx);
//	mlx_key_hook(mlx, key_hook, mlx);
//	mlx_delete_image(mlx, img); // Once the application request an exit, cleanup.
	mlx_terminate(m.mlx);
	return (EXIT_SUCCESS);
}

