/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:48:09 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:48:11 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c) == 1)
		return (c + 32);
	else
		return (c);
}

int	ft_toupper(int c)
{
	if (ft_islower(c) == 1)
		return (c - 32);
	else
		return (c);
}

long	ft_strtol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		errno = EINVAL;
	while (*str)
	{
		if (!ft_isdigit(*str))
			errno = EINVAL;
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (!ft_isdigit(*str) && *str != '-')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
