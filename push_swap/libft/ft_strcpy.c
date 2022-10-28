/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:55 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:57 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (dst);
}
