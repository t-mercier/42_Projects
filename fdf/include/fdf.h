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

# define DEG2RAD (360.0 * M_PI / 180)
# define EXIT_FAILURE 1
# define HEIGHT 1500
# define WIDTH 1800
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

typedef struct s_bresenham
{
	t_vertex	d;
	t_vertex	s;
	int			e;
	int			e2;

}				t_bresenham;

typedef struct s_fdf
{
	float		zoom;
	int			x_offset;
	int			y_offset;
	int			tile_size;
	mlx_t		*mlx;
	t_vector	*map;
	mlx_image_t	*img;
}				t_fdf;

void			hook(t_fdf *fdf);
void			calibration(t_fdf *fdf);
void			scrollhook(double xdelta, double ydelta, t_fdf *fdf);
void			control_hook(mlx_key_data_t press, t_fdf *fdf);
t_vector		*open_read_file(int fd);
void			exit_message(char *s, int code);
void			projection(t_vector *map, t_fdf *fdf);
void			drawline(mlx_image_t *img, t_vertex _0, t_vertex _1,
					uint32_t color);
int				get_color(t_vertex *p1, t_vertex *p2, int mod);

#endif