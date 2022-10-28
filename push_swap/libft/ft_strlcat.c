/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:19 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:20 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* strlcat() appends string src to the end of dst.
 * It will append at most dstsize - strlen(dst) - 1 characters.
 * It will then NUL-terminate, unless dstsize is 0
 * or the original dst string was longer than dstsize
 * (in practice this should not happen as it means that either
 * dstsize is incorrect or that dst is not a proper string).
 *
 * If the src and dst strings overlap, the behavior is undefined. */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (s_len + dstsize);
	i = 0;
	while (src[i] && d_len + i < dstsize - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}
