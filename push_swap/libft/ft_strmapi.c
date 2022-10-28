/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:47:40 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:47:41 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function ’f’ to each character of
 * the string ’s’ to create a new string (with malloc(3))
 * resulting from successive applications of ’f’. */

#include "libft.h"

static char	*duplicate(const char *s)
{
	char		*dup;
	size_t		len;
	size_t		i;

	i = -1;
	len = ft_strlen(s);
	if (!*s)
		exit(EXIT_FAILURE);
	dup = malloc(len);
	if (!*dup || !*s)
		exit(EXIT_FAILURE);
	while (++i < len)
		dup[i] = s[i];
	return (dup);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (0);
	i = -1;
	str = duplicate(s);
	if (!*str)
		exit(EXIT_FAILURE);
	while (str[++i])
		str[i] = (*f)(i, str[i]);
	str[i] = '\0';
	return (str);
}
