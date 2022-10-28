/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:49 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Locates the first occurrence of the null-terminated
 * string needle in the string haystack, where not more
 * than len characters are searched.  Characters that
 * appear after a `\0' character are not searched.
 *
 * If needle is an empty string, haystack is returned;
 * if needle occurs nowhere in haystack, NULL is returned;
 * otherwise a pointer to the first character of the first
 * occurrence of needle is returned. */

#include "libft.h"

#define LONG_MAX 9223372036854775807

static bool	compare(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (*s1 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
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
		if ((compare(haystack, needle, len_n) == 0))
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
