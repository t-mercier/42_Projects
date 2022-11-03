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

void trace(mlx_image_t *image, t_xyz _0, t_xyz _1, int color) {

	if (_0.x > image->width || _1.x > image->width ||
		_0.y > image->height || _1.y > image->height)
		return;
	int dx = abs(_1.x - _0.x);
	int sx = _0.x < _1.x ? 1 : -1;
	int dy = -abs(_1.y - _0.y);
	int sy = _0.y < _1.y ? 1 : -1;
	int error = dx + dy;

	while (1) {
		mlx_put_pixel(image, abs(_0.x), abs(_0.y), color);
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

