/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_usage.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 20:25:35 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	key_hook(mlx_key_data_t keydata, t_fdf *fdf)
// {
// 	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
// 		fdf->display_usage = false;
// 	project(fdf, fdf->map);
// }

static void unable_usage(t_fdf *fdf)
{
	int i = 0;
	while (i < 12)
		fdf->img_usage[i++]->enabled = true;
}

static void disable_usage(t_fdf *fdf)
{
	int i = 0;
	while (i < 12)
		fdf->img_usage[i++]->enabled = false;
}

bool	display_usage(t_fdf *fdf)
{
	if (fdf->display_usage)
		unable_usage(fdf);
	else
		disable_usage(fdf);
}

void	build_usage(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 20;
	x = WIDTH - 300;
	fdf->img_usage[0] = mlx_put_string(fdf->mlx, "Usage", x - 20, y);
	fdf->img_usage[1] = mlx_put_string(fdf->mlx, "Disable usage    |  space", x, y + 30);
	fdf->img_usage[2] = mlx_put_string(fdf->mlx, "Move             |  < ^ v >", x, y + 55);
	fdf->img_usage[3] = mlx_put_string(fdf->mlx, "Rotation [ Z ]   |  Q - W", x, y + 80);
	fdf->img_usage[4] = mlx_put_string(fdf->mlx, "Rotation [ Y ]   |  A - S", x, y + 105);
	fdf->img_usage[5] = mlx_put_string(fdf->mlx, "Rotation [ X ]   |  Z - X", x, y + 130);
	fdf->img_usage[6] = mlx_put_string(fdf->mlx, "Rotate all axes  |  Z - X", x, y + 155);
	fdf->img_usage[7] = mlx_put_string(fdf->mlx, "Zoom             |  + -", x, y + 205);
	fdf->img_usage[8] = mlx_put_string(fdf->mlx, "Scale up         |  page up", x, y + 230);
	fdf->img_usage[9] = mlx_put_string(fdf->mlx, "Scale down       |  page down", x, y + 255);
	fdf->img_usage[10] = mlx_put_string(fdf->mlx, "Projection       |  p", x, y + 280);
	fdf->img_usage[11] = mlx_put_string(fdf->mlx, "Colortheme       |  c", x, y + 305);
}
