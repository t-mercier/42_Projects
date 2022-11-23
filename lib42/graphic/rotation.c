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
#define DEG2RAD (M_PI / 180)


t_rotate rotate_point(t_matrice a, t_vertex p_in)     //Input coords in order (x,y,z)
{
	t_rotate p_out;

	p_out.x = a.r11 * p_in.x + a.r12 * p_in.y + a.r13 * p_in.z;
	p_out.y = a.r21 * p_in.x + a.r22 * p_in.y + a.r23 * p_in.z;
	p_out.z = a.r31 * p_in.x + a.r32 * p_in.y + a.r33 * p_in.z;
	return p_out; //Output coords in order (x,y,z)
}


void init_cos_sin(t_fdf *fdf, t_rotate *c, t_rotate *s)
{
	c->x = (float) cos(fdf->r.roll * DEG2RAD);
	s->x = (float) sin(fdf->r.roll * DEG2RAD);
	c->y = (float) cos(fdf->r.pitch * DEG2RAD);
	s->y = (float) sin(fdf->r.pitch * DEG2RAD);
	c->z = (float) cos(fdf->r.yaw * DEG2RAD);
	s->z = (float) sin(fdf->r.yaw * DEG2RAD);

}

