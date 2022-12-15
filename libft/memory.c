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

#include "../_inc/libft.h"

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

void	*ft_malloc(ssize_t esz)
{
	void	*ptr;

	ptr = malloc(esz);
	if (ptr != NULL)
		return (ptr);
	exit(EXIT_FAILURE);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = -1;
	while (++i < len)
		*(unsigned char *)(b + i) = (unsigned char)c;
	return (b);
}

void	*ft_realloc(void *ptr, size_t size, size_t old_s)
{
	void	*new_p;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_p = malloc(size);
	ft_memcpy(new_p, ptr, old_s);
	return (new_p);
}

void	ft_bzero(void *s, size_t len)
{
	ft_memset((s), '\0', (len));
}
