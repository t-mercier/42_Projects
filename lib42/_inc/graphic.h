/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_linkedlist.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:57:11 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"


typedef struct s_vertex
{
	int 		x;
	int			y;
	int			z;

}				t_vertex;

typedef struct	s_rotate
{
	float 		x;
	float 		y;
	float 		z;
	float 		cx;
	float		cy;
	float		cz;
	float 		sx;
	float		sy;
	float		sz;
	double		roll;
	double		pitch;
	double		yaw;
}				t_rotate;

typedef struct s_bresenham
{
	t_vertex	d;
	t_vertex	s;
	int			e;
	int			e2;

}				t_bresenham;

typedef struct s_matrice
{
	double		r11;
	double		r12;
	double		r13;
	double		r21;
	double		r22;
	double		r23;
	double		r31;
	double		r32;
	double		r33;
}t_matrice;

// utils
void init_cos_sin(t_rotate *r, void *param);
double	deg_to_rad(int degree);

// rotate
t_vertex rotate_x(t_vertex p, t_rotate r, void *param);
void rotate_y(t_vertex *p, t_rotate r, void *param);
void rotate_z(t_vertex *p, t_rotate r, void *param);

// matrice
t_matrice build_matrice(t_rotate r);
t_rotate matrix_to_angle(t_matrice a);
t_vertex matrice_to_px(t_matrice a, t_vertex p_in, void *param);

// draw
void	drawline(mlx_image_t *img, t_vertex _0, t_vertex _1, uint32_t color);



#endif