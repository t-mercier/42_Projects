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

t_vector	*open_read_file(t_fdf *fdf, int fd)
{
    static char	**split;
    char		*line;
	t_vector	*row;
	t_data		data;


	fdf->grid = vector_init(sizeof(t_vector *));
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
		row = vector_init(sizeof(t_data));
        split = ft_split(line, ' ');
        while (*split)
        {
			data.z = ft_atoi(*split++);
            if (ft_strchr(*split, 'x'))
				data.color = ft_hextodeci(ft_strchr(*split, 'x') + 1);
            else
				data.color = WHITE;
            vector_append(row, &data);
        }
        vector_append(fdf->grid, &row);
        free(line);
    }
	fdf->map.width = row->len;
	fdf->map.height = fdf->grid->len;
    close(fd);
    return (fdf->grid);
}

