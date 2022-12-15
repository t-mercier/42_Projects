/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perspectives.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 14:05:26 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/24 14:05:26 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/graphic.h"

t_vertex	isometry_projection(t_offset offset, t_vertex *p, double angle)
{
	t_vertex	t;

	t = *p;
	p->x = ((double)(t.x - t.y)) * cos(deg_to_rad(angle));
	p->y = -(double)t.z + ((double)(t.x + t.y)) * sin(deg_to_rad(angle));
	p->x += offset.x;
	p->y += offset.y;
	return (*p);
}
