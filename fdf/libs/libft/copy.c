/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:55 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:57 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	char const	*s;

	d = (char *)dst;
	s = (char const *)src;
	if (dst == 0 && src == 0)
		exit(EXIT_FAILURE);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	strlen;

	strlen = ft_strlen(s);
	res = ft_calloc(strlen + 1, sizeof(char));
	if (res == 0)
		return (res);
	ft_memcpy(res, (void *)s, strlen);
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (len);
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	else
		dst[i - 1] = '\0';
	return (len);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
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
