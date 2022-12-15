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

#include "../inc/fdf.h"

uint32_t	_blink(t_fdf *fdf)
{
	return (rgba_hex(fdf->rgba.a, fdf->rgba.r,
			fdf->rgba.g, fdf->rgba.b));
}

uint32_t	_random(t_fdf *fdf, int p0, int p1)
{
	return (rgba_hex(fdf->rgba.a + p0, fdf->rgba.r - (p0 + p1),
			fdf->rgba.g - p0, fdf->rgba.b - p1));
}

uint32_t	get_color(t_fdf *fdf, int z)
{
	if (fdf->palette == 1)
		fdf->color = grey(fdf, z);
	if (fdf->palette == 2)
		fdf->color = forest(z);
	if (fdf->palette == 3)
		fdf->color = pastel(fdf, z);
	if (fdf->palette == 4)
		fdf->color = fire(fdf, z);
	if (fdf->palette == 5)
		fdf->color = midnight(fdf, z);
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

uint32_t	grey(t_fdf *fdf, int z)
{
	double	pct;

	pct = get_percent(fdf->z_min, fdf->z_max, z);
	if (pct < 0.1)
		return (0x212121FF);
	else if (pct < 0.2)
		return (0x414141FF);
	else if (pct < 0.3)
		return (0x505050FF);
	else if (pct < 0.4)
		return (0x6E6E6EFF);
	else if (pct < 0.5)
		return (0xA3A3A3FF);
	else if (pct < 0.6)
		return (0xD4D4D4FF);
	else if (pct < 0.7)
		return (0xE0E0E0FF);
	else if (pct < 0.8)
		return (0xEDEDEDFF);
	return (0x3F3A63FF);
}
