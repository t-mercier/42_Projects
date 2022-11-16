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

void	drawline(mlx_image_t *image, t_vertex _0, t_vertex _1, uint32_t color)
{
	t_vertex d;
	t_vertex s;
	int	error;
	int	e2;

	if (_0.x >= image->width || _1.x >= image->width \
	|| _0.y >= image->height || _1.y >= image->height)
		return ;
	d.x = abs(_1.x - _0.x);
	s.x = _0.x < _1.x ? 1 : -1;
	d.y = -abs(_1.y - _0.y);
	s.y = _0.y < _1.y ? 1 : -1;
	error = d.x + d.y;
	while (1)
	{
		mlx_put_pixel(image, abs(_0.x), abs(_0.y), color);
		if (_0.x == _1.x && _0.y == _1.y)
			break ;
		e2 = 2 * error;
		if (e2 >= d.y)
		{
			if (_0.x == _1.x)
				break ;
			error += d.y;
			_0.x += s.x;
		}
		if (e2 <= d.x)
		{
			if (_0.y == _1.y)
				break ;
			error += d.x;
			_0.y += s.y;
		}
	}
}

void	calibration(t_fdf *fdf)
{
	fdf->tile_size = 50;
	fdf->x_offset  = WIDTH - (WIDTH / 2);
	fdf->y_offset  = HEIGHT - (HEIGHT / 2);

}
