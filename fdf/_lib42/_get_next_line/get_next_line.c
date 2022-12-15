/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 19:07:34 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/14 20:47:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "stdio.h"

static char	*_free(char **tmp, int line)
{
	char	*res;

	if (!line)
		res = ft_strdup(*tmp);
	else
		res = NULL;
	free(*tmp);
	*tmp = NULL;
	return (res);
}

char	*ft_get_line(char *line, char *buff)
{
	char	*dl;
	int		size;

	size = ft_strlen(line) - ft_strlen(buff) + 1;
	dl = ft_malloc((size + 1) * sizeof(char));
	dl = ft_strncpy(dl, line, size);
	return (dl);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*dl;
	char		*line;
	char		*old_dl;
	int			b;

	b = read(fd, buff, BUFFER_SIZE);
	if (b < 0)
		exit(EXIT_FAILURE);
	buff[b] = '\0';
	dl = ft_strjoin(dl, buff);
	if (ft_strchr(dl, '\n'))
	{
		line = ft_get_line(dl, ft_strchr(dl, '\n'));
		old_dl = dl;
		dl = ft_strdup(ft_strchr(dl, '\n') + 1);
		free(old_dl);
		return (line);
	}
	else if (b > 0)
		return (get_next_line(fd));
	else if (ft_strchr(dl, '\0') && *dl)
		return (_free(&dl, 0));
	return (_free(&dl, 1));
}
