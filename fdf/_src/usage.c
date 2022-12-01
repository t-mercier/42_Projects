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

#include "../_inc/fdf.h"

static void	define_usage(t_fdf *fdf)
{
	fdf->usage.s[0] = "Usage on / off   [ space ]";
	fdf->usage.s[1] = "Close window     [ esc ]";
	fdf->usage.s[2] = "Move             [ < ^ v > ]";
	fdf->usage.s[3] = "Rotation - Z     [ Q ] [ W ]";
	fdf->usage.s[4] = "Rotation - Y     [ A ] [ S ]";
	fdf->usage.s[5] = "Rotation - X     [ Z ] [ X ]";
	fdf->usage.s[6] = "Rotate all axes  [ page ^ ] [ page v ]";
	fdf->usage.s[7] = "Switch color     [ 0 ] -> [ 7 ]";
	fdf->usage.s[8] = "Random colors    [ 8 ]";
	fdf->usage.s[9] = "Zoom +/-         [ + ] [ - ]";
	fdf->usage.s[10] = "Depth +/-        [ I ] [ O ]";
	fdf->usage.s[11] = "Top view         [ / ]";
	fdf->usage.s[12] = "WOW Calme toi! Or you will crash my fdf ^_^";
	fdf->usage.s[13] = "disable/enable usage : [ space ]";
}

void	init_usage(t_fdf *fdf)
{
	int		y;
	int		x;
	int		i;
	size_t	len;

	i = 0;
	x = fdf->mlx->width * 80 / 100;
	y = fdf->mlx->height * 5 / 100;
	define_usage(fdf);
	len = ft_strlen(fdf->usage.s[12])
		* (size_t)(fdf->tile_size);
	fdf->warning = mlx_put_string(fdf->mlx,
			fdf->usage.s[12], WIDTH / 2 - len, HEIGHT / 3);
	fdf->baseline = mlx_put_string(fdf->mlx,
			fdf->usage.s[13], WIDTH * 5 / 100, HEIGHT * 55 / 100);
	fdf->warning->enabled = false;
	while (i < 12)
	{
		fdf->usage.n[i] = mlx_put_string(fdf->mlx,
				fdf->usage.s[i], x, y);
		y += 25;
		i++;
	}
}
