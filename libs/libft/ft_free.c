/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_doublearr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 19:15:15 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/03 19:15:15 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_freetab(char **s)
{
	int	i;

	i = -1;
	while (s[i++])
		free(s[i]);
	free(s);
	return (0);
}
