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

# include "../../lib42/lib42.h"

# define DEG2RAD (360.0 * M_PI / 180)

# define EXIT_FAILURE 1
# define HEIGHT 1500
# define WIDTH 1800
# define BPP sizeof(int32_t)
# define R	0x00FF0000
# define B	0x000000FF
# define G	0x0000FF00
# define A	0x000000FF

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
	double			r;
	double			g;
	double			b;
	double			a;
	uint32_t		rgb;
} t_rgb;

typedef struct s_vertices
{
	uint16_t		x;
	uint16_t		y;
}					t_vertices;

typedef struct s_data
{
	int 			n;
	int 			c;
} t_data;

typedef struct s_vertex
{
	int				x;
	int				y;
	int				z;
	t_data			data;
	int				color;
}					t_vertex;

typedef struct s_fdf
{
	float			zoom;
	int 			x_offset;
	int 			y_offset;
	int 			tile_size;
	mlx_t			*mlx;
	t_vector		*map;
	t_vertices		size;
	mlx_image_t		*img;
}					t_fdf;

void				hook(t_fdf *fdf);
void				project_0(t_fdf *fdf, t_vector *map, t_vertex *_0, t_vertex p);
void				project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_vertex p);
void				projection_right(t_fdf *fdf, t_vertex _0, t_vertex p);
void				projection_down(t_fdf *fdf, t_vertex _0, t_vertex p);
void				calibration(t_fdf *fdf);
void				error(void);
void 				scrollhook(double xdelta, double ydelta, t_fdf *fdf);
void				control_hook(mlx_key_data_t press, t_fdf *fdf);
t_vector			*open_read_file(t_fdf *fdf, int fd);
void				exit_message(char *s, int code);
void				projection(t_vector *map, t_fdf *fdf);
void				drawline(mlx_image_t *image, t_vertex _0, t_vertex _1, uint32_t color);

int		get_color(t_vertex *p1, t_vertex *p2, int mod);

#endif