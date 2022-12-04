/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/12/01 22:19:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/fdf.h"

void	calibrate(t_fdf *fdf)
{
	fdf->win.w = fdf->w * (int)fdf->t_s + 700;
	fdf->win.h = fdf->h * (int)fdf->t_s + 700;
	fdf->win.s = fdf->win.h * fdf->win.w;
	fdf->map.w = fdf->w * (int)fdf->t_s;
	fdf->map.h = fdf->h * (int)fdf->t_s;
	fdf->map.s = fdf->map.h * fdf->map.w;
	fdf->r.yaw = 0.;
	fdf->r.pitch = 0.;
	fdf->r.roll = 0.;
	fdf->depth = 1.;
	fdf->palette = 1;
	fdf->offset.x = (double)(fdf->win.w - fdf->map.w);
	fdf->offset.y = (double)(fdf->win.h - fdf->map.h) / 5;
	fdf->angle = 30.264;
	fdf->n = 1.;
	fdf->rgb.r = 255;
	fdf->rgb.g = 255;
	fdf->rgb.b = 255;
	fdf->rgb.a = 255;
}

t_point	cast_points(t_vertex p)
{
	t_point	_p;

	_p.x = (int)p.x;
	_p.y = (int)p.y;
	_p.z = (int)p.z;
	return (_p);
}

int	check_error(int ac, char *name)
{
	if (ac < 2 || ac > 2)
		exit_message("\n_USAGE_ERROR_ >>> "
			"./fdf *.fdf\n\n", 1);
	else if (ft_strnstr(name, ".fdf", ft_strlen(name)) == 0)
		exit_message("\n_ARGS_ERROR_ >>> "
			"./fdf maps/*.fdf\nAccepted files : *.fdf\n\n", 1);
	return (0);
}

bool	in_perimeter(t_fdf *fdf)
{
	if ((fdf->p0.x <= fdf->win.w && fdf->p0.x >= 0
			&& fdf->p0.y <= fdf->win.h && fdf->p0.y >= 0)
		|| (fdf->p1.x <= fdf->win.w && fdf->p1.x >= 0
			&& fdf->p1.y <= fdf->win.h && fdf->p1.y >= 0))
		return (true);
	return (false);
}

double	get_percent(int n1, int n2, int current)
{
	double	p;
	double	d;

	p = current - n1;
	d = n2 - n1;
	if (d == 0)
		return (1.0);
	return (p / d);
}