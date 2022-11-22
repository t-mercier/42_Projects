/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	usage(void)
{
	char *s;

	s = "usage: ./fdf maps/[map]\n";
	write(1, s, ft_strlen(s));
	exit(0);
}

double	degree_to_radians(int degree)
{
	if (degree < 0)
		degree = 360;
	else if (degree > 360)
		degree = 0;
	return (degree * M_PI / 180);
}