/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 12:52:36 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/24 12:52:36 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/graphic.h"

uint32_t	_color(int color)
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	a = 0xFF & (color >> 24);
	r = 0xFF & (color >> 16);
	g = 0xFF & (color >> 8);
	b = 0xFF & (color);
	return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t	set_g(uint32_t trgb, uint8_t g)
{
	return (trgb & ((g >> 8) & 0xff));
}

int	_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
