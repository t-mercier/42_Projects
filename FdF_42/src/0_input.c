/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_input.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:38:08 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 21:07:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector *open_read_file(int fd)
{
	static char	**split;
	char		*line;
	t_vector	*map;
	t_vector	*row;
	int 		n;

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
			n = ft_atoi(*split++);
			vector_append(row, &n);
		}
		vector_append(map, &row);
		free (line);
	}
	return (map);
}

