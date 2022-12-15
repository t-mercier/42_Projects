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

t_vertex	rotate_x(t_vertex p, t_rotate r, void *param)
{
	t_vertex	t;
	double		angle;

	if (!param)
		param = NULL;
	t = p;
	angle = deg_to_rad(r.yaw);
	p.x = t.x;
	p.y = t.y * cos(angle) + t.z * -sin(angle);
	p.z = t.y * sin(angle) + t.z * cos(angle);
	return (p);
}

t_vertex	rotate_y(t_vertex p, t_rotate r, void *param)
{
	t_vertex	t;
	double		angle;

	if (!param)
		param = NULL;
	t = p;
	angle = deg_to_rad(r.pitch);
	p.x = t.x * cos(angle) + t.z * sin(angle);
	p.y = t.y;
	p.z = t.x * -sin(angle) + t.z * cos(angle);
	return (p);
}

t_vertex	rotate_z(t_vertex p, t_rotate r, void *param)
{
	t_vertex	t;
	double		angle;

	if (!param)
		param = NULL;
	t = p;
	angle = deg_to_rad(r.roll);
	p.x = t.x * cos(angle) + t.y * -sin(angle);
	p.z = t.x * sin(angle) + t.y * cos(angle);
	p.y = t.z;
	return (p);
}
