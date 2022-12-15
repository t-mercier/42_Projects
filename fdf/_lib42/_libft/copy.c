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

#include "../inc/libft.h"

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

	if (dst == 0 || src == 0)
		return (0);
	d = (char *)dst;
	s = (char const *)src;
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
	size_t	len;

	len = ft_strlen(s);
	res = ft_calloc(len + 1, sizeof(char));
	ft_memcpy(res, (void *)s, len);
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	if (!size)
		return (len);
	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
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
