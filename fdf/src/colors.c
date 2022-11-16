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

//t_rgb color_converter(int hex)
//{
//	t_rgb c;
//	c.r = ((hex >> 16) & 0xff) / 255.0;  // Extract the RR byte
//	c.g = ((hex >> 8) & 0xff) / 255.0;   // Extract the GG byte
//	c.b = ((hex) & 0xff) / 255.0;        // Extract the BB byte
//
//	return (c);
//}
//
//double get_rgba(t_rgb c)
//{
//	return (c.r << 24 | c.g << 16 | c.b << 8 | c.a);
//}

//int get_rgba()
//{
//	return (R << 24 | G << 16 | B << 8 | A);
//}

//void	init(t_fdf *fdf, char *filename)
//	fdf->map.heightmap = NULL;
//	fdf->width = 1000;
//	fdf->height = 1000;
//	fdf->zoom = fdf->width / 2;
//	fdf->rgb = 0xFF0000;
//}

//int		get_color(t_vertex *p1)
//{
//	int	r;
//	int	g;
//	int	b;
//
//	r = (p1->color & 0xFF0000) >> 16;
//	g = (p1->color & 0x00FF00) >> 8;
//	b = p1->color & 0x0000FF;
//	return ((r << 16) + (g << 8) + b);
//}
