/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:43:09 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/28 13:29:12 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(const char *format, va_list arg)
{
	static int	(*ft_ptr[128])(va_list) = {
	['i'] = ft_putnbr_va_arg,
	['d'] = ft_putnbr_va_arg,
	['c'] = ft_putchar_va_arg,
	['s'] = ft_putstr_va_arg,
	['x'] = ft_lowerhex_va_arg,
	['X'] = ft_upperhex_va_arg,
	['u'] = ft_unsigned_va_arg,
	['p'] = ft_print_address_va_arg,
	};

	if ((ft_ptr)[(int)*format] == NULL)
	{
		ft_putstr_fd("* Calling a flag that doesn't exist!? *", 1);
		return (1);
	}
	return ((ft_ptr[(int)*format])(arg));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += write(1, "%", 1);
			else
				count += ft_convert(format, arg);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (count);
}
