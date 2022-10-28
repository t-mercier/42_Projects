/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:45:46 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:45:48 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Copies n bytes from memory area libftprintf to memory area dst.
 * If dst and libftprintf overlap, behavior is undefined.
 * Returns the original value of dst. */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((void *)dst == 0 && (void *)src == 0)
		return (0);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
