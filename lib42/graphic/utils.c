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

#include "../_inc/graphic.h"
#define DEG2RAD (M_PI / 180)


double	deg_to_rad(int degree)
{
	if (degree < 0)
		degree = 360;
	else if (degree > 360)
		degree = 0;
	return (degree * M_PI / 180);
}

t_vertex rotate_point(t_matrice a, t_vertex p_in, void *param)
{
	t_vertex p_out;

	p_out.x = a.r11 * p_in.x + a.r12 * p_in.y + a.r13 * p_in.z;
	p_out.y = a.r21 * p_in.x + a.r22 * p_in.y + a.r23 * p_in.z;
	p_out.z = a.r31 * p_in.x + a.r32 * p_in.y + a.r33 * p_in.z;
	return p_out; //Output coords in order (x,y,z)
}
//
//void rotation_()
//{
//	d.x = c.y * (s.z * t.y + c.z * t.x) - s.y * t.z;
//	d.y = s.x * (c.y * t.z + s.y * (s.z * t.y + c.z * t.x)) + c.x * (c.z * t.y - s.z * t.x);
//	d.z = c.x * (c.y * t.z + s.y * (s.z * t.y + c.z * t.x)) - s.x * (c.z * t.y - s.z * t.x);
//}
//

void init_cos_sin(t_rotate *r, t_rotate *c, t_rotate *s, void *param)
{
	c->x = (float) cos(r->roll * DEG2RAD);
	s->x = (float) sin(r->roll * DEG2RAD);
	c->y = (float) cos(r->pitch * DEG2RAD);
	s->y = (float) sin(r->pitch * DEG2RAD);
	c->z = (float) cos(r->yaw * DEG2RAD);
	s->z = (float) sin(r->yaw * DEG2RAD);
}


void rotate_x(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = deg_to_rad(fdf->r.yaw);
	p->x = t.x;
	p->y = t.y * cos(angle) + t.z * -sin(angle);
	p->z = t.y * sin(angle) + t.z * cos(angle);
}

void rotate_y(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = deg_to_rad(fdf->r.pitch);
	p->x = t.x * cos(angle) + t.z * sin(angle);
	p->y = t.y;
	p->z = t.x * -sin(angle) + t.z * cos(angle);
}

void rotate_z(t_fdf *fdf, t_vertex *p)
{
	t_vertex t;
	double angle;

	t = *p;
	angle = deg_to_rad(fdf->r.roll);
	p->x = t.x * cos(angle) + t.y * -sin(angle);
	p->z = t.x * sin(angle) + t.y * cos(angle);
	p->y = t.z;
}


