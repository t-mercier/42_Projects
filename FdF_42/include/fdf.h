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
# define WIDTH 700
# define HEIGHT 700

# ifndef X_OFFSET
#  define X_OFFSET 20
# endif

# ifndef Y_OFFSET
#  define Y_OFFSET 20
# endif

# ifndef TILE_H
#  define TILE_H 50
# endif

# ifndef TILE_W
#  define TILE_W 50
# endif

# ifndef MAX_H
#  define MAX_H 80
# endif

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/

typedef struct s_draw
{
	int					x;
	int					y;
}						t_draw;

typedef struct s_data
{
	int					c;
	int					p;
}						t_data;

typedef struct s_pixel
{
	int					x;
	int					y;
	t_data				z;
}						t_pixel;

typedef struct s_key
{
    float	height;
    float	rot_angle;
    int		palette;
    float	zoom;
    size_t	perspective;
    float	points_resolution;
    int		horiz;
    int		vert;
}t_key;

typedef struct s_view
{
	double				zoom;
	float				z_axis;
	int					x;
	int					y;
}						t_view;

typedef struct s_fdf
{
    t_key               set;
	t_vector			*map;
	mlx_image_t			*img;
	mlx_t				*mlx;
	t_view				view;
}						t_fdf;

static inline double	rad(double degree_to_radian)
{
	degree_to_radian *= (M_PI / 180);
	return (degree_to_radian);
}

/*
**			[ SRC ]
** --------------------------------*/

/* ---------------------------------
**			0_input.c
*/
t_vector	*open_read_file(int fd);

/* ---------------------------------
**			1_parse.c
*/

/* ---------------------------------
**			2_trace.c
*/
//void conversion(int *x, int *y, int z);
void					projection(t_vector *map, t_fdf *m);
void					trace(mlx_image_t *image, t_draw p0, t_draw p1,
							uint32_t color);
void					convert(t_pixel p, t_draw *d, int z);
t_pixel					iso(t_pixel p, t_fdf *g, t_vector *x, t_vector *y);

/* ---------------------------------
**			3_algo.c
*/
void					error(void);
void					ft_key_hook(mlx_key_data_t k, void *param);
/* ---------------------------------
**			4_utils.c
*/
t_vector				*open_read_file(int fd);
void					*check_malloc(void *ptr);
char					*process_map(const char *file);

int						process_file(const char *file);
void					size_map(t_fdf *map, char *line);
void					background(mlx_t *mlx);
//void	drawline(t_init	*map);
void					exit_message(char *s, int code);

//int		parse_map(char *argv[], t_map *map);
//void	make_raster(t_draw *draw, t_map *map, t_br *br, mlx_image_t *g_img);
//void	bresenham(t_br *br, mlx_image_t *g_img, int color);
//void	fdf_keyhook(mlx_key_data_t keydata, void *param);
//void	free_struct(t_map *map);
//void	malloc_map(t_map *map, int x, int y);
//char	**open_read_file(char **av);
//void line(mlx_image_t *img, t_draw *p, uint32_t color);
#endif