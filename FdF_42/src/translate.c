/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:37:19 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/02 15:37:19 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void	rotate_x(t_pixel *p, double angle)
{
	double a = rad(angle);
	p->r.x.x = p->x;
	p->r.x.y = cos(a) * p->y - sin(a) * p->z;
	p->r.x.z = sin(a) * p->y + cos(a) * p->z;
}

void	rotate_y(t_pixel *p, double angle)
{
	double a = rad(angle);
	p->r.y.x = cos(a) * p->x - sin(a) * p->z;
	p->r.y.y = p->y;
	p->r.y.z = -sin(a) * p->x + cos(a) * p->z;
}

void	rotate_z(t_pixel *p, double angle)
{
	double a = rad(angle);
	p->r.z.z = cos(a) * p->x - sin(a) * p->y;
	p->r.z.x = sin(a) * p->x + cos(a) * p->y;
	p->r.z.y = p->z;
}

void	rotate(t_fdf *fdf, t_pixel p)
{
	rotate_x(&p, fdf->set.angle);
	rotate_y(&p, fdf->set.angle);
	rotate_z(&p, fdf->set.angle);
}

// https://en.wikipedia.org/wiki/Rotation_matrix