/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 11:51:13 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 11:51:13 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int tab[], int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i < n)
	{
		tmp = tab[i];
		j = i - 1;
		while (j > -1 && tab[j] > tmp)
		{
			tab[j + 1] = tab[j];
			j -= 1;
		}
		tab[++j] = tmp;
	}
}
