/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:05 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:08 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if c is a numric or alphabet character */

#include "../inc/libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}
