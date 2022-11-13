/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 19:15:32 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/03 19:15:32 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_itoa(long n, int radix, char *buff)
{
	static int		i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)buff;
	if (n < 0)
		n = -n;
	if (n < 0 && radix == 10)
		res[i++] = '-';
	else
		res[i++] = n % radix + '0';
	if (n / radix)
		ft_itoa(n / radix, radix, buff);
	if ((n % radix) < 10)
		res[i++] = (n % radix) + '0';
	else
		res[i++] = (n % radix) + 'a' + 10;
	res[i] = '\0';
}

int	ft_hextodeci(char *hex)
{
	int		y;
	int		n;
	int		x;
	size_t	len;

	y = 0;
	n = 0;
	len = ft_strlen(hex) - 1;
	while (len--)
	{
		if (*(hex + len) >= '0' && *(hex + len) <= '9')
			x = *(hex + len) - '0';
		else
			x = *(hex + len) - 'A' + 10;
		n = (int)(n + x * pow(16, y));
	}
	return (n);
}
