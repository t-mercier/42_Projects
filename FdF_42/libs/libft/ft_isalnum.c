/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:05 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:08 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if c is a numric or alphabet character */

static int	isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

static int	isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_isalnum(int c)
{
	return (isalpha(c) || isdigit(c));
}
