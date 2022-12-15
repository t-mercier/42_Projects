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

#include "../inc/graphic.h"
#include "../inc/libft.h"

double	deg_to_rad(double degree)
{
	if (degree < 0)
		degree = 360;
	else if (degree > 360)
		degree = 0;
	return (degree * M_PI / 180);
}

void	init_cos_sin(t_rotate *r, void *param)
{
	if (!param)
		param = NULL;
	r->cx = (float)cos(deg_to_rad(r->roll));
	r->sx = (float)sin(deg_to_rad(r->roll));
	r->cy = (float)cos(deg_to_rad(r->pitch));
	r->sy = (float)sin(deg_to_rad(r->pitch));
	r->cz = (float)cos(deg_to_rad(r->yaw));
	r->sz = (float)sin(deg_to_rad(r->yaw));
}

void	mlx_error_exit(void)
{
	char	*s;

	s = ft_strdup(mlx_strerror(mlx_errno));
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
