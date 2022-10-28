/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:04 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:06 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Copies len bytes from string libftprintf to string dst.
 * The two strings may overlap; the copy is always done in
 * a non-destructive manner.
 * Returns the original value of dst. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_s;
	char	*ptr_d;

	if (src == dst)
		return (dst);
	ptr_s = (char *)src;
	ptr_d = (char *)dst;
	if (src < dst)
	{
		while (len > 0)
		{
			ptr_d[len - 1] = ptr_s[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
