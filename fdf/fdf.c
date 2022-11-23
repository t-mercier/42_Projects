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

void	calibration(t_fdf *fdf)
{
	fdf->x_offset  = WIDTH - (WIDTH / 2);
	fdf->y_offset  = HEIGHT - (HEIGHT / 2);
	fdf->tile_size = 20;
	fdf->angle = deg_to_rad(30);
	fdf->height = HEIGHT;
	fdf->width = WIDTH;
	fdf->zoom = fdf->width / 2;
	fdf->rgb = 0xFF0000;
	fdf->r.yaw = 10;
	fdf->r.pitch = 30;
	fdf->r.roll = 0;
}

void render(t_fdf *fdf, int fd)
{

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
	calibration(&fdf);
	fdf.map = open_read_file(fd);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	mlx_set_window_size(fdf.mlx, WIDTH, HEIGHT);
	project(&fdf, fdf.map);
	mlx_loop_hook(fdf.mlx, (void *)&hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
