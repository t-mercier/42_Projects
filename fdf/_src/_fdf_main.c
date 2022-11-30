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

#include "../_inc/fdf.h"

static void	render(t_fdf *fdf, int fd)
{
	fdf->map = open_read_file(fd, fdf);
	fdf->width = fdf->row->len;
	fdf->height = fdf->map->len;
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	init_usage(fdf);
	resize_map(fdf);
	project(fdf);
	mlx_key_hook(fdf->mlx, (void *)k_hook, fdf);
	mlx_loop_hook(fdf->mlx, (void *)l_hook, fdf);
	mlx_loop(fdf->mlx);
}

int32_t	main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	fdf = (t_fdf){};
	fd = check_error(ac, av);
	mlx_set_setting(MLX_MAXIMIZED, true);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf.mlx)
		exit(1);
	calibrate(&fdf);
	render(&fdf, fd);
	clear(&fdf);
	system("leaks fdf");
	return (0);
}
