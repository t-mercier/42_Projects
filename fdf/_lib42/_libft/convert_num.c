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

#include "../inc/libft.h"

char	*ft_itoa(long n, int radix)
{
	char	*s;
	long	tmp;
	int		len;

	tmp = n;
	len = tern_int(n <= 0, 2, 1);
	while (n && ++len)
		n /= 10;
	s = ft_malloc(sizeof(char) * len);
	s[--len] = '\0';
	s[0] = tern_char(tmp <= 0, '-', '0');
	while (tmp)
	{
		s[--len] = tern_long(tmp < 0, -tmp, tmp) % radix + '0';
		tmp /= radix;
	}
	return (s);
}

void	ft_itoa_str(long n, int radix, char *str)
{
	static int		i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	if (n < 0)
		n = -n;
	if (n < 0 && radix == 10)
		s[i] = '-';
	else
		s[i] = n % radix + '0';
	if (n / radix)
		ft_itoa_str(n / radix, radix, str);
	if ((n % radix) < 10)
		s[i++] = (n % radix) + '0';
	else
		s[i++] = (n % radix) + 'a' + 10;
	s[i] = '\0';
}

int	ft_hextodeci(char *hex)
{
	int		n;
	int		x;
	size_t	len;

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
