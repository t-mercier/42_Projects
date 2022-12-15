/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 11:56:48 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/13 11:56:48 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../_inc/libft.h"

char	**ft_free_doublearr(char **s)
{
	int	i;

	i = -1;
	while (s[i++])
		free(s[i]);
	free(s);
	return (0);
}
