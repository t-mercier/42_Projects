/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:12 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:15 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if c is a character from the alphabet */

static int	islower(int c)
{
	return (c > 96 && c < 123);
}

static int	isupper(int c)
{
	return (c > 64 && c < 91);
}

int	ft_isalpha(int c)
{
	return (islower(c) || isupper(c));
}
