/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:45:31 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:45:33 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Locates the first occurrence of c
 * (converted to an unsigned char) in string s.
 * Returns a pointer to the byte located,
 * or NULL if no such byte exists within n bytes. */

#include <stddef.h>

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
