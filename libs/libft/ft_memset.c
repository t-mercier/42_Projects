/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:13 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:15 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* The memset() function writes len bytes of value c
 * (converted to an unsigned char) to the string b.
 * Returns its first argument. */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	if (!b)
		return (NULL);
	i = -1;
	while (++i < len)
		*(unsigned char *)(b + i) = (unsigned char)c;
	return (b);
}
