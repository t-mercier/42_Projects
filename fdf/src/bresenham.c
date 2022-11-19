/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_trace.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static bool	out_perimeter(mlx_image_t *img, t_vertex _0, t_vertex _1)
{
	return (_0.x >= img->width || _1.x >= img->width || _0.y >= img->height
		|| _1.y >= img->height);
}

static int	init_s_d(t_vertex _0, t_vertex _1, t_bresenham *p)
{
	p->d.x = abs(_1.x - _0.x);
	p->s.x = tern_int(_0.x < _1.x, 1, -1);
	p->d.y = -abs(_1.y - _0.y);
	p->s.y = tern_int(_0.y < _1.y, 1, -1);
	return (p->d.x + p->d.y);
}

static void	narrow_(t_bresenham *p, t_vertex *_0, t_vertex _1)
{
	if (p->e2 >= p->d.y && _0->x != _1.x)
	{
		p->e += p->d.y;
		_0->x += p->s.x;
	}
	if (p->e2 <= p->d.x && _0->y != _1.y)
	{
		p->e += p->d.x;
		_0->y += p->s.y;
	}
}

void	drawline(mlx_image_t *img, t_vertex _0, t_vertex _1, uint32_t color)
{
	t_bresenham	p;

	p = (t_bresenham){};
	if (out_perimeter(img, _0, _1))
		return ;
	p.e = init_s_d(_0, _1, &p);
	while (1)
	{
		mlx_put_pixel(img, abs(_0.x), abs(_0.y), color);
		if (_0.x == _1.x && _0.y == _1.y)
			break ;
		p.e2 = p.e;
		narrow_(&p, &_0, _1);
	}
}
