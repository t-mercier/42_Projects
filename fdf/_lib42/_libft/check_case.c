/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:49 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:43:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_islower(int c)
{
	return (c > 96 && c < 123);
}

int	ft_isupper(int c)
{
	return (c > 64 && c < 91);
}
