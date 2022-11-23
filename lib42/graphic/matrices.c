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

#include "../_inc/graphic.h"

t_matrice build_matrice(t_rotate r)
{
	t_matrice a = (t_matrice){};

	init_cos_sin(&r, NULL);
	a.r11 = r.cy * r.cz;
	a.r12 = r.sx * r.sy * r.cz - r.cx * r.sz;
	a.r13 = r.sx * r.sz + r.cx * r.sy * r.cz;

	a.r21 = r.cy * r.sz;
	a.r22 = r.cx * r.cz + r.sx * r.sy* r.sz;
	a.r23 = r.cx * r.sy * r.sz - r.sx * r.cz;

	a.r31 = -r.sy;
	a.r32 = r.sx * r.cy;
	a.r33 = r.cx * r.cy;

	return a;
}

t_rotate matrix_to_angle(t_matrice a)
{
	t_rotate r;

	r.pitch = -asin( a.r31 );

	if (a.r31 == 1)
	{
		r.yaw = 0.0;
		r.roll = atan2( -a.r12, -a.r13 );
	}
	else if (a.r31 == -1 )
	{
		r.yaw = 0.0;
		r.roll = atan2(a.r12, a.r13);
	}
	else
	{
		r.yaw = atan2(a.r21, a.r11);
		r.roll = atan2(a.r32, a.r33);
	}
	return r;   //Euler angles in order yaw, pitch, roll
}

t_vertex matrice_to_px(t_matrice a, t_vertex p_in, void *param)
{
	t_vertex p_out;

	p_out.x = a.r11 * p_in.x + a.r12 * p_in.y + a.r13 * p_in.z;
	p_out.y = a.r21 * p_in.x + a.r22 * p_in.y + a.r23 * p_in.z;
	p_out.z = a.r31 * p_in.x + a.r32 * p_in.y + a.r33 * p_in.z;
	return p_out; //Output coords in order (x,y,z)
}