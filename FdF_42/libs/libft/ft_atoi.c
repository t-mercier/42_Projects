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

static int	isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (!isdigit(*str) && *str != '-')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '-')
		str++;
	while (isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
