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

uint32_t	pastel(int z)
{
	if (z > 100.)
		return (0xffadadff);
	if (z > 75.)
		return (0xffd6a5ff);
	if (z > 50.)
		return (0xfdffb6ff);
	if (z > 25.)
		return (0xcaffbfff);
	if (z > 15.)
		return (0x9bf6ffff);
	if (z > 0.)
		return (0x9bf6ffff);
	if (z > -10.)
		return (0xa0c4ffff);
	if (z > -20.)
		return (0xbdb2ff8f);
	return (0xffc6ff6f);
}

uint32_t	midnight(int z)
{
	if (z > 100.)
		return (0xfbf2c4ff);
	if (z > 75.)
		return (0xfbf2c4ff);
	if (z > 50.)
		return (0xffd380ff);
	if (z > 25.)
		return (0xffa600ff);
	if (z > 15.)
		return (0xff8531ff);
	if (z > 10.)
		return (0xff6361ff);
	if (z > 5.)
		return (0xbc5090ff);
	if (z > 0.)
		return (0x8a508fff);
	if (z > -10.)
		return (0x8a508fff);
	if (z > -20.)
		return (0x2c4875ff);
	if (z > -50.)
		return (0x003f5cff);
	return (0x00202eff);
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
