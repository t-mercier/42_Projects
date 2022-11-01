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
    t_data		z;
    t_vector	*m;
    t_vector	*r;

    m = vector_init(sizeof(t_vector *));
    while (1)
    {
        r = vector_init(sizeof(t_data));
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
            vector_append(r, &z);
        }
        vector_append(m, &r);
        free(line);
    }
    close(fd);
    return (m);
}
