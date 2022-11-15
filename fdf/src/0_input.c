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

#include "../include/fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
t_vector *open_read_file(t_fdf *fdf, int fd)
{
	static char	**split;
	char		*line;
	t_vector	*map;
	t_vector	*row;
	t_data 		data;
	char		*tmp;

	map = vector_init(sizeof(t_vector *));
	while (1)
	{
		row = vector_init(sizeof(t_data));
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		free(line);
		while (*split)
		{
			if ((tmp = ft_strchr(*split, ',')))
			{
				tmp += 3;
				data.c = ft_hextodeci(tmp);
				data.c = create_trgb(data.n*3,data.n/2,0,0xff);




				data.c = (ft_hextodeci(tmp) << sizeof(0xff) ) & 0xFF;
			}
			data.n = ft_atoi(*split++);
			vector_append(row, &data);
		}
		vector_append(map, &row);
		fdf->size.x = row->len;
	}
	fdf->size.y = map->len;
	close(fd);
	return (map);
}

