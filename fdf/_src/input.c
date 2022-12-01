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

#include "../_inc/fdf.h"

t_vector	*open_read_file(int fd, t_fdf *fdf)
{
	static char	**split;
	char		*line;
	char		**tmp;
	int			data;

	fdf->map = vector_init(sizeof(t_vector *));
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
			data = ft_atoi(*tmp++);
			vector_append(fdf->row, &data);
		}
		free(line);
		ft_free_2d_array(split);
		vector_append(fdf->map, &fdf->row);
	}
	close(fd);
	return (fdf->map);
}
