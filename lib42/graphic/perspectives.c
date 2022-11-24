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

#include "../include/fdf.h"

void isometry(t_fdf *fdf)
{

	_1.x = (t.x - t.y) * cos(0.523599) + fdf->x_offset;
	_1.y = -t.z + (t.x + t.y) * sin(0.523599) + fdf->y_offset;


}

//destination.x = source.x + cos(angle) * source.z
//destination.y = source.y + sin(angle) * source.z

void	parallel()

