/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:56 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:57 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if c is a printable character */

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
