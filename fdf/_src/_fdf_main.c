/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _fdf_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 22:44:48 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	render(t_fdf *fdf, int fd)
{
	calibration(fdf);
	fdf->map = open_read_file(fd);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_set_window_size(fdf->mlx, WIDTH, HEIGHT);
	project(fdf, fdf->map);
	display_usage(fdf);
	display_baseline(fdf);
	mlx_loop_hook(fdf->mlx, (void *)hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_terminate(fdf->mlx);
}

int32_t	main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		usage();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("[ ERROR FILE READING ]\n", 1);
	fdf = (t_fdf){};
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf.mlx)
		exit(EXIT_FAILURE);
	render(&fdf, fd);
	return (EXIT_SUCCESS);
}
