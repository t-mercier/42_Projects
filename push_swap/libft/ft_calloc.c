/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:42:49 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:42:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* The calloc() function contiguously allocates enough space for count
 * objects that are size bytes of memory each and returns a pointer to the
 * allocated memory. The allocated memory is filled with bytes of value zero.
 * Returns a pointer to allocated memory. */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = malloc(count * size);
	if (!ptr)
		exit(EXIT_FAILURE);
	while (++i < count * size)
		*(unsigned char *)(ptr + i) = 0;
	return (ptr);
}
