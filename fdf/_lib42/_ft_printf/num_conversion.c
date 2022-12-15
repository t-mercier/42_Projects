/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num_conversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:57:03 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/28 13:29:09 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putnbr_va_arg(va_list arg)
{
	int	n;

	n = va_arg(arg, int);
	ft_putnbr_fd(n, 10, 1);
	if (n < 0)
		return (ft_numlen(n, 10) + 1);
	else
		return (ft_numlen(n, 10));
}

int	ft_unsigned_va_arg(va_list arg)
{
	unsigned int	n;

	n = va_arg(arg, int);
	ft_putnbr_fd(n, 10, 1);
	return (ft_numlen(n, 10));
}

int	ft_lowerhex_va_arg(va_list arg)
{
	unsigned int	n;

	n = (unsigned int)va_arg(arg, unsigned int);
	ft_putnbr_fd(n, 16, 1);
	return (ft_numlen(n, 16));
}

int	ft_upperhex_va_arg(va_list arg)
{
	unsigned int	n;

	n = (unsigned int)va_arg(arg, unsigned int);
	ft_putnbr_fd(n, 16, 1);
	return (ft_numlen(n, 16));
}
