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

void line(mlx_image_t *img, t_map *i)
{
	int dx;
	int dy;
	int grtr_d;
	int smlr_d;
	int d;
		if (i->x0 > img->width || i->x1 > img->width || \
	i->y0 > img->height || i->y1 > img->height)
		return ;
	dx = i->x1 - i->x0;
	dy = i->y1 - i->y0;
	grtr_d = 2 * dy - 2 * dx;
	smlr_d = 2 * dy;// when d < 0
	d = (2 * dy) - dx;
	while (i->x0 < i->x1)
	{
		mlx_put_pixel(img, i->x, i->y, BLUE);
		if(d < 0) {
			d = smlr_d+d;
		}
		else
		{
			d = grtr_d+d;
			i->y0 = i->y0 + 1;
		}
		i->x0 = i->x0 + 1;
	}
}

//void *line(mlx_image_t *img, t_draw *i, uint32_t color)
//{
//	int error;
//	int e2;
//
//	if (i->x0 > img->width || i->x1 > img->width || \
//	i->y0 > img->height || i->y1 > img->height)
//		return NULL;
//	i->sx = -1;
//	if (i->x0 < i->x1)
//		i->sx = 1;
//	i->dx = abs(i->x1 - i->x0);
//	i->dy = -abs(i->y1 - i->y0);
//	i->sy = -1;
//	if (i->y0 < i->y1)
//		i->sy = 1;
//	error = i->dx + i->dy;
//
//	while (1)
//	{
//		if (i->x0 == i->x1 && i->y0 == i->y1)
//			break;
//		e2 = 2 * error;
//		if (e2 >= i->dy)
//		{
//			if (i->x0 == i->x1)
//				break;
//			error += i->dy;
//			i->x0 += i->sx;
//		}
//		if (e2 <= i->dx)
//		{
//			if (i->y0 == i->y1)
//				break;
//			error += i->dx;
//			i->y0 += i->sy;
//		}
//		mlx_put_pixel(img, abs(i->x0), abs(i->y0), color);
//	}
//	return NULL;
//}

int32_t	main(int ac, char **av)
{
	t_vector	*map;
	t_vector	*row;
	t_map		m;
	t_grid 		i;
	int x;
	int y;
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
	x = 0;
	y = 0;
	int z = 0;
	while (y < map->len)
	{
		row = ((t_vector **)map->data)[y];
		while (x < row->len)
		{
			z = ((int *)row->data)[x];
			isometric_conversion(x, y, z, &i.u0, &i.v0);
			if (row->len > i.x1)
			{
				printf("1er IF | i.x0 %d\n", i.x0);
				printf("1er IF | row len %zu\n", row->len);
				i.z1 = ((int *)row->data)[i.x1];
				isometric_conversion(i.x1, i.y1, i.z1, &i.u1, &i.v1);
				j.y0 = i.v0 * GRIDSIZE;
				j.y1 = i.v1 * GRIDSIZE;
				j.x0 = i.u0 * GRIDSIZE;
				j.x1 = i.u1 * GRIDSIZE;
				j.dx = abs(j.x0 - j.x1);
				j.dy = abs(j.y0 - j.y1);
				line(m.img, &j, BLUE);
			}
			if (map->len > i.y1)
			{
				printf("2e IF | i.y1 %d\n", i.y1);
				printf("2e IF | map len %zu\n", map->len);

				row = ((t_vector **)map->data)[i.y1];
				i.z1 = ((int *)row->data)[i.x0];
				isometric_conversion(i.x0, i.y1, i.z1, &i.u0, &i.v1);
				j.y0 = i.v0 * GRIDSIZE;
				j.y1 = i.v1 * GRIDSIZE;
				j.x0 = i.u0 * GRIDSIZE;
				j.x1 = i.u1 * GRIDSIZE;
				j.dx = abs(i.x0 - i.x1);
				j.dy = abs(i.y0 - i.y1);
				line(m.img, &j, BLUE);
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

