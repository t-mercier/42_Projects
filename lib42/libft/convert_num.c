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
	int n;
	int x;
	size_t len;

	n = 0;
	len = ft_strlen(hex);
	while (len--)
	{
		if (*hex >= '0' && *hex <= '9')
			x = *hex - '0';
		else if (*hex >= 'a' && *hex <= 'f')
			x = *hex - 'a' + 10;
		else if (*hex >= 'A' && *hex <= 'F')
			x = *hex - 'A' + 10;
		n += x * pow(16, len);
		hex++;
	}
	return (n);
}