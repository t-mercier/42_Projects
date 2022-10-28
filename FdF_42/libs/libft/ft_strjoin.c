/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:13 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:14 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* str_join concatenates all the strings/character arrays
 * passed to it. If 'delim' is not NULL then after every string,
 * the 'delim' string is concatenated.
 * It allocates a new character array whose size is equal to
 * the sum of the lengths of all strings passed to it plus 1
 * (extra 1 for terminating null byte). It then concatenates
 * all the strings passed to it separated by 'delim' string
 * into the newly allocated character array.
 * Returns the pointer to the newly allocated character array.
 * If memory allocation fails then NULL is returned. */

#include "../include/libft.h"
#include "stdio.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t		l;
	char		*s;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	l = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(l + 1);
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcpy(s + ft_strlen(s1), (char *)s2);
	s[l] = '\0';
	free(s1);
	return (s);
}