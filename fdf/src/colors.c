/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 21:39:43 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/16 21:39:43 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int	knife_fade(int h)
{
	if (h > 100)
		return (0xFFDF8D);
	if (h > 75)
		return (0xFFDE7A);
	if (h > 50)
		return (0xFFC568);
	if (h > 25)
		return (0xFD996B);
	if (h > 15)
		return (0xF7856C);
	if (h > 10)
		return (0xF06E6C);
	if (h > 5)
		return (0xD9576B);
	if (h > 0)
		return (0xA44369);
	if (h > -10)
		return (0x833F68);
	if (h > -20)
		return (0x833F68);
	if (h > -50)
		return (0x5E3C65);
	return (0x3F3A63);
}

unsigned int	minecraft_fade(int h)
{
	if (h > 70)
		return (0xE9EAF0);
	if (h > 62)
		return (0xC4C1BD);
	if (h > 50)
		return (0x4C591A);
	if (h > 10)
		return (0x4C591A);
	if (h > 1)
		return (0x4D5E36);
	if (h > 0)
		return (0xD8D19C);
	if (h > -5)
		return (0x444CC6);
	if (h > -10)
		return (0x2A2EAE);
	if (h > -30)
		return (0x3D497C);
	return (0x05093d);
}

unsigned int	white_on_black(int h)
{
	(void)h;
	return (0xFFFFFF);
}