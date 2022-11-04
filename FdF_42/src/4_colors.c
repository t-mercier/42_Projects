/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   6_colors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Get the red channel.
int get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
	return (rgba & 0xFF);
}
