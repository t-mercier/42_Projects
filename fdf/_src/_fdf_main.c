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
	fdf->grid = read_file(fd, fdf);
	calibrate(fdf);
	fdf->mlx = mlx_init((int32_t)fdf->win.w,
			(int32_t)fdf->win.h, fdf->title, true);
	if (!fdf->mlx)
		exit(1);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win.w, fdf->win.h);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		exit(0);
	init_usage(fdf);
	project(fdf);
	mlx_key_hook(fdf->mlx, (void *)k_hook, fdf);
	mlx_loop_hook(fdf->mlx, (void *)l_hook, fdf);
	mlx_scroll_hook(fdf->mlx, (void *)scrollhook, fdf);
	mlx_loop(fdf->mlx);
}

int32_t	main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;
	int		len;
	int		n;

	fdf = (t_fdf){};
	n = 0;
	check_error(ac, av[1]);
	if (ft_memcmp(av[1], "maps/", 6) == 0)
	{
		len = ft_strlen(av[1]) - 4;
		n = 5;
	}
	else
		len = ft_strlen(av[1]) + 1;
	fdf.title = ft_malloc(len * sizeof(char));
	fdf.title = ft_strncpy(fdf.title, av[1] + n, len);
	fd = open(fdf.title, O_RDONLY);
	if (!fd || fd < 0)
		exit_message("\n_FILE_ERROR_ >>> wrong file "
			"or file missing\nAccepted files : *.fdf\n\n", 1);
	render(&fdf, fd);
	clear(&fdf);
	return (0);
}
