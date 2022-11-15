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

# define GREEN 0x39BD00FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define DEFAULT 0x00000000
# define W_HEIGHT 1500
# define W_WIDTH 1800
# define HEIGHT 1500
# define WIDTH 1800
# define TILE_SIZE 50

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/


typedef struct s_vertex
{
	int				x;
	int				y;
	int				z;
}					t_vertex;

typedef struct s_vertices
{
	uint16_t		x;
	uint16_t		y;
	int				color;
}					t_vertices;

typedef struct s_index
{
	size_t				x;
	size_t				y;
	ssize_t 			z;
}					t_index;

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	int				*heightmap;
	float			delta;
	int				min;
	int				max;
}					t_map;

typedef struct s_fdf
{
	t_vertices		size;
	t_map			map;
	float			zoom;
	int				x_off;
	int				y_off;
	int 			tile_size;
	mlx_key_data_t	press;
	t_vector		*grid;
	mlx_image_t		*img;
	mlx_t			*mlx;
	uint32_t		rgb;
}					t_fdf;

void				hook(t_fdf *fdf);
void				project_0(t_fdf *fdf, t_vector *map, t_vertex *_0, t_index i);
void				project_1(t_fdf *fdf, t_vector *map, t_vertex _0, t_index i);
void				projection_right(t_fdf *fdf, t_vertex _0, t_index i);
void				projection_down(t_fdf *fdf, t_vertex _0, t_index i);
void				calibration(t_fdf *fdf);
void				error(void);
void 				scrollhook(double xdelta, double ydelta, t_fdf *fdf);
void				control_hook(mlx_key_data_t press, t_fdf *fdf);
t_vector			*open_read_file(t_fdf *fdf, int fd);
void				exit_message(char *s, int code);
void				projection(t_vector *map, t_fdf *fdf);
void				line(mlx_image_t *image, int x0, int y0, int x1, int y1,
						uint32_t color);
#endif