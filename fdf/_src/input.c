/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_process_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/25 19:01:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	resize_map(t_fdf *fdf)
{
	int	surface;

	surface = fdf->w * fdf->h;
	if (surface > 10000)
		fdf->t_s = 5.;
	else if (surface > 5000)
		fdf->t_s = 10.;
	else if (surface < 500)
		fdf->t_s = 50.;
	else
		fdf->t_s = 30.;
}

static void	get_size(t_fdf *fdf)
{
	fdf->w = (int)fdf->row->len;
	fdf->h = (int)fdf->grid->len;
	resize_map(fdf);
}

static void	get_max_min(t_fdf *fdf, int z)
{
	if (z > fdf->z_max)
		fdf->z_max = z;
	if (z < fdf->z_min)
		fdf->z_min = z;
}

t_vector	*read_file(int fd, t_fdf *fdf)
{
	static char	**split;
	char		*line;
	char		**tmp;

	fdf->grid = vector_init(sizeof(t_vector *));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		tmp = split;
		fdf->row = vector_init(sizeof(int));
		while (*tmp)
		{
			fdf->data = ft_atoi(*tmp++);
			get_max_min(fdf, fdf->data);
			vector_append(fdf->row, &fdf->data);
		}
		free(line);
		ft_free_2d_array(split);
		vector_append(fdf->grid, &fdf->row);
		get_size(fdf);
	}
	return (fdf->grid);
}
