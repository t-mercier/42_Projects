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


//void	background(mlx_t	*mlx)
//{
//	mlx = mlx_init(256, 256, "MLX42", true);
//	if (!mlx)
//		exit(EXIT_FAILURE);
//}

//int	abscisse(float n)
//{
//	if (n > 0)
//		return (-n);
//}

//void	drawline(t_map	*map)
//{
//	float x;
//	float y;
//	float next_x;
//	float next_y;
//	int i;
//
//	map->trace->point->x = map->trace->x1 - map->trace->x0;
//	map->trace->point->y = map->trace->y1 - map->trace->y0;
//	map->steps = abscisse(map->trace->point->x);
//
//// calculate steps required for generating pixels
//	if (abscisse(map->trace->point->x) <= abscisse(map->trace->point->y))
//		map->steps = abscisse(map->trace->point->y);
//
//// calculate increment in x & y for each steps
//	next_x = (float)abscisse(map->trace->point->x / (float)map->steps);
//	next_y = (float)abscisse(map->trace->point->y / (float)map->steps);
//
//	i = 0;
//	x = map->trace->x0;
//	y = map->trace->y0;
//	while (i <= map->steps)
//	{
//		mlx_put_pixel(map->img, (int32_t)roundf(x), (int32_t)roundf(y), RED);
//		x += next_x;
//		y += next_y;
//		delay(100);
//	}
//
//}
//
//void	isometric_projection(t_map *map)
//{
//
//}