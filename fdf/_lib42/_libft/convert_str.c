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

#include "../inc/libft.h"

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

	while (is_space(*str))
		str++;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');

	return (res * sign);
}
