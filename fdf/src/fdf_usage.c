/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_usage.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 22:47:07 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	unable_usage(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < 12)
		fdf->usage[i++]->enabled = true;
}

void	disable_usage(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < 12)
		fdf->usage[i++]->enabled = false;
}

void	display_usage(t_fdf *fdf)
{
	int	x;
	int	y;

	x = WIDTH - 400;
	y = 30;
	fdf->usage[0] = mlx_put_string(fdf->mlx,
									"Usage on / off   [ space ]",
									x,
									y);
	fdf->usage[1] = mlx_put_string(fdf->mlx,
									"Close window     [ esc ]",
									x,
									y += 25);
	fdf->usage[2] = mlx_put_string(fdf->mlx,
									"Move             [ < ^ v > ]",
									x,
									y += 25);
	fdf->usage[3] = mlx_put_string(fdf->mlx,
									"Rotation - Z     [ Q ] [ W ]",
									x,
									y += 25);
	fdf->usage[4] = mlx_put_string(fdf->mlx,
									"Rotation - Y     [ A ] [ S ]",
									x,
									y += 25);
	fdf->usage[5] = mlx_put_string(fdf->mlx,
									"Rotation - X     [ Z ] [ X ]",
									x,
									y += 25);
	fdf->usage[6] = mlx_put_string(fdf->mlx,
									"Rotate all axes  [ page ^ ] [ page v ]",
									x,
									y += 25);
	fdf->usage[7] = mlx_put_string(fdf->mlx,
									"Zoom             [ + ] [ - ]",
									x,
									y += 25);
	fdf->usage[8] = mlx_put_string(fdf->mlx,
									"Isometry         [ P ]",
									x,
									y += 25);
	fdf->usage[9] = mlx_put_string(fdf->mlx,
									"Depth +/-        [ I ] [ O ]",
									x,
									y += 25);
	fdf->usage[10] = mlx_put_string(fdf->mlx,
									"View from top    [ / ]",
									x,
									y += 25);
	fdf->usage[11] = mlx_put_string(fdf->mlx,
									"Switch color     [ C ]",
									x,
									y += 25);
}

void	display_baseline(t_fdf *fdf)
{
	fdf->baseline = mlx_put_string(fdf->mlx,
									"Display usage : [ space ]",
									50,
									HEIGHT - 50);
}