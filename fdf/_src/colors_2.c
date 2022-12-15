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

uint32_t	pastel(t_fdf *fdf, int z)
{
	double	pct;

	pct = get_percent(fdf->z_min, fdf->z_max, z);
	if (pct < 0.05)
		return (0xa9bcffff);
	else if (pct < 0.1)
		return (0x9affffff);
	else if (pct < 0.2)
		return (0x18ffb1ff);
	else if (pct < 0.3)
		return (0xffffadff);
	else if (pct < 0.4)
		return (0xffd493ff);
	else if (pct < 0.6)
		return (0xff9f8cff);
	return (0xFF75B3ff);
}

uint32_t	midnight(t_fdf *fdf, int z)
{
	double	pct;

	pct = get_percent(fdf->z_min, fdf->z_max, z);
	if (pct < 0.15)
		return (0x00202eff);
	else if (pct < 0.2)
		return (0x003f5cff);
	else if (pct < 0.3)
		return (0x2c4875ff);
	else if (pct < 0.4)
		return (0x8a508fff);
	else if (pct < 0.5)
		return (0xbc5090ff);
	else if (pct < 0.6)
		return (0xff6361ff);
	else if (pct < 0.7)
		return (0xff8531ff);
	else if (pct < 0.8)
		return (0xffa600ff);
	return (0xffd380ff);
}

uint32_t	grapes(int z)
{
	if (z > 100.)
		return (0xd6b7c1ff);
	if (z > 75.)
		return (0xac6f82ff);
	if (z > 50.)
		return (0xa4637eff);
	if (z > 25.)
		return (0x9b577aff);
	if (z > 15.)
		return (0x893f71ff);
	if (z > 10.)
		return (0x782769ff);
	if (z > 5.)
		return (0x660e60ff);
	if (z > 0.)
		return (0x5a0d54ff);
	if (z > -10.)
		return (0x4d0b48ff);
	if (z > -20.)
		return (0x330730ff);
	if (z > -50.)
		return (0x270624ff);
	return (0x1a0418ff);
}

uint32_t	dark(int z)
{
	if (z > 100.)
		return (0xc7a5aaff);
	if (z > 75.)
		return (0xb19297ff);
	if (z > 50.)
		return (0xa78a8eff);
	if (z > 25.)
		return (0x9c8185ff);
	if (z > 15.)
		return (0x877074ff);
	if (z > 10.)
		return (0x7d676bff);
	if (z > 5.)
		return (0x735e62ff);
	if (z > 0.)
		return (0x5e4d50ff);
	if (z > -10.)
		return (0x4a3c3fff);
	if (z > -20.)
		return (0x352b2dff);
	if (z > -50.)
		return (0x21191cff);
	return (0x0C080Aff);
}

uint32_t	forest(int z)
{
	if (z > 100.)
		return (0xFFFFE755);
	if (z > 50.)
		return (0xFFFFE755);
	if (z > 30.)
		return (0xD3E7A355);
	if (z > 20.)
		return (0x8baf7955);
	if (z > 10.)
		return (0x51704a55);
	if (z > 0.)
		return (0x3b503755);
	return (0x51704a55);
}
