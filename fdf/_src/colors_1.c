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
	if (fdf->scheme == 8)
		fdf->color = WHITE;
	if (fdf->scheme == 1)
		fdf->color = grey(z);
	if (fdf->scheme == 2)
		fdf->color = forest(z);
	if (fdf->scheme == 3)
		fdf->color = pastel(z);
	if (fdf->scheme == 4)
		fdf->color = fire(z);
	if (fdf->scheme == 5)
		fdf->color = midnight(z);
	if (fdf->scheme == 6)
		fdf->color = grapes(z);
	if (fdf->scheme == 7)
		fdf->color = dark(z);
	return (fdf->color);
}

uint32_t	fire(int z)
{
	if (z > 100)
		return (0xFFDF8DFF);
	if (z > 75)
		return (0xFFDE7AFF);
	if (z > 50)
		return (0xFFC568FF);
	if (z > 25)
		return (0xFD996BFF);
	if (z > 15)
		return (0xF7856CFF);
	if (z > 10)
		return (0xF06E6CFF);
	if (z > 5)
		return (0xD9576BFF);
	if (z >= 0)
		return (0xA44369FF);
	if (z > -10)
		return (0x833F68FF);
	if (z > -20)
		return (0x833F68FF);
	if (z > -50)
		return (0x5E3C65FF);
	return (0x3F3A63FF);
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
