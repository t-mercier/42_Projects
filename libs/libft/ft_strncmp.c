/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:44 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:46 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* strncmp() functions lexicographically compare
 * not more than n characters of the null-terminated
 * strings s1 and s2.
 * Because strncmp() is designed for comparing strings
 * rather than binary data, characters that appear after
 * a `\0' character are not compared.
 * Returns an integer greater than, equal to, or less than 0,
 * according as the string s1 is greater than, equal to,
 * or less than the string s2. */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}
