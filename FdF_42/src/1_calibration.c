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

#include "fdf.h"

void	scale(t_fdf *fdf)
{
	fdf->d.x += fdf->map.x_offset;
	fdf->d.y += fdf->map.y_offset;
}

void	calibration(t_fdf *fdf)
{
//	fdf->map.zoom = _min(WIDTH / fdf->map.width / 2, HEIGHT / fdf->map.height / 2);
	fdf->map.angle = 0;
	fdf->map.z_divisor = 1;
	fdf->map.x_offset = 20;
	fdf->map.y_offset = 20;
}


void trace(mlx_image_t *img, t_xyz _0, t_xyz _1, int color) {

	if (_0.x > img->width || _1.x > img->width ||
		_0.y > img->height || _1.y > img->height)
		return;
	int dx = abs(_1.x - _0.x);
	int sx = _0.x < _1.x ? 1 : -1;
	int dy = -abs(_1.y - _0.y);
	int sy = _0.y < _1.y ? 1 : -1;
	int error = dx + dy;

	while (1) {
		mlx_put_pixel(img, abs(_0.x), abs(_0.y), color);
		if (_0.x == _1.x && _0.y == _1.y)
			break;
		int e2 = 2 * error;
		if (e2 >= dy) {
			if (_0.x == _1.x)
				break;
			error += dy;
			_0.x += sx;
		}
		if (e2 <= dx) {
			if (_0.y == _1.y)
				break;
			error += dx;
			_0.y += sy;
		}
	}
}

