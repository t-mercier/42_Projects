/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 16:21:42 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/02 16:21:42 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	isdigit(int c)
{
	return (c > 47 && c < 58);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (!isdigit(*str))
		str++;
	if (*(str - 1) == '-')
		sign = -1;
	if (*str == '-')
		str++;
	while (isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
