/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	hook(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_P))
		mlx_delete_image(fdf->mlx, fdf->img);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->y_offset -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->y_offset += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->x_offset -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->x_offset += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		fdf->tile_size += 2;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		fdf->tile_size -= 2;
	//	if (press.key == 333 || fdf->press.key == 45)
	//		fdf->map.zoom -= 0.02;
	//	if (press.key == MLX_KEY_KP_ADD)
	//		fdf->map.zoom += 0.02;
	projection(fdf->map, fdf);
}

//void scrollhook(double xdelta, double ydelta, t_fdf *fdf)
//{
//	(void) xdelta;
//	if (ydelta > 0)
//		fdf->img->instances[0].z -= 1;
//	else if (ydelta < 0)
//		fdf->img->instances[0].z += 1;
//	projection(fdf->map, &fdf);
//
//
//}