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

# include "../libs/include/MLX42/MLX42/MLX42.h"
# include "../libs/include/libft.h"
# include "../libs/include/single_linkedlist.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define EXIT_FAILURE 1
# define WHITE 0xFFFFFFFF

// Map settings
# define HEIGHT			1000
# define WIDTH			1500
# define TILE_SIZE		50

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/

typedef struct s_data
{
	size_t				color;
	int					z;
} t_data;

typedef struct s_xyz
{
	int					x;
	int					y;
	int					z;
	int 				color;
} t_xyz;

typedef struct s_axis
{
	int 		x;
	int 		y;
	int 		z;
}t_axis;

typedef struct s_set
{

//	double				alpha;
//	double				beta;
//	double				gamma;
	int 				zoom;
	double				angle;
	float				z_divisor;
	int				x_offset;
	int				y_offset;
}						t_set;

typedef struct s_rotate
{
	t_axis					x;
	t_axis					y;
	t_axis					z;
}t_rotate;

typedef struct s_pixel
{
	int 		x;
	int 		y;
	int 		z;
	double 				angle;
	t_data				data;
	t_xyz 				_0;
	t_xyz 				_1;
	t_xyz 				_2;
	t_xyz 				t; // translated
	t_xyz 				o; // origin
	t_xyz	 			i; // isometry
}						t_pixel;

typedef struct s_map
{
	int 				zoom;
	double				angle;
	float				z_divisor;
	int				x_offset;
	int				y_offset;
	size_t				height;
	size_t				width;
	t_pixel 		p;
}t_map;

typedef struct s_fdf
{

	t_xyz 				p;
	t_xyz 				d;
	t_xyz 				u;
	t_xyz 				v;
	t_map	 			map;
	t_set				set;
	mlx_key_data_t		press;
	t_vector			*grid;
	mlx_image_t			*img;
	mlx_t				*mlx;
}						t_fdf;

static inline double	rad(double degree_to_radian)
{
	if (degree_to_radian < 0)
		degree_to_radian = 360;
	else if (degree_to_radian > 360)
		degree_to_radian = 0;
	return (degree_to_radian * (M_PI / 180));
}

void 	isometry(t_xyz *p, t_fdf *fdf);
t_vector 	*open_read_file(t_fdf *fdf, int fd);
void	rotate(t_xyz *p);
void	draw_map(t_fdf *fdf);
void	projection(t_xyz *p, t_fdf *fdf);
void 	trace(mlx_image_t *img, t_xyz _0, t_xyz _1, int color);
void	calibration(t_fdf *fdf);
void	scale(t_fdf *fdf);
void	control_hook(t_fdf *fdf);
void	control_loop_hook(t_fdf *fdf);
int	_min(int a, int b);
/* ---------------------------------
**			3_algo.c
*/
void	error(void);
/* ---------------------------------
**			4_utils.c
*/
void	*ft_malloc(void	*ptr, ssize_t esz);
void	exit_message(char *s, int code);

#endif