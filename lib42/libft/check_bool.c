/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:49 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	is_negative(int n)
{
	if ((long int)n < 0)
		return (true);
	return (false);
}

bool	is_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

bool	char_is_found(int c, char const *s)
{
	while (*s)
	{
		if (c == *s)
			return (true);
		s++;
	}
	return (false);
}
