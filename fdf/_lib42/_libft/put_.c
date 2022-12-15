/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:30 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:31 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(long n, int radix, int fd)
{
	unsigned char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / radix)
		ft_putnbr_fd(n / radix, radix, fd);
	if ((n % radix) < 10)
		c = (n % radix) + '0';
	else
		c = (n % radix) + 'a' + 10;
	write(fd, &c, 1);
}

void	ft_putulong_fd(unsigned long n, int radix, int fd)
{
	unsigned char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / radix)
		ft_putulong_fd(n / radix, radix, fd);
	if ((n % radix) < 10)
		c = (n % radix) + '0';
	else
		c = (n % radix) + 'a' + 10;
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
