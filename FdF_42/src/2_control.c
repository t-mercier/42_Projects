/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2_view.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:36:58 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/02 15:36:58 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void	control_offset(t_fdf *fdf)
{
    if (fdf->press.key == MLX_KEY_UP)
		fdf->set.y_offset += 10;
    if (fdf->press.key == MLX_KEY_DOWN)
		fdf->set.y_offset -= 10;
	if (fdf->press.key == MLX_KEY_RIGHT)
		fdf->set.x_offset += 10;
    if (fdf->press.key == MLX_KEY_LEFT)
		fdf->set.x_offset -= 10;
	draw_map(fdf);
}

/*
 * zoom in : MLX_KEY_KP_ADD
 * zoom out : MLX_KEY_KP_SUBTRACT || MLX_KEY_MINUS
 */
void    control_zoom(t_fdf *fdf)
{
    if (fdf->press.key == 333 || fdf->press.key == 45)
		fdf->set.zoom -= 0.02;
    if (fdf->press.key == MLX_KEY_KP_ADD)
		fdf->set.zoom += 0.02;
	draw_map(fdf);
}

void    control_rotation(t_fdf *fdf)
{
    if ((fdf->press.key == MLX_KEY_LEFT_CONTROL
	|| fdf->press.key == MLX_KEY_RIGHT_CONTROL) && fdf->press.key == MLX_KEY_UP)
		fdf->set.angle += 0.04;
    if ((fdf->press.key == MLX_KEY_LEFT_CONTROL
	|| fdf->press.key == MLX_KEY_RIGHT_CONTROL) && fdf->press.key == MLX_KEY_DOWN)
		fdf->set.angle -= 0.04;
	rotate(&fdf->map->p, fdf->set.angle);
	draw_map(fdf);
}

void	control_hook(t_fdf *fdf)
{
	if (fdf->press.key == MLX_KEY_ESCAPE)
		exit(0);
}

void	control_loop_hook(t_fdf *fdf)
{
	if (fdf->press.key == 333 || fdf->press.key == 45 || fdf->press.key == 334)
		control_zoom(fdf);
	else if (fdf->press.key > 261 && fdf->press.key < 266)
		control_offset(fdf);
	else if ((fdf->press.key == 341 || fdf->press.key == 345)
	&& fdf->press.key > 261 && fdf->press.key < 266)
		control_rotation(fdf);
}
