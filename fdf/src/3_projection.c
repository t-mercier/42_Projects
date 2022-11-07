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

void	line(mlx_image_t *image, int x0, int y0, int x1, int y1, uint32_t color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	error;
	int	e2;

	if (x0 > image->width || x1 > image->width || y0 > image->height ||
		y1 > image->height)
		return ;
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	error = dx + dy;
	while (1)
	{
		mlx_put_pixel(image, abs(x0), abs(y0), color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			error += dx;
			y0 += sy;
		}
	}
}


void	projection(t_vector *map, t_fdf *fdf)
{
	t_vertex	_0;
	t_index		i;
	t_vector	*row;

	i.y = 0;
	ft_memset(&_0, 0, sizeof(t_vertex));
	while (i.y < fdf->size.y)
	{
		i.x = 0;
		row = ((t_vector **)map->item)[i.y];
		while (i.x < fdf->size.x)
		{
			project_0(fdf, row, &_0, i);
			project_1(fdf, map, _0, i);
			i.x++;
		}
		i.y++;
	}
}
