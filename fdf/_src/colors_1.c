/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 21:39:43 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/16 21:39:43 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/fdf.h"

uint32_t	_blink(t_fdf *fdf)
{
	return (_trgb(fdf->rgb.a, fdf->rgb.r,
				  fdf->rgb.g, fdf->rgb.b));
}

uint32_t	_random(t_fdf *fdf, int p0, int p1)
{
	return (_trgb(fdf->rgb.a + p0, fdf->rgb.r - (p0 + p1),
			fdf->rgb.g - p0, fdf->rgb.b - p1));
}

uint32_t	get_color(t_fdf *fdf, int z)
{
	if (fdf->palette == 1)
		fdf->color = grey(z);
	if (fdf->palette == 2)
		fdf->color = forest(z);
	if (fdf->palette == 3)
		fdf->color = pastel(z);
	if (fdf->palette == 4)
		fdf->color = fire(fdf, z);
	if (fdf->palette == 5)
		fdf->color = midnight(z);
	if (fdf->palette == 6)
		fdf->color = grapes(z);
	if (fdf->palette == 7)
		fdf->color = dark(z);
	if (fdf->palette == 8)
		fdf->color = WHITE;
	return (fdf->color);
}

uint32_t	fire(t_fdf *fdf, int z)
{
	double	pct;

	pct = get_percent(fdf->z_min, fdf->z_max, z);
	if (pct < 0.2)
		return (0xA10100FF);
	else if (pct < 0.3)
		return (0xDA1F05FF);
	else if (pct < 0.4)
		return (0xF33C04FF);
	else if (pct < 0.6)
		return (0xFE650DFF);
	else if (pct < 0.8)
		return (0xFFC11FFF);
	else
		return (0x6B1F20FF);
}

uint32_t	grey(int z)
{
	if (z > 100.)
		return (0xEDEDEDFF);
	if (z > 75.)
		return (0xE0E0E0FF);
	if (z > 50.)
		return (0xD4D4D4FF);
	if (z > 25.)
		return (0xA3A3A3FF);
	if (z > 15.)
		return (0x6E6E6EFF);
	if (z > 0.)
		return (0x505050FF);
	if (z > -10.)
		return (0x414141FF);
	if (z > -20.)
		return (0x212121FF);
	return (0x3F3A63FF);
}
