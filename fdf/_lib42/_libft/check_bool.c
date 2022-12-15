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

#include "../inc/libft.h"

bool	is_negative(int n)
{
	if ((long int)n < 0)
		return (true);
	return (false);
}

bool is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r');
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
