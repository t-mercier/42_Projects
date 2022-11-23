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

# include "../../lib42/_inc/lib42.h"

# define EXIT_FAILURE 1

# define HEIGHT 1024
# define WIDTH 1280

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
}				t_rgb;

typedef struct s_fdf
{
	int			x_offset;
	int			y_offset;
	int			tile_size;
	double		angle;
	int 		width;
	int 		height;
	int 		zoom;
	t_vertex	_0;
	t_vertex	_1;
	t_vertex	p;
	uint32_t	rgb;
	mlx_t		*mlx;
	t_rotate	r;
	t_vector	*map;
	mlx_image_t	*img;
	t_matrice	m;
}				t_fdf;

void	project(t_fdf *fdf, t_vector *map);
void			hook(t_fdf *fdf);
void			usage(void);
void			calibration(t_fdf *fdf);
t_vector		*open_read_file(int fd);
void			exit_message(char *s, int code);
int				get_color(t_vertex _0, t_vertex _1);
int				_trgb(unsigned char t, unsigned char r, unsigned char g, \
					unsigned char b);
int			color(t_vertex _0, t_vertex _1);
void render(t_fdf *fdf, int fd);

#endif