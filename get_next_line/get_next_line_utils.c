/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 17:56:38 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/14 20:48:23 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*res;
	size_t	strlen;

	strlen = ft_strlen(s1);
	res = ft_calloc(strlen + 1, sizeof(char));
	if (res == 0)
		return (res);
	ft_memcpy(res, (void *)s1, strlen);
	return (res);
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (*(src + i) && i < n)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(str), s2);
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	if (s && c)
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	else if (!c)
		return ((char *)s);
	return (0);
}
