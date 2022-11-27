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
	bool		display_usage;
	bool		isometry;
	bool		render;
	int			tile_size;
	double		depth;
	double 		angle;
	t_offset 	offset;
	mlx_t		*mlx;
	t_rotate	r;
	t_vector	*map;
	uint32_t	rgb;
	t_matrice	m;
	mlx_image_t	*img;
	mlx_image_t	*usage[12];
	mlx_image_t	*baseline;
}				t_fdf;

/*
**			hook_setup.c
** ------------------------------------------ */
void	hook(t_fdf *fdf, mlx_key_data_t keydata);

/*
**			process_input.c
** ------------------------------------------ */
t_vector		*open_read_file(int fd);

/*
**			project_lines.c
** ------------------------------------------ */
void			project(t_fdf *fdf, t_vector *map);

/*
**			utils.c
** ------------------------------------------ */
void			usage(void);
void			calibration(t_fdf *fdf);
int				color(t_vertex _0, t_vertex _1);
bool	rotate(t_fdf *fdf);
void	display_usage(t_fdf *fdf);
void disable_usage(t_fdf *fdf);
void unable_usage(t_fdf *fdf);
void	display_baseline(t_fdf *fdf);

#endif