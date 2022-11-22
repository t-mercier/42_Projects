/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   src.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/02 16:12:52 by tmercier      #+#    #+#                 */
/*   Updated: 2022/07/02 16:12:52 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../lib42/include/lib42.h"

# define EXIT_FAILURE 1
# define HEIGHT 900
# define WIDTH 1600
# define GREEN 0x39BD00FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/

typedef struct s_rgb
{
	double		r;
	double		g;
	double		b;
	double		a;
	uint32_t	rgb;
}				t_rgb;

typedef struct s_data
{
	int			z;
	int			c;
}				t_data;

typedef struct s_vertex
{
	int 		x;
 	int			y;
	int			z;
	int			color;
	t_data		data;
}				t_vertex;

typedef struct s_matrice {
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

typedef struct	s_rotate
{
	float 		x;
	float		y;
	float		z;
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

typedef struct s_fdf
{
	int			x_offset;
	int			y_offset;
	int			tile_size;
	double	angle;
	mlx_t		*mlx;
	t_rotate	r;
	t_vector	*map;
	mlx_image_t	*img;
}				t_fdf;

void			hook(t_fdf *fdf);
void			usage(void);
void			calibration(t_fdf *fdf);
void			scrollhook(double xdelta, double ydelta, t_fdf *fdf);
void			control_hook(mlx_key_data_t press, t_fdf *fdf);
t_vector		*open_read_file(int fd);
void			exit_message(char *s, int code);
void			project(t_vector *map, t_fdf *fdf);
void			drawline(mlx_image_t *img, t_vertex _0, t_vertex _1,
					uint32_t color);
int				get_color(t_vertex _0, t_vertex _1);
int				_trgb(unsigned char t, unsigned char r, unsigned char g, \
					unsigned char b);
int			color(t_vertex _0, t_vertex _1);
double	degree_to_radians(int degree);
#endif