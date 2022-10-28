/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:59 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:01 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* The strdup() function allocates sufficient memory for a copy of the
 * string s1, does the copy, and returns a pointer to it.
 * If insufficient memory is available, NULL is returned. */

#include "libft.h"

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
