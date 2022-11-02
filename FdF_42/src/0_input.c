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

    fdf.map = vector_init(sizeof(t_vector *));
    while (1)
    {
        fdf.row = vector_init(sizeof(t_data));
        line = get_next_line(fd);
        if (!line)
            break ;
        split = ft_split(line, ' ');
        while (*split)
        {
			fdf.data.pixel = ft_atoi(*split++);
            if (ft_strchr(*split, 'x'))
                fdf.data.z = hexa_to_deci(ft_strchr(*split, 'x') + 1);
            else
				fdf.data.z = WHITE;
            vector_append(fdf.row, &fdf.data);
        }
        vector_append(fdf.map, &fdf.row);
        free(line);
    }
    close(fd);
    return (m);
}

