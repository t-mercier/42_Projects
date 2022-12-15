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

# include "../_lib42/inc/lib42.h"
# define WHITE 0xFFFFFFFF

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/

typedef struct s_size
{
	int			w;
	int			h;
	int			s;
}				t_size;

typedef struct s_usage
{
	char		*s[23];
	mlx_image_t	*n[23];
}				t_usage;

typedef struct s_index
{
	int			x;
	int			y;
	int			z;
	int			c;
}				t_index;

typedef struct s_fdf
{
	int			w;
	int			h;
	int			palette;
	int			color;
	int			data;
	int			z_min;
	int			z_max;
	char		*title;
	double		depth;
	double		t_s;
	double		angle;
	double		n;
	bool		_invert;
	bool		_switch;
	bool		_color;
	bool		_blink;
	bool		_view;
	bool		_iso;
	t_rgba		rgba;
	t_size		map;
	t_size		win;
	t_point		p0;
	t_point		p1;
	t_point		c0;
	t_vertex	_0;
	t_rotate	r;
	t_matrix	m;
	t_usage		usage;
	t_offset	offset;
	t_vector	*grid;
	t_vector	*row;
	mlx_image_t	*img;
	mlx_t		*mlx;
	mlx_image_t	*warning;
	mlx_image_t	*baseline;

}				t_fdf;

/*
**			colors_1.c
** ------------------------------------------ */
uint32_t		_blink(t_fdf *fdf);
uint32_t		_random(t_fdf *fdf, int p0, int p1);
uint32_t		get_color(t_fdf *fdf, int z);
uint32_t		fire(t_fdf *fdf, int z);
uint32_t		grey(t_fdf *fdf, int z);

/*
**			colors_2.c
** ------------------------------------------ */
uint32_t		pastel(t_fdf *fdf, int z);
uint32_t		midnight(t_fdf *fdf, int z);
uint32_t		grapes(int z);
uint32_t		dark(int z);
uint32_t		forest(int z);

/*
**			input.c
** ------------------------------------------ */
t_vector		*read_file(int fd, t_fdf *fdf);

/*
**			key_hook.c
** ------------------------------------------ */
void			k_hook(mlx_key_data_t key, void *tmp);

/*
**			lines.c
** ------------------------------------------ */
void			project(t_fdf *fdf);

/*
**			loop_hook.c
** ------------------------------------------ */
void			l_hook(t_fdf *fdf);

/*
**			rotation.c
** ------------------------------------------ */
void			rotations(t_fdf *fdf);

/*
**			usage.c
** ------------------------------------------ */
void			init_usage(t_fdf *fdf);

/*
**			utils.c
** ------------------------------------------ */
void			calibrate(t_fdf *fdf);
t_point			cast_points(t_vertex p);
int				check_error(int ac, char *av);
void			scrollhook(double xdelta, double ydelta, void *param);
bool			in_perimeter(t_fdf *fdf);

#endif