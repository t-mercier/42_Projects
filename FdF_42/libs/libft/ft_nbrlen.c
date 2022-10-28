/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 19:15:55 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/03 19:15:55 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(long n, int radix)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n -= -n;
	while (n && ++i)
		n /= radix;
	return (i);
}
