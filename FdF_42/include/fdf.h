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

# include "../libs/include/libft.h"
# include "../libs/include/single_linkedlist.h"
# include "../libs/include/MLX42/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define EXIT_FAILURE 1
# define WIN_HEIGHT 720
# define WIN_WIDTH 1080
# define GREEN 0x39BD00FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define OFFSET 50
# define GRIDSIZE 20

/*
**		[ STRUCTURES ]
** ---------------------------------
**		linked list
*/

typedef struct	s_index {
	int			x0;
	int 		y0;
	int 		x1;
	int 		y1;
} t_index;

typedef struct s_map {
	t_index i;
	int			x0;
	int 		y0;
	int 		x1;
	int 		y1;
	int 		u0;
	int 		u1;
	int 		v0;
	int 		v1;
	int 		dx;
	int 		sx;
	int 		dy;
	int 		sy;
} t_map;

typedef struct	s_fdf {

	mlx_image_t	*img;
	mlx_t 		*mlx;
	int 		x;
	int 		y;
	int 		z;
	uint32_t	color;
} t_fdf;


/*
**			[ SRC ]
** --------------------------------*/

/* ---------------------------------
**			0_input.c
*/

/* ---------------------------------
**			1_parse.c
*/

/* ---------------------------------
**			2_trace.c
*/
void isometric_conversion(int x, int y, int z, int *u, int *v);
/* ---------------------------------
**			3_algo.c
*/
void	error(void);
void	my_keyhook(mlx_key_data_t keydata, void* param);
/* ---------------------------------
**			4_utils.c
*/
t_vector *open_read_file(int fd);
void	*check_malloc(void	*ptr);
char	*process_map(const char *file);

int		process_file(const char *file);
void	size_map(t_fdf *map, char *line);
void	background(mlx_t	*mlx);
//void	drawline(t_init	*map);
void exit_message(char *s, int code);

//int		parse_map(char *argv[], t_map *map);
//void	make_raster(t_draw *draw, t_map *map, t_br *br, mlx_image_t *g_img);
//void	bresenham(t_br *br, mlx_image_t *g_img, int color);
//void	fdf_keyhook(mlx_key_data_t keydata, void *param);
//void	free_struct(t_map *map);
//void	malloc_map(t_map *map, int x, int y);
//char	**open_read_file(char **av);
void line(mlx_image_t *img, t_map *p, uint32_t color);

#endif