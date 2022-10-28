/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:48:04 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:48:06 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* The substring is the portion of the object that starts
 * at character position pos and spans len characters (or until
 * the end of the string, whichever comes first).
 * Returns a newly constructed string object with its value
 * initialized to a copy of a substring of this object. */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	sub_str = malloc(sizeof(char *) * (len + 1));
	if (!sub_str)
		exit(EXIT_FAILURE);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
