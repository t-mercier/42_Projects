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

#include "../include/fdf.h"

t_vector	*open_read_file(int fd)
{
	static char	**split;
	char		*line;
	t_vector	*map;
	t_vector	*row;
	int			data;
	int			width;

	width = 0;
	map = vector_init(sizeof(t_vector *));
	while (1)
	{
		row = vector_init(sizeof(int));
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		while (*split)
		{
			data = ft_atoi(*split++);
			vector_append(row, &data);
		}
		vector_append(map, &row);
		// if (row->len > width)
		// fdf->width = row->len;
		// fdf->height = map->len;
	}
	free(line);
	close(fd);
	return (map);
}
