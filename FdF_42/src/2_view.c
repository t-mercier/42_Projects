/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3_algo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_control_movement(mlx_key_data_t k, t_fdf *fdf)
{
    if (k.key == MLX_KEY_UP || k.key == MLX_KEY_W)
        fdf->set.vert -= 5;
    if (k.key == MLX_KEY_DOWN || k.key == MLX_KEY_S)
        fdf->set.vert += 5;
    if (k.key == MLX_KEY_LEFT || k.key == MLX_KEY_A)
        fdf->set.horiz -= 5;
    if (k.key == MLX_KEY_RIGHT || k.key == MLX_KEY_D)
        fdf->set.horiz += 5;
    modify_mesh(fdf);
}

void	set_control_view(mlx_key_data_t keydata, t_fdf *fdf)
{
    if (keydata.key == MLX_KEY_T)
        fdf->set.perspective = TOP_VIEW;
    if (keydata.key == MLX_KEY_I)
        fdf->set.perspective = ISOMETRIC;
    modify_mesh(fdf);
}

void	ft_key_hook(mlx_key_data_t k, void* param)
{
    t_fdf	*fdf;
    keys_t	key;

    fdf = param;
    key = k.key;
	if (k.key == MLX_KEY_Q && k.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
    if (k.key == MLX_KEY_Z)
        fdf->set.rot_angle += 0.04;
    if (k.key == MLX_KEY_X)
        fdf->set.rot_angle -= 0.04;
    if (k.key == MLX_KEY_KP_SUBTRACT || k.key == MLX_KEY_MINUS || k.key == MLX_KEY_PAGE_DOWN)
        fdf->set.height -= 0.02;
    if (k.key == MLX_KEY_KP_ADD || k.key == MLX_KEY_PAGE_UP)
        fdf->set.height += 0.02;

}
void    set_control_height(mlx_key_data_t k, t_fdf *fdf)
{
    if (k.key == MLX_KEY_KP_SUBTRACT || k.key == MLX_KEY_MINUS || k.key == MLX_KEY_PAGE_DOWN)
        fdf->set.height -= 0.02;
    if (k.key == MLX_KEY_KP_ADD || k.key == MLX_KEY_PAGE_UP)
        fdf->set.height += 0.02;
    modify_mesh(fdf);
}

void    set_control_rotation(mlx_key_data_t k, t_fdf *fdf)
{
    if (k.key == MLX_KEY_Z)
        fdf->set.rot_angle += 0.04;
    if (k.key == MLX_KEY_X)
        fdf->set.rot_angle -= 0.04;
    modify_mesh(fdf);
}

void	move_img(mlx_key_data_t k, void* param)
{
    t_fdf	*fdf;
    keys_t	key;

    fdf = param;
    key = k.key;
    if (key == MLX_KEY_A && k.action == MLX_RELEASE && k.modifier == MLX_CONTROL)
        puts("Gotta grab it all!");
    if (key == MLX_KEY_ESCAPE)
        mlx_close_window(fdf->mlx);
    if (key >= MLX_KEY_RIGHT && key <= MLX_KEY_UP && key >= MLX_KEY_W && key <= MLX_KEY_A)
        set_control_movement(k, fdf);
    if (key == MLX_KEY_T || key == MLX_KEY_I)
        set_control_view(k, fdf);
    if (key == 333 || key == 45 || key == 267 || key == 334 || key == 266)
        set_control_height(k, fdf);
    if (key == MLX_KEY_Z || key == MLX_KEY_X)
        set_control_rotation(k, fdf);
}