/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:27 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:29 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* strlcpy() copies up to dstsize - 1 characters from the
 * string src to dst, NUL-terminating the result if dstsize is not 0.
 * If the src and dst strings overlap, the behavior is undefined.
 * NUL-termination if there is room.
 * NUL-termination should be included in dstsize (the length of src).
 * Returns the total length of src.
 * If return value is >= dstsize, the output string is truncated. */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = -1;
	if (!dstsize)
		return (len);
	while (src[i] && ++i < dstsize)
		dst[i] = src[i];
	if (i < dstsize)
		dst[i] = '\0';
	else
		dst[i - 1] = '\0';
	return (len);
}
