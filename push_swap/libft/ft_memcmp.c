/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:45:36 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:45:37 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 * Returns zero if the two strings are identical, otherwise returns
 * the difference between the first two differing bytes */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
