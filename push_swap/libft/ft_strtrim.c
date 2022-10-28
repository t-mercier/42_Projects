/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:59 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:48:00 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 *
 * Returns he trimmed string.  NULL if the allocation fails. */

#include "libft.h"

static char	*search(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

static char	*substring(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*str;

	if (!*s)
		exit(EXIT_FAILURE);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < len && i + start < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		exit(EXIT_FAILURE);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && search(set, s1[start]))
		start++;
	while (s1[end - 1] && search(set, s1[end - 1]) && end > start)
		end--;
	return (substring(s1, start, end - start));
}
