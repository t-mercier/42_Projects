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

#include "../include/libft.h"

t_rotate matrix_to_angle(t_matrice a)
{
	t_rotate r;

	r.pitch = -asin( a.r31 );

	if (a.r31 == 1)
	{
		r.yaw = 0.0;
		r.roll = atan2( -a.r12, -a.r13 );
	}
	else if (a.r31 == -1 ){
		r.yaw = 0.0;
		r.roll = atan2(a.r12, a.r13);
	}
	else{
		r.yaw = atan2(a.r21, a.r11);
		r.roll = atan2(a.r32, a.r33);
	}
	return r;   //Euler angles in order yaw, pitch, roll
}

void build_matrice()
{
	t_vertex 	d;
	t_vertex	c;
	t_rotate	s;
	t_matrice a = (t_matrice){};

	a.r11 = c.y * c.z;
	a.r12 = s.x * s.y * c.z - c.x * s.z;
	a.r13 = s.x * s.z + c.x * s.y * c.z;

	a.r21 = c.y * s.z;
	a.r22 = c.x * c.z + s.x * s.y* s.z;
	a.r23 = c.x * s.y * s.z - s.x * c.z;

	a.r31 = -s.y;
	a.r32 = s.x * c.y;
	a.r33 = c.x * c.y;
}