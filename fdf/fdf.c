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
//void	init(t_fdf *fdf, char *filename)
//{
//	int		i;
//
//	fdf->map.heightmap = NULL;
//	fdf->map->height = 1000;
//	fdf->width = 1000;
//	fdf->zoom = fdf->width / 2;
//	fdf->rgb = 0xFF0000;
//}


int32_t	main(int ac, char **av)
{

	t_fdf		fdf;
	int			fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		error();
	ft_memset(&fdf, 0, sizeof(t_fdf));
	calibration(&fdf);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("ERROR [ Empty grid ]\n", 1);
	fdf.grid = open_read_file(&fdf, fd);
	fdf.mlx = mlx_init(W_WIDTH, W_HEIGHT, "FDF", true);
	if (!fdf.mlx)
		exit(EXIT_FAILURE);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf.mlx, fdf.img, 50, 50);
	projection(fdf.grid, &fdf);
	mlx_scroll_hook(fdf.mlx, &scrollhook, &fdf);
	mlx_loop_hook(fdf.mlx, &hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
