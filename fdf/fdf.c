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


static void	insert_menu(t_fdf *fdf)
{
	int i;
	t_vertex p;

	i = 0;
	p.x = 50;
	p.y = 50;
	mlx_put_string(fdf->mlx, "+ + + + + + + + + + + + + + + +\n", 50, 50);
	mlx_put_string(fdf->mlx, "+\n", p.x, p.y);
	while (i++ < 7)
		mlx_put_string(fdf->mlx, "+\n", p.x, p.y += 25);
	p.y = 25;
	i = 0;
	while (i++ < 7)
		mlx_put_string(fdf->mlx, "+\n", 350, p.y += 25);
	mlx_put_string(fdf->mlx, "+ + + + + + + + + + + + + + + +\n", 50, 225);
	mlx_put_string(fdf->mlx, "Zoom in : + \n", 80, 60);
	mlx_put_string(fdf->mlx, "Zoom ou : - \n", 80, 80);
	mlx_put_string(fdf->mlx, "move up : ", 80, 100);
	mlx_put_string(fdf->mlx, "move up :  \n", 80, 120);

}

static void	render(t_fdf *fdf, int fd)
{
	calibration(fdf);
	fdf->map = open_read_file(fd);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_set_window_size(fdf->mlx, WIDTH, HEIGHT);
	insert_menu(fdf);
	project(fdf, fdf->map);
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
