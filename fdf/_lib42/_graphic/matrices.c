/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:42:49 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:42:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* The calloc() function contiguously allocates enough space for count
 * objects that are size bytes of memory each and returns a pointer to the
 * allocated memory. The allocated memory is filled with bytes of value zero.
 * Returns a pointer to allocated memory. */

#include "../inc/graphic.h"

t_matrix	build_matrix(t_rotate r)
{
	t_matrix	m;

	m = (t_matrix){};
	init_cos_sin(&r, NULL);
	m.r11 = r.cy * r.cz;
	m.r12 = r.sx * r.sy * r.cz - r.cx * r.sz;
	m.r13 = r.sx * r.sz + r.cx * r.sy * r.cz;
	m.r21 = r.cy * r.sz;
	m.r22 = r.cx * r.cz + r.sx * r.sy * r.sz;
	m.r23 = r.cx * r.sy * r.sz - r.sx * r.cz;
	m.r31 = -r.sy;
	m.r32 = r.sx * r.cy;
	m.r33 = r.cx * r.cy;
	return (m);
}

t_rotate	matrix_to_angle(t_matrix a)
{
	t_rotate	r;

	r.pitch = -asin(a.r31);
	if (a.r31 == 1)
	{
		r.yaw = 0.0;
		r.roll = atan2(-a.r12, -a.r13);
	}
	else if (a.r31 == -1)
	{
		r.yaw = 0.0;
		r.roll = atan2(a.r12, a.r13);
	}
	else
	{
		r.yaw = atan2(a.r21, a.r11);
		r.roll = atan2(a.r32, a.r33);
	}
	return (r);
}

t_vertex	matrix_to_px(t_matrix a, t_vertex p_in, void *param)
{
	t_vertex	p_out;

	if (!param)
		param = NULL;
	p_out.x = a.r11 * p_in.x + a.r12 * p_in.y + a.r13 * p_in.z;
	p_out.y = a.r21 * p_in.x + a.r22 * p_in.y + a.r23 * p_in.z;
	p_out.z = a.r31 * p_in.x + a.r32 * p_in.y + a.r33 * p_in.z;
	return (p_out);
}
