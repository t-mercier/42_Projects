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

# include "../_lib42/_inc/lib42.h"
# define WHITE 0xFFFFFFFF
# define WIDTH 3000
# define HEIGHT 2500

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/

typedef struct s_usage
{
	char			*s[14];
	mlx_image_t		*n[12];
}					t_usage;

typedef struct s_index
{
	int				x;
	int				y;
	int				z;
}					t_index;

typedef struct s_fdf
{
	size_t			width;
	size_t			height;
	int				scheme;
	int				color;
	double			depth;
	double			tile_size;
	double			angle;
	double			n;
	bool			_invert;
	bool			_switch;
	bool			_color;
	bool			_view;
	bool			_iso;
	t_point			p0;
	t_point			p1;
	t_rgb			rgb;
	t_offset		offset;
	mlx_t			*mlx;
	t_rotate		r;
	t_vector		*map;
	t_vector		*row;
	t_matrix		m;
	mlx_image_t		*img;
	t_usage			usage;
	t_vertex		c;
	mlx_image_t		*warning;
	mlx_image_t		*baseline;

}					t_fdf;

/*
**			colors_1.c
** ------------------------------------------ */
uint32_t			get_color(t_fdf *fdf, int z);
uint32_t			fire(int z);
uint32_t			grey(int z);
uint32_t			forest(int z);

/*
**			colors_2.c
** ------------------------------------------ */
uint32_t			pastel(int z);
uint32_t			midnight(int z);
uint32_t			grapes(int z);
uint32_t			dark(int z);
uint32_t			color(t_fdf *fdf, int z0, int z1);

/*
**			input.c
** ------------------------------------------ */
t_vector			*open_read_file(int fd, t_fdf *fdf);

/*
**			key_hook.c
** ------------------------------------------ */
void				k_hook(mlx_key_data_t key, void *tmp);

/*
**			lines.c
** ------------------------------------------ */
void				project(t_fdf *fdf);

/*
**			loop_hook.c
** ------------------------------------------ */
void				l_hook(t_fdf *fdf);

/*
**			rotation.c
** ------------------------------------------ */
void				rotations(t_fdf *fdf);

/*
**			usage.c
** ------------------------------------------ */
void				init_usage(t_fdf *fdf);

/*
**			utils.c
** ------------------------------------------ */
void				resize_map(t_fdf *fdf);
void				calibrate(t_fdf *fdf);
t_point				cast_points(t_vertex p);
void				clear(t_fdf *fdf);
int					check_error(int ac, char **av);

#endif