/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graphic.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/12/01 22:18:02 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_rgba
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}				t_rgba;

typedef struct s_offset
{
	double		x;
	double		y;
}				t_offset;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			c;
}				t_point;

typedef struct s_vertex
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_vertex;

typedef struct s_rotate
{
	double		x;
	double		y;
	double		z;
	double		cx;
	double		cy;
	double		cz;
	double		sx;
	double		sy;
	double		sz;
	double		roll;
	double		pitch;
	double		yaw;
}				t_rotate;

typedef struct s_bresenham
{
	t_point		d;
	t_point		s;
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
}				t_matrix;

/*
**			arbitrary_rotation.c
** ------------------------------------------ */
t_vertex		rotate_x(t_vertex p, t_rotate r, void *param);
t_vertex		rotate_y(t_vertex p, t_rotate r, void *param);
t_vertex		rotate_z(t_vertex p, t_rotate r, void *param);

/*
**			bresenham.c
** ------------------------------------------ */
void			drawline(mlx_image_t *img, t_point _0, t_point _1, uint32_t c);

/*
**			colors.c
** ------------------------------------------ */
t_rgba			hex_rgba(int c);
int				rgba_hex(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b);

/*
**			matrices.c
** ------------------------------------------ */
t_matrix		build_matrix(t_rotate r);
t_rotate		matrix_to_angle(t_matrix a);
t_vertex		matrix_to_px(t_matrix a, t_vertex p_in, void *param);

/*
**			perspectives.c
** ------------------------------------------ */
t_vertex		isometry_projection(t_offset offset, t_vertex *p, double angle);

/*
**			utils.c
** ------------------------------------------ */
void			init_cos_sin(t_rotate *r, void *param);
double			deg_to_rad(double degree);
void			mlx_error_exit(void) __attribute__((unused));
double			get_percent(int n1, int n2, int current);

#endif
