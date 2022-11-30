/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 22:47:59 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/fdf.h"

static void	usage_status(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->_switch)
	{
		while (i < 11)
			fdf->usage.n[i++]->enabled = true;
	}
	else
	{
		while (i < 11)
			fdf->usage.n[i++]->enabled = false;
	}
}

static void	display_usage(t_fdf *fdf)
{
	if (fdf->_switch)
		usage_status(fdf);
	else
		usage_status(fdf);
	fdf->_switch = !fdf->_switch;
}

static void	iso_view(t_fdf *fdf, bool _iso)
{
	if (_iso)
	{
		fdf->r.yaw = 0.;
		fdf->r.pitch = 0.;
		fdf->r.roll = 0.;
		fdf->depth = 1.;
	}
	else
	{
		fdf->r.yaw = 315.;
		fdf->r.pitch = 0.;
		fdf->r.roll = 315.;
		fdf->depth = 0.;
	}
}

static void	switch_view(t_fdf *fdf)
{
	if (fdf->_view)
		iso_view(fdf, true);
	else
		iso_view(fdf, false);
	fdf->_view = !fdf->_view;
	fdf->_iso = !fdf->_iso;
}

void	k_hook(mlx_key_data_t k, void *p)
{
	t_fdf	*fdf;

	fdf = (void *)p;
	(void)k;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_SPACE))
		display_usage(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_DIVIDE))
		switch_view(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT_SHIFT))
		fdf->_invert = !fdf->_invert;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	project(fdf);
}
