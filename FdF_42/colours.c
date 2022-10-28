/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colours.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:29:21 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/05 12:29:21 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Get the red channel.
int get_r(int rgba)
{
	// Move 3 bytes to the right and mask out the first byte.
	return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
	// Move 2 bytes to the right and mask out the first byte.
	return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
	// Move 1 byte to the right and mask out the first byte.
	return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
	// Move 0 bytes to the right and mask out the first byte.
	return (rgba & 0xFF);
}
