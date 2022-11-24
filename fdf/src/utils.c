/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	calibration(t_fdf *fdf)
{
	fdf->width = WIDTH;
	fdf->tile_size = 20;
	fdf->offset.x = WIDTH - (WIDTH / 2);
	fdf->offset.y = HEIGHT - (HEIGHT / 2);
	fdf->rgb = 0xFF0000;
	fdf->r.yaw = 0;
	fdf->r.pitch = 0;
	fdf->r.roll = 0;
	fdf->angle = 35.264;
	fdf->isometry = true;
}

void	usage(void)
{
	char	*s;

	s = "usage: ./fdf maps/[ map.fdf ] \n";
	write(1, s, ft_strlen(s));
	exit(0);
}
