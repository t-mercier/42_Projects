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
		fdf->set.offset.axis.y += 1 + TILESIZE * 0.2 + WIDTH * 0.05;
    if (fdf->press.key == MLX_KEY_DOWN)
		fdf->set.offset.axis.y -= 1 + TILESIZE * 0.2 + WIDTH * 0.05;
	if (fdf->press.key == MLX_KEY_RIGHT)
		fdf->set.offset.axis.x += 1 + TILESIZE * 0.2 + WIDTH * 0.05;
    if (fdf->press.key == MLX_KEY_LEFT)
		fdf->set.offset.axis.x -= 1 + TILESIZE * 0.2 + WIDTH * 0.05;
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

}

void    control_rotation(t_fdf *fdf)
{
    if (fdf->press.key == MLX_KEY_)
		fdf->set.angle += 0.04;
    if (fdf->press.key == MLX_KEY_X)
		fdf->set.angle -= 0.04;
	rotate(fdf, fdf->p);
}

//
//void	control_hook(t_fdf *fdf, mlx_key_data_t press, t_key *k)
//{
//
//}