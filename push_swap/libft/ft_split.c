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

#include "libft.h"
#include <stdlib.h>

static size_t	word_count(char const *s, char c)
{
	size_t	w;

	w = 0;
	while (*s++)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			w += 1;
	}
	return (w);
}

static char	**ft_freetab(char **s)
{
	int	i;

	i = -1;
	while (s[i++])
		free(s[i]);
	free(s);
	return (0);
}

static char	**get_words(char **ptr, char const *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (count < word_count(s, c))
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[j + i] != c && s[j + i] != '\0')
				j++;
			ptr[count] = ft_substr(s, i, j);
			if (!ptr[count])
				return (ft_freetab(ptr));
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
	result = malloc(sizeof(s) * (word_count(s, c) + 1));
	if (!result)
		exit(EXIT_FAILURE);
	return (get_words(result, s, c));
}
