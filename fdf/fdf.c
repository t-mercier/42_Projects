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

mlx_image_t	*mlx_put_string(mlx_t *mlx, const char *str, int32_t x, int32_t y);

//void	init(t_fdf *fdf, char *filename)
//	fdf->map.heightmap = NULL;
//	fdf->width = 1000;
//	fdf->height = 1000;
//	fdf->zoom = fdf->width / 2;
//	fdf->rgb = 0xFF0000;
//}

//int		get_color(t_vertex *p1)
//{
//	int	r;
//	int	g;
//	int	b;
//
//	r = (p1->color & 0xFF0000) >> 16;
//	g = (p1->color & 0x00FF00) >> 8;
//	b = p1->color & 0x0000FF;
//	return ((r << 16) + (g << 8) + b);
//}

int32_t	main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		exit_message("[ ERROR - WRONG ARGUMENTS ]", 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("[ ERROR FILE READING ]\n", 1);
	ft_memset(&fdf, 0, sizeof(t_fdf));
	calibration(&fdf);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf.mlx)
		exit(EXIT_FAILURE);
	fdf.map = open_read_file(fd);
	mlx_set_window_size(fdf.mlx, WIDTH, HEIGHT);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	projection(fdf.map, &fdf);
	mlx_loop_hook(fdf.mlx, (void *)&hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
