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


#include "../include/fdf.h"
#define DEG2RAD (360.0 * M_PI / 180)

static int	_color(int color)
{

	unsigned char a = 0xFF & (color >> 24);
	unsigned char r = 0xFF & (color >> 16);
	unsigned char g = 0xFF & (color >> 8);
	unsigned char b = 0xFF & (color);
	return (a << 24 | r << 16 | g << 8 | b);
}

int			color(t_vertex _0, t_vertex _1)
{
	int h;

	h = _0.z - _1.z;
	if (h == 0)
		return (0xFFFFFFFF);
	else if (h >= 15)
		return (0xff4000FF);
	else if (h < 0)
		return (0x191970FF);
	else if (h > 0 && h < 5)
		return (0xffa500FF);
	else if (h >= 5 && h < 15)
		return (0xff8000FF);
	else
		return (0xFFFFFF);
}