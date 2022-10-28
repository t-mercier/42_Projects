/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraycmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 10:52:05 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 10:52:05 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdbool.h"
#include "unistd.h"

bool	ft_intncmp(int *t1, int *t2, size_t n)
{
	while (n-- > 0)
	{
		if (*t1 == *t2)
		{
			t1++;
			t2++;
		}
		else
			return (false);
	}
	return (true);
}
