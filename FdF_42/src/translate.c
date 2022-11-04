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

#include "fdf.h"


//
//static void	rotate_x(t_xyz *p)
//{
//	p->x = p->i.x;
//	p->y = cos(rad(p->angle)) * p->i.y + sin(rad(p->angle)) * p->i.z;
//	p->z = -sin(rad(p->angle)) * p->i.y + cos(rad(p->angle)) * p->i.z;
//}
//
//static void	rotate_y(t_xyz *p)
//{
//	p->x = cos(rad(p->angle)) * p->i.x + sin(rad(p->angle)) * p->i.z;
//	p->y = p->i.y;
//	p->z = -sin(rad(p->angle)) * p->i.x + cos(rad(p->angle)) * p->i.z;
//}
//
//static void	rotate_z(t_xyz *p)
//{
//	p->x = cos(rad(p->angle)) * p->i.x - sin(rad(p->angle)) * p->i.y;
//	p->y = sin(rad(p->angle)) * p->i.x + cos(rad(p->angle)) * p->i.y;
//	p->z = p->i.z;
//}
//
//void	rotate(t_xyz *p)
//{
//	rotate_x(p);
//	rotate_y(p);
//	rotate_z(p);
//}

// https://en.wikipedia.org/wiki/Rotation_matrix


//void	convert(t_pixel p, t_draw *d, t_set *a, int z)
//{

//	float cz = cos(rad(a->roll));
//	float cy = cos(rad(a->pitch));
//	float cx = cos(rad(a->yaw));
//	float sz = sin(rad(a->roll));
//	float sy = sin(rad(a->pitch));
//	float sx = sin(rad(a->yaw));
//	float dx = cy * (sz * p.y + cz * p.x) - sy * z;
//	float dy = sx * (cy * z + sy * (sz * p.y + cz * p.x)) + cx * (cz * p.y - sz * p.x);
//	float dz = cx * (cy * z + sy * (sz * p.y + cz * p.x)) - sx * (cz * p.y - sz * p.x);
//	o->x = dx * cos(α) + dy * cos(α + 120) + dz * cos(α - 120);
//	o->y = dx * sin(α) + dy * sin(α + 120) + o * sin(α - 120);
//	d->x = dx * cos(α) + dy * cos(α + 120) + dz * cos(α - 120);
//	d->y = dx * sin(α) + dy * sin(α + 120) + dz * sin(α - 120);
//}
