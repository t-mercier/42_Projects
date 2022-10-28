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

#include "libft.h"

static char	*p_strcpy(char *dst, char *src, int *len)
{
	int	j;
	int	i;

	i = *len;
	j = 0;
	while (*(src + j))
	{
		*(dst + i) = *(src + j);
		i += 1;
		j++;
	}
	*len = i;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	ptr = (char *)malloc(i + j + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (s1)
		p_strcpy(ptr, (char *)s1, &i);
	p_strcpy(ptr, (char *)s2, &i);
	ptr[i] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}
