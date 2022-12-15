/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 12:52:36 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/24 12:52:36 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/graphic.h"

t_rgba	hex_rgba(int c)
{
	t_rgba	rgba;

	rgba.a = 0xFF & (c >> 24);
	rgba.r = 0xFF & (c >> 16);
	rgba.g = 0xFF & (c >> 8);
	rgba.b = 0xFF & (c);
	return (rgba);
}

int	rgba_hex(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){r, g, b, a});
}
