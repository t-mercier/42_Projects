/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:38:22 by tmercier      #+#    #+#                 */
/*   Updated: 2022/03/18 11:16:52 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

char	ft_putchar(char c)
{
	return (write(1, &c, sizeof(c)));
}

int	ft_strlen(char *s)
{
	int i;
	for (i = 0; s[i]; i++);
	return i;
}

int	ft_nbrlen(int n, int base)
{
	int i;
	
	if (n == 0)
		return 1;
	if (n < 0)
		n *= -1;
	for (i = 0; n != 0; i++)
		n /= base;
	return i;
}

void	ft_putnbr(ssize_t n, char *tab)
{
	int base = ft_strlen(tab);
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n > base - 1)
		ft_putnbr(n / base, tab);
	ft_putchar(tab[n % base]);
}

int	flag_is_s(va_list arg)
{
	char *s = (char *)va_arg(arg, char *);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	flag_is_d(va_list arg)
{	
	int n = va_arg(arg, int);
	ft_putnbr(n, "0123456789");
	if (n < 0)
		return (ft_nbrlen(n, 10) + 1);
	else
		return (ft_nbrlen(n, 10));	
}

int	flag_is_x(va_list arg)
{
	int n = va_arg(arg, unsigned long);
	ft_putnbr(n, "0123456789abcdef");
	return (ft_nbrlen(n, 16));
}

int	convert(const char *format, va_list arg)
{
	int (*ft_ptr[128])(va_list) = {
		['s'] = flag_is_s,
		['d'] = flag_is_d,
		['x'] = flag_is_x,
	};
	return (ft_ptr[(int)*format](arg));
}

int	ft_printf(const char *format, ...)
{
	int count = 0;
	va_list arg;

	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += write(1, "%", 1);
			else
				count += convert(format, arg);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return count;
}

#include <stdio.h>

int main (void)
{
	ft_printf("hello %d is %x in %s\n", 10, 16, "hexa");
	printf("hello %d is %x in %s", 10, 16, "hexa");
	return 0;
}