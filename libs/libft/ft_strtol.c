/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtol.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:57:07 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/03 18:57:07 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
