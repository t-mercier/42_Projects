/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:06 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:08 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function f to each character of
 * the string passed as argument, and passing
 * its index as first argument.
 * Each character is passed by address
 * to f to be modified if necessary */

#include "../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	if (s && f)
	{
		while (s[++i])
			(*f)(i, &s[i]);
		s[i] = '\0';
	}
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (0);
	i = -1;
	str = ft_strdup(s);
	if (!*str)
		exit(EXIT_FAILURE);
	while (str[++i])
		str[i] = (*f)(i, str[i]);
	str[i] = '\0';
	return (str);
}
