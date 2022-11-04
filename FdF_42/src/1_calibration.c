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

void	scale(t_fdf *fdf)
{
	fdf->map->p.x += (fdf->map->row->len - fdf->map->grid->len) * TILE_WIDTH / 2  + fdf->set.x_offset;
	fdf->map->p.y += (fdf->map->row->len + fdf->map->grid->len) * TILE_HEIGHT / 2  + fdf->set.y_offset;
}

void	calibration(t_fdf *fdf)
{
	ft_malloc(&fdf->set, sizeof(t_set));
	fdf->set.zoom = _min(WIDTH / fdf->map->row->len / 2, HEIGHT / fdf->map->grid->len / 2);
	fdf->set.angle = 0;
	fdf->set.z_divisor = 1;
	fdf->set.x_offset = 0;
	fdf->set.y_offset = 0;
}


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

