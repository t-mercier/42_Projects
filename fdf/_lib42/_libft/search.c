/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:51 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:52 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* locates the first occurrence of c (converted to a char)
 * in the string pointed to by s. The terminating null character
 * is considered to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 * Returns a pointer to the located character. */

#include "../inc/libft.h"

char	*ft_strchr(char const *s, int c)
{
	char	*d;

	d = (char *)s;
	if (d && c)
	{
		while (*d)
		{
			if (*d == (char)c)
				return ((char *)d);
			d++;
		}
	}
	else if (!c)
		return ((char *)d);
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	tofind;
	size_t			i;

	ptr = (unsigned char *)s;
	tofind = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == tofind)
			return (ptr);
		ptr++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len_n;
	size_t	len;

	len = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (n > LONG_MAX)
		n = len;
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < n)
	{
		if ((ft_strncmp(haystack, needle, len_n) == 0))
		{
			if (n < len_n + i)
				return (NULL);
			return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_s;
	char	*ptr_d;

	if (src == dst)
		return (dst);
	ptr_s = (char *)src;
	ptr_d = (char *)dst;
	if (src < dst)
	{
		while (len > 0)
		{
			ptr_d[len - 1] = ptr_s[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len--)
	{
		if ((s[len] == (char)c) || (c == '\0'))
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
