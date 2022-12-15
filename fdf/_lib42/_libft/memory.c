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

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = ft_malloc(count * size);
	while (++i < count * size)
		*(unsigned char *)(ptr + i) = 0;
	return (ptr);
}

void	*ft_malloc(size_t esz)
{
	void *ptr;
	if (esz == 0)
	{
		ft_printf("%s%s", RED, "\nAttempt to allocate 0 bytes of memory, "
			   "this could cause undefined behavior - Exiting Program\n\n");
		exit(EXIT_FAILURE);
	}
	ptr = malloc(esz);
	if (!ptr)
	{
		ft_printf("%s%s", RED, "\nFailed to allocate memory\n\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
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

	if (!ptr)
		return ft_malloc(size);
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (size <= old_s)
		return ptr;
	new_p = ft_malloc(size);
	if (!new_p)
		return NULL;
	ft_memcpy(new_p, ptr, old_s);
	free(ptr);
	return new_p;
}

void	ft_bzero(void *s, size_t len)
{
	ft_memset((s), '\0', (len));
}
