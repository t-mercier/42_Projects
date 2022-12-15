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

#include "../inc/fdf.h"

//void f() {
//	system("leaks fdf");
//}
//atexit(f);

static void	clear(t_fdf *fdf)
{
	free(fdf->title);
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_delete_image(fdf->mlx, fdf->baseline);
	mlx_delete_image(fdf->mlx, fdf->warning);
	mlx_terminate(fdf->mlx);
	exit(0);
}

void resizer(int32_t width, int32_t height, void* param) {
	t_fdf *fdf=param;
	width = fdf->win.w;
	height =  fdf->win.h;
	mlx_resize_image(fdf->img, width, height);
	calibrate(fdf);
	project(fdf);

}

static void	render(t_fdf *fdf, int fd)
{
	fdf->grid = read_file(fd, fdf);
	close(fd);
	calibrate(fdf);
	fdf->mlx = mlx_init((int32_t)fdf->win.w,
			(int32_t)fdf->win.h, fdf->title, true);
	if (!fdf->mlx)
		exit(1);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win.w, fdf->win.h);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		exit(1);
	mlx_resize_hook(fdf->mlx, resizer, fdf);
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
	size_t	len;
	int		fd;
	int		n;

	fdf = (t_fdf){};
	n = 0;
	check_error(ac, av[1]);
	if (ft_memcmp(av[1], "maps/", 5) == 0)
	{
		len = ft_strlen(av[1]) - 5 + 1;
		n = 5;
	}
	else
		len = ft_strlen(av[1]) + 1;
	fdf.title = ft_malloc((len) * sizeof(char));
	fdf.title = ft_strncpy(fdf.title, av[1] + n, len);
	fd = open(av[1], O_RDONLY);
	if (!fd || fd < 0)
		exit_message("\n_EMPTY_FILE_ERROR_ >>> "
			"File missing\n\n", 1);
	render(&fdf, fd);
	clear(&fdf);
	return (0);
}
