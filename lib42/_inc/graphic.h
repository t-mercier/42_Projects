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

typedef struct 	s_offset
{
	int			x;
	int			y;
}				t_offset;

typedef struct s_vertex
{
	int 		x;
	int			y;
	int			z;
}				t_vertex;

typedef struct	s_rotate
{
	double 		x;
	double 		y;
	double 		z;
	double 		cx;
	double		cy;
	double		cz;
	double 		sx;
	double		sy;
	double		sz;
	double		roll;
	double		pitch;
	double		yaw;
}				t_rotate;

typedef struct 	s_bresenham
{
	t_vertex	d;
	t_vertex	s;
	int			e;
	int			e2;

}				t_bresenham;

typedef struct 	s_matrice
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
}				t_matrice;

/*
**			arbitrary_rotation.c
** ------------------------------------------ */
t_vertex	rotate_x(t_vertex p, t_rotate r, void *param);
void		rotate_y(t_vertex *p, t_rotate r, void *param);
void		rotate_z(t_vertex *p, t_rotate r, void *param);

/*
**			bresenham.c
** ------------------------------------------ */
void		drawline(mlx_image_t *img, t_vertex _0, t_vertex _1, uint32_t color);

/*
**			colors.c
** ------------------------------------------ */
uint32_t	_color(int color);

/*
**			matrices.c
** ------------------------------------------ */
t_matrice	build_matrice(t_rotate r);
t_rotate	matrix_to_angle(t_matrice a);
t_vertex	matrice_to_px(t_matrice a, t_vertex p_in, void *param);

/*
**			perspectives.c
** ------------------------------------------ */
t_vertex	isometry_projection(t_offset offset, t_vertex *p, double angle);
t_vertex	parallel_projection(t_offset offset, t_vertex *p, double angle);

/*
**			utils.c
** ------------------------------------------ */
void		init_cos_sin(t_rotate *r, void *param);
double		deg_to_rad(int degree);
void		mlx_error_exit(void)__attribute__((unused));

#endif