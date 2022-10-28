/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 18:53:59 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/14 20:48:03 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(char *s);
char	*ft_strncpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_get_line(char *line, char *buff);
char	*get_next_line(int fd);
char	*ft_free(char **tmp, int line);

#endif
