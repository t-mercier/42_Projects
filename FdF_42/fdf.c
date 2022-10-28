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
	 *u = sqrt(2) / 2 * (x - y);
	 *v = sqrt(2 / 3) * z - 1 / sqrt(6) * (x + y);
}

//void line(mlx_image_t *img, t_fdf *i)
//{
//	int dx;
//	int dy;
//	int grtr_d;
//	int smlr_d;
//	int d;
//		if (i->x0 > img->width || i->x1 > img->width || \
//	i->y0 > img->height || i->y1 > img->height)
//		return ;
//	dx = i->x1 - i->x0;
//	dy = i->y1 - i->y0;
//	grtr_d = 2 * dy - 2 * dx;
//	smlr_d = 2 * dy;// when d < 0
//	d = (2 * dy) - dx;
//	while (i->x0 < i->x1)
//	{
//		mlx_put_pixel(img, i->x, i->y, BLUE);
//		if(d < 0) {
//			d = smlr_d+d;
//		}
//		else
//		{
//			d = grtr_d+d;
//			i->y0 = i->y0 + 1;
//		}
//		i->x0 = i->x0 + 1;
//	}
//}

void line(mlx_image_t *img, t_map *p, uint32_t color)
{
	int error;
	int e2;

	if (p->u0 > img->width || p->u1 > img->width || \
	p->v0 > img->height || p->v1 > img->height)
		return ;
	p->sx = -1;
	if (p->u0 < p->u1)
		p->sx = 1;
	p->dx = abs(p->u1 - p->u0);
	p->dy = -abs(p->v1 - p->v0);
	p->sy = -1;
	if (p->v0 < p->v1)
		p->sy = 1;
	error = p->dx + p->dy;

	while (1)
	{
		mlx_put_pixel(img, abs(p->u0), abs(p->v0), color);
		if (p->u0 == p->u1 && p->v0 == p->v1)
			break;
		e2 = 2 * error;
		if (e2 >= p->dy)
		{
			if (p->u0 == p->u1)
				break;
			error += p->dy;
			p->u0 += p->sx;
		}
		if (e2 <= p->dx)
		{
			if (p->v0 == p->v1)
				break;
			error += p->dx;
			p->v0 += p->sy;
		}
	}
	return ;
}

int32_t	main(int ac, char **av)
{
	t_vector	*map;
	t_vector	*row;
	t_fdf		m;
	t_map 		p;
	int x;
	int y;
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
	i.x1 = 1;
	i.y1 = 1;
	while (i.y0 < map->len)
	{
		row = ((t_vector **)map->data)[y];
		while (i.x0 < row->len)
		{
			cur = ((int *)row->data)[x];
			p.x0 = i.x0 * GRIDSIZE;
			p.y0 = i.y0 * GRIDSIZE;
			isometric_conversion(p.x0, p.y0, cur, &p.u0, &p.v0);
			if (i.x1 < row->len)
			{
				int zx = ((int *)row->data)[i.x1];
				p.x1 = i.x1 * GRIDSIZE;
				p.y1 = i.y0 * GRIDSIZE;
				p.u0 += OFFSET;
				p.v0 += OFFSET;
				p.u1 += OFFSET;
				p.v1 += OFFSET;
				isometric_conversion(p.x1, p.y1, zx, &p.u1, &p.v1);
				line(m.img, &p, BLUE);
			}
			if (i.y1 < map->len)
			{
				t_vector *next_row = ((t_vector **)map->data)[i.y1];
				int zy = ((int *)next_row->data)[i.x1];
				p.x1 = i.x0 * GRIDSIZE;
				p.y1 = i.y1 * GRIDSIZE;
				p.u0 += OFFSET;
				p.v0 += OFFSET;
				p.u1 += OFFSET;
				p.v1 += OFFSET;
				isometric_conversion(p.x1, i.y1, zy, &p.u1, &p.v1);
				line(m.img, &p, BLUE);
//				j.dx = abs(i.x0 - i.x1);
//				j.dy = abs(i.y0 - i.y1);
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

