/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:44:11 by tmercier      #+#    #+#                 */
/*   Updated: 2021/12/15 16:36:54 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative nbers must be handled.
 * Returns the string representing the integer.
 * NULL if the allocation fails. */

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
