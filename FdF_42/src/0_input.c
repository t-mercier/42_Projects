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


static int _min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
static int hexa_to_deci(char *hex)
{
	int y = 0;
	int n = 0;
	int x;
	size_t len;

	len = ft_strlen(hex) - 1;
	while (len--)
	{
		if (*(hex + len) >= '0' && *(hex + len) <= '9')
			x = *(hex + len) - '0';
		else
			x = *(hex + len) - 'A' + 10;
		n = (int) (n + x * pow(16, y));
	}
	return n;
}

t_vector *open_read_file(int fd)
{
	static char	**split;
	char		*line;
	t_data 		z;
	t_vector	*map;
	t_vector	*row;
	t_vector	*color;
	map = vector_init(sizeof(t_vector *));
	while (1)
	{
		row = vector_init(sizeof(t_data));
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		while (*split)
		{
			z.p = ft_atoi(*split++);
			if (ft_strchr(*split, 'x'))
				z.c = hexa_to_deci(ft_strchr(*split, 'x') + 1);
			else
				z.c = WHITE;
			vector_append(row, &z);
		}
		vector_append(map, &row);
		free(line);
	}
	close(fd);
	return (map);
}


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

