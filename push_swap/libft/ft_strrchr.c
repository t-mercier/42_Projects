/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:54 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* The strrchr() function locates the last occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be part
 * of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 *
 * Returns a pointer to the located character,
 * or NULL if the character does not appear in the string. */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((s[len] == (char)c) || (c == '\0'))
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
