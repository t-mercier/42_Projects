/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_conversion.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:01:27 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/28 13:38:48 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putchar_va_arg(va_list arg)
{
	unsigned int	c;

	c = (unsigned int)va_arg(arg, unsigned int);
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	ft_putstr_va_arg(va_list arg)
{
	char	*s;

	s = (char *)va_arg(arg, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return ((int)ft_strlen(s));
}

int	ft_print_address_va_arg(va_list arg)
{
	long	n;
	long	p;

	p = 2;
	n = (long)va_arg(arg, long);
	write(1, "0x", 2);
	if (n == 0)
		p += write(1, "0", 1);
	else
	{
		ft_putnbr_fd(n, 16, 1);
		p += ft_numlen(n, 16);
	}
	return ((int)p);
}
