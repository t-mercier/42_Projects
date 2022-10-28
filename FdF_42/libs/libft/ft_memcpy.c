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

#include "../include/libft.h"
#include "stdio.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	char const	*s;

	d = (char *)dst;
	s = (char const *)src;
	if (dst == 0 && src == 0)
		exit(EXIT_FAILURE);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
