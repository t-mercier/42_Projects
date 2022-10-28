/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:51 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:52 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		*ft_realloc(void *ptr, size_t size, size_t old_s)
{
	void	*new_p;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_p = malloc(size);
	ft_memcpy(new_p, ptr, old_s);
	return (new_p);
}
