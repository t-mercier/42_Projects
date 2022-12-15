/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 21:46:29 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib42.h"

double	get_percent(int n1, int n2, int current)
{
	double	p;
	double	d;

	p = current - n1;
	d = n2 - n1;
	if (d == 0)
		return (1.0);
	return (p / d);
}

static void	_init_s_d(t_point _0, t_point _1, t_bresenham *p)
{
	p->d.x = abs(_1.x - _0.x);
	p->s.x = tern_int(_0.x < _1.x, 1, -1);
	p->d.y = -abs(_1.y - _0.y);
	p->s.y = tern_int(_0.y < _1.y, 1, -1);
	p->e = ((p->d.x + p->d.y));
}

static void	_narrow(t_bresenham *p, t_point *_0, t_point _1)
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

void	drawline(mlx_image_t *img, t_point _0, t_point _1, uint32_t c)
{
	t_bresenham	p;

	p = (t_bresenham){};
	_init_s_d(_0, _1, &p);
	while (1)
	{
		if (((uint32_t)_0.x >= 0 && (uint32_t)_0.x < img->width)
			&& ((uint32_t)_0.y >= 0 && (uint32_t)_0.y < img->height))
			mlx_put_pixel(img, _0.x, _0.y, c);
		if (_0.x == _1.x && _0.y == _1.y)
			break ;
		p.e2 = p.e;
		_narrow(&p, &_0, _1);
	}
}
