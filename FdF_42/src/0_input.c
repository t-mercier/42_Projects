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

t_vector	*open_read_file(int fd)
{
    static char	**split;
    char		*line;
	t_fdf		fdf;

    fdf.map.grid = vector_init(sizeof(t_vector *));
    while (1)
    {
        fdf.map.row = vector_init(sizeof(t_data));
        line = get_next_line(fd);
        if (!line)
            break ;
        split = ft_split(line, ' ');
        while (*split)
        {
			fdf.map.p.data.z = ft_atoi(*split++);
            if (ft_strchr(*split, 'x'))
				fdf.map.p.data.color = hexa_to_deci(ft_strchr(*split, 'x') + 1);
            else
				fdf.map.p.data.color = WHITE;
            vector_append(fdf.map.row, &fdf.map.p.data);
        }
        vector_append(fdf.map.grid, &fdf.map.row);
        free(line);
    }
    close(fd);
    return (fdf.map.grid);
}

