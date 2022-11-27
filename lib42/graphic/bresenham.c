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

#include "../_inc/lib42.h"

static void	_init_s_d(t_vertex _0, t_vertex _1, t_bresenham *p)
{
	p->d.x = (double)abs(_1.x - _0.x);
	p->s.x = (double)tern_int(_0.x < _1.x, 1, -1);
	p->d.y = (double)-abs(_1.y - _0.y);
	p->s.y = (double)tern_int(_0.y < _1.y, 1, -1);
	p->e = (double)(p->d.x + p->d.y);
}

static void	_narrow(t_bresenham *p, t_vertex *_0, t_vertex _1)
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
	_init_s_d(_0, _1, &p);
	
	while (1)
	{
		if (((uint32_t)_0.x >= 0 && (uint32_t)_0.x < img->width) \
		&& ((uint32_t)_0.y >= 0 && (uint32_t)_0.y < img->height) )
			mlx_put_pixel(img, (uint32_t)_0.x, (uint32_t)_0.y, color);
			
		if (_0.x == _1.x && _0.y == _1.y)
			break ;
		p.e2 = p.e;
		_narrow(&p, &_0, _1);
	}

}
