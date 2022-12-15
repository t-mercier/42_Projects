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

#include "../inc/fdf.h"

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

static void	display_usage(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->_switch)
		while (i < 23)
			fdf->usage.n[i++]->enabled = true;
	else
		while (i < 23)
			fdf->usage.n[i++]->enabled = false;
	fdf->_switch = !fdf->_switch;
}

void	k_hook(mlx_key_data_t k, void *tmp)
{
	t_fdf	*fdf;

	fdf = (void *)tmp;
	(void) k;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_DIVIDE))
		return (switch_view(fdf), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_SPACE))
		return (display_usage(fdf), project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT_SHIFT))
		return (fdf->_invert = !fdf->_invert, project(fdf));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_9))
	{
		fdf->_blink = false;
		return (fdf->_color = !fdf->_color, project(fdf));
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
	{
		fdf->_color = false;
		return (fdf->_blink = !fdf->_blink, project(fdf));
	}
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	(void) xdelta;
	if (fdf->t_s <= 5. && ydelta > 0)
		return (fdf->t_s += 0.1, project(fdf));
	if (fdf->t_s <= 5. && ydelta < 0)
		return (fdf->t_s -= 0.1, project(fdf));
	if (fdf->t_s <= 10. && ydelta > 0)
		return (fdf->t_s += 0.5, project(fdf));
	if (fdf->t_s <= 10. && ydelta < 0)
		return (fdf->t_s -= 0.5, project(fdf));
	if (fdf->t_s > 10. && ydelta > 0)
		return (fdf->t_s += 1.3, project(fdf));
	if (fdf->t_s > 10. && ydelta < 0)
		return (fdf->t_s -= 1.3, project(fdf));
}
