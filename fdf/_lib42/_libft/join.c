/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:19 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:20 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* strlcat() appends string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 characters.
 * It will then NUL-terminate, unless size is 0
 * or the original dst string was longer than size
 * (in practice this should not happen as it means that either
 * size is incorrect or that dst is not a proper string).
 *
 * If the src and dst strings overlap, the behavior is undefined. */

#include "../inc/libft.h"

static size_t	ft_strnlen(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strnlen(dst, size);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (s_len + size);
	if (s_len < size - d_len)
		ft_memcpy(dst + d_len, src, s_len + 1);
	else
	{
		ft_memcpy(dst + d_len, src, size - d_len - 1);
		dst[size - 1] = '\0';
	}
	return (s_len + d_len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	l;
	char	*s;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	l = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)ft_malloc(l + 1);
	ft_strcpy(s, s1);
	ft_strcpy(s + ft_strlen(s1), (char *)s2);
	s[l] = '\0';
	free(s1);
	return (s);
}
