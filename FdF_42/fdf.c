/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   src.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "libs/include/libft.h"


int32_t	main(int ac, char **av)
{
	t_vector	*map;
	t_vector	*row;
	t_fdf		m;
	int			fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		error();
	ft_memset(&m.mlx, 0, sizeof(mlx_t *));
	ft_memset(&map, 0, sizeof(struct s_vector *));
	ft_memset(&row, 0, sizeof(struct s_vector *));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("ERROR [ Empty map ]\n", 1);
	map = open_read_file(fd);
	m.mlx = mlx_init(2000, 1000, "FDF", true);
	if (!m.mlx)
		exit(EXIT_FAILURE);
	m.img = mlx_new_image(m.mlx, 2000, 1000);
	mlx_image_to_window(m.mlx, m.img,  700, 100);
	projection(map, &m);
	mlx_key_hook(m.mlx, &ft_key_hook, NULL);
	mlx_loop(m.mlx);
	mlx_terminate(m.mlx);
	return (EXIT_SUCCESS);
}

//	while (i.y0 < map->len)
//	{
//		row = ((t_vector **) map->data)[i.y0];
//		fprintf(stderr, "row y%d \n", i.y0);
//		while (i.x0 < row->len)
//		{
//			int zx = ((int *) row->data)[i.x0];
//			fprintf(stderr, "z[y%d][x%d] %d ", i.y0, i.x0, zx);
//			i.x0++;
//		}
//		fprintf(stderr, "\n");
//		i.y0++;
//	}

//	for (int j = 0; j < map->len; j++)
//	{
//		t_vector *row2 = ((t_vector **) map->data)[j];
//		for (int i = 0; i < row2->len; i++)
//		{
//			int zx = ((int *) row2->data)[i];
//			fprintf(stderr, "%d ", zx);
//		}
//		fprintf(stderr, "\n");
//	}
//	ft_memset(&p, 0, sizeof(t_map));