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
//	t_vector	*map;
//	t_vector	*row;
	t_fdf		fdf;
	int			fd;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(av[1]) - 4 <= 0)
		error();
	ft_memset(&fdf, 0, sizeof(struct s_fdf *));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_message("ERROR [ Empty grid ]\n", 1);
	fdf.map = open_read_file(&fdf, fd);
	fdf.mlx = mlx_init(2000, 1000, "FDF", true);
	if (!fdf.mlx)
		exit(EXIT_FAILURE);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
	calibration(&fdf);
	draw_map(&fdf);
	mlx_key_hook(fdf.mlx, (mlx_keyfunc)&control_hook, &fdf);
	mlx_loop_hook(fdf.mlx, (void (*)(void *))&control_loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}

//	while (i.y0 < grid->len)
//	{
//		row = ((t_vector **) grid->item)[i.y0];
//		fprintf(stderr, "row y%o \n", i.y0);
//		while (i.x0 < row->len)
//		{
//			int zx = ((int *) row->item)[i.x0];
//			fprintf(stderr, "item[y%o][x%o] %o ", i.y0, i.x0, zx);
//			i.x0++;
//		}
//		fprintf(stderr, "\n");
//		i.y0++;
//	}

//	for (int j = 0; j < grid->len; j++)
//	{
//		t_vector *row2 = ((t_vector **) grid->item)[j];
//		for (int i = 0; i < row2->len; i++)
//		{
//			int zx = ((int *) row2->item)[i];
//			fprintf(stderr, "%o ", zx);
//		}
//		fprintf(stderr, "\n");
//	}
//	ft_memset(&p, 0, sizeof(t_map));