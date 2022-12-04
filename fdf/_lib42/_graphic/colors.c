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

static double	get_percent(int p0, int p1, int current)
{
	double	p;
	double	d;

	p = current - p0;
	d = p1 - p0;
	if (d == 0)
		return (1.0);
	return (p / d);
}

static int	get_light(int p0, int p1, double pct)
{
//	t_rgb rgb;
//
//	rgb.a = (int)((1 - pct) * p0 + pct * p1);
//	rgb.r = (int)((1 - pct) * p0 + pct * p1);
//	rgb.g = (int)((1 - pct) * p0 + pct * p1);
//	rgb.b = (int)((1 - pct) * p0 + pct * p1);
//	return (rgb);
	return ((int)((1 - pct) * p0 + pct * p1));
}

static uint32_t	get_rgb(t_rgb rgb, int c)
{
	rgb.a = 0xFF & (c >> 24);
	rgb.r = 0xFF & (c >> 16);
	rgb.g = 0xFF & (c >> 8);
	rgb.b = 0xFF & (c);
	return (rgb.a << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
//	return (a << 24 | r << 16 | g << 8 | b);
}

int	_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

uint32_t	gradient_color(t_rgb rgb, t_point p0, t_point p1)
{
	double	pct;
	t_point d;
	t_point curr;

	curr = p0;
	d.x = abs(p1.x - p0.x);
	d.y = -abs(p1.y - p0.y);
	if (curr.c == p1.c)
		return (curr.c);
	if (d.x > d.y)
		pct = get_percent(p0.x, p1.x, curr.x);
	else
		pct = get_percent(p0.y, p1.y, curr.y);
	p0.c = (int)get_rgb(rgb, p0.c);
	p1.c = (int)get_rgb(rgb, p1.c);
//	rgb = get_light(p0.c, p1.c, pct);
	rgb.a = get_light(p0.c, p1.c, pct);
	rgb.r = get_light((p0.c >> 16) & 0xFF, (p1.c >> 16) & 0xFF, pct);
	rgb.g = get_light((p0.c >> 8) & 0xFF, (p1.c >> 8) & 0xFF, pct);
	rgb.b = get_light(p0.c & 0xFF, p1.c & 0xFF, pct);
	return (_trgb(rgb.a, rgb.r,
				  rgb.g, rgb.b));
}