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

#include "../inc/fdf.h"

static void	define_usage(t_fdf *fdf)
{
	fdf->usage.s[0] = "Usage on / off   [ space ]";
	fdf->usage.s[1] = "Close window     [ esc ]";
	fdf->usage.s[2] = "\n";
	fdf->usage.s[3] = "| MOVE";
	fdf->usage.s[4] = "---------------------------------------";
	fdf->usage.s[5] = "Move             [ < ^ v > ]";
	fdf->usage.s[6] = "Zoom +/-         [ mouse scroll ]";
	fdf->usage.s[7] = "Depth +/-        [ + ] [ - ]";
	fdf->usage.s[8] = "Flatten          [ / ]";
	fdf->usage.s[9] = "\n";
	fdf->usage.s[10] = "| ROTATION";
	fdf->usage.s[11] = "---------------------------------------";
	fdf->usage.s[12] = "Rotation - Z     [ Q ] [ W ]";
	fdf->usage.s[13] = "Rotation - Y     [ A ] [ S ]";
	fdf->usage.s[14] = "Rotation - X     [ Z ] [ X ]";
	fdf->usage.s[15] = "Rotate all axes  [ page ^ ] [ page v ]";
	fdf->usage.s[16] = "\n";
	fdf->usage.s[17] = "| COLORS";
	fdf->usage.s[18] = "---------------------------------------";
	fdf->usage.s[19] = "Switch           [ 1 ] -> [ 8 ]";
	fdf->usage.s[20] = "Motion           [ 9 ]";
	fdf->usage.s[21] = "Blink            [ 0 ]";
	fdf->usage.s[22] = "Reverse	         [ right shift ]";
}

void	init_usage(t_fdf *fdf)
{
	int		y;
	int		x;
	int		i;

	i = 0;
	x = 20;
	y = 20;
	define_usage(fdf);
	while (i < 23)
	{
		fdf->usage.n[i] = mlx_put_string(fdf->mlx,
				fdf->usage.s[i], x, y);
		y += 25;
		i++;
	}
}
