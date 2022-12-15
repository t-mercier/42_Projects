/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:42 by tmercier      #+#    #+#                 */
/*   Updated: 2021/12/01 19:22:58 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter.  The array must be
 * i_ended by a NULL pointer.
 * Returns the array of new strings resulting from the split. */

#include "../inc/libft.h"

static char	**get_words(char **ptr, char const *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (count < ft_count_words(s, c))
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[j + i] != c && s[j + i] != '\0')
				j++;
			ptr[count] = ft_substr(s, i, j);
			if (!ptr[count])
			{
				// Free memory and return NULL
				while (count > 0)
					free(ptr[--count]);
				free(ptr);
				return (NULL);
			}
			i += j;
			count++;
		}
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		exit(EXIT_FAILURE);
	result = ft_malloc(sizeof(s) * (ft_count_words(s, c) + 1));
	return (get_words(result, s, c));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		exit(EXIT_FAILURE);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	return (ft_substr(s1, start, end - start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	sub_str = ft_malloc(sizeof(char *) * (len + 1));
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
