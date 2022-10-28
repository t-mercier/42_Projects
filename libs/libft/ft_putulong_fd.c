/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putulongnbr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 19:15:30 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/12 19:15:30 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
