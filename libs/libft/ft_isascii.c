/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:29 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:30 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if c is a valid character from the ASCII table */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
