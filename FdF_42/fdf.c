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


//
//void	init_fdf(t_fdf *fdf)
//{
//	fdf->mlx->width = 1200;
//	fdf->mlx->height = 800;
//	fdf->flag.height_mod = 4;
//	fdf->flag.zoom = 11;
//	fdf->flag.angle_mod = 30;
//	fdf->flag.pos.x = fdf->mlx.win_size.x / 2;
//	fdf->flag.pos.y = fdf->mlx.win_size.y / 2;
//	get_next_colorcheme(&fdf->disp);
//}

//static void	move(t_fdf *fdf, int key)
//{
//	if (key == MLX_KEY_ESCAPE)
//		mlx_close_window(mlx);
//
//}
//
//int			key_hook(int keycode, t_fdf *fdf)
//{
//	if (keycode == ESC_KEY)
//		fdf_exit(fdf);
//	move(fdf, keycode);
//	draw_win(fdf);
//	return (0);
//}
//
//int			move_hook(int keycode, t_fdf *fdf)
//{
//	if (keycode == UP_KEY || keycode == W_KEY)
//		fdf->flag.pos.y -= 20;
//	if (keycode == DOWN_KEY || keycode == S_KEY)
//		fdf->flag.pos.y += 20;
//	if (keycode == LEFT_KEY || keycode == A_KEY)
//		fdf->flag.pos.x -= 20;
//	if (keycode == RIGHT_KEY || keycode == D_KEY)
//		fdf->flag.pos.x += 20;
//	if (keycode == CM_KEY || keycode == Q_KEY)
//		fdf->flag.angle_mod += 3;
//	if (keycode == PT_KEY || keycode == E_KEY)
//		fdf->flag.angle_mod -= 3;
//	draw_win(fdf);
//	return (0);
//}

void conversion(int x, int y, int z, int *u, int *v)
{
	double a = 30;
	double b = 180;


	*u = x * cos(a / 180) + y * cos((a + b) / 180) + z * cos((a - b) / 180);
	*v = x * sin(a / 180) + y * sin((a + b) / 180) + z * sin((a - b) / 180);

//	*u = (x - y) * cos(0.523598776);
//	*v = (-z + y + x) * sin(0.523598776);
	*u += X_OFFSET;
	*v += Y_OFFSET;

}


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

	j = 0;
	while (j < map->len)
	{
		i = 0;
		t_vector *row = ((t_vector **)map->data)[j];
		while (i < row->len)
		{
			int cur = ((int *)row->data)[i];
			ft_memset(&d, 0, sizeof(t_draw));
			p.x0 = i * TILE_W;
			p.y0 = j * TILE_H;
			cur *= TILE_H / 4;
			conversion(p.x0, p.y0, cur, &d.u0, &d.v0);
			if (i < row->len)
			{
				int zx = ((int *)row->data)[i + 1];
				p.x1 = (i + 1) * TILE_W;
				p.y1 = j * TILE_H;
				zx *= TILE_H / 4;
				conversion(p.x1, p.y1, zx, &d.u1, &d.v1);
				line(m->img, d.u0, d.v0, d.u1, d.v1, BLUE);
			}
			if (j < map->len - 1)
			{
				t_vector *nrow = ((t_vector **)map->data)[j + 1];
				int zy = ((int *)nrow->data)[i];
				p.x1 = i * TILE_W;
				p.y1 = (j + 1) * TILE_H;
				zy *= TILE_H / 4;
				conversion(p.x1, p.y1, zy, &d.u1, &d.v1);
				line(m->img, d.u0, d.v0, d.u1, d.v1, BLUE);
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
	m.mlx = mlx_init(2500, 1500, "FDF", true);
	if (!m.mlx)
		exit(EXIT_FAILURE);
	m.img = mlx_new_image(m.mlx, 2000, 1000);   // Creates a new image.
	mlx_image_to_window(m.mlx, m.img,  700, 100);// Draw the image at coordinate (0, 0).
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