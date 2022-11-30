/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 22:30:44 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/fdf.h"

void	resize_map(t_fdf *fdf)
{
	if (fdf->width > 100 || fdf->height > 100)
		fdf->tile_size = 3.;
	else if (fdf->width < 20 || fdf->height < 20)
		fdf->tile_size = 50.;
	else
		fdf->tile_size = 10.;
}

void	calibrate(t_fdf *fdf)
{
	fdf->r.yaw = 0.;
	fdf->r.pitch = 0.;
	fdf->r.roll = 0.;
	fdf->depth = 1.;
	fdf->palette = 1;
	fdf->offset.x = (double)WIDTH * 40 / 100;
	fdf->offset.y = (double)HEIGHT * 10 / 100;
	fdf->angle = 35.264;
	fdf->_invert = false;
	fdf->n = 1.;
}

t_point	cast_points(t_vertex p)
{
	t_point	_p;

	_p.x = (int)p.x;
	_p.y = (int)p.y;
	_p.z = (int)p.z;
	return (_p);
}

void	clear(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_delete_image(fdf->mlx, fdf->baseline);
	mlx_delete_image(fdf->mlx, fdf->warning);
	mlx_terminate(fdf->mlx);
	exit(0);
}

int	check_error(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (!fd || fd < 0)
		exit_message("\n_FILE_ERROR_ >>> wrong file or file missing\n\n", 1);
	if (ac < 2 || ac > 2 || ft_strlen(av[1]) - 5 <= 0)
		exit_message("\n_USAGE_ERROR_ >>> ./fdf _maps/*.fdf\n\n", 1);
	else if (ft_memcmp(av[1], "_maps/", 6) != 0)
		exit_message("\n_ARGS_ERROR_ >>> ./fdf _maps/*.fdf\n\n", 1);
	return (fd);
}
