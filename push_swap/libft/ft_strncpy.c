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

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
    size_t	i;

    if (!src)
        return (0);
    i = 0;
    while (*(src + i) && i < n)
    {
        *(dst + i) = *(src + i);
        i++;
    }
    *(dst + i) = '\0';
    return (dst);
}
