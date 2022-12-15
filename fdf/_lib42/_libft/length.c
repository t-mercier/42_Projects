/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:35 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:37 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_numlen(long n, int radix)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n -= -n;
	while (n && ++i)
		n /= radix;
	return (i);
}

size_t	ft_count_words(char const *s, char c)
{
	size_t	w;

	w = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			w += 1;
		s++;
	}
	return (w);
}
