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

#include "fdf.h"

int32_t	to_isometric_2d(double x, double y,double z, double *u, double*v)
{
	*u = (x - z) / sqrt(2);
	*v = (x + 2 * y + z) / sqrt(6);
	return 0;
}