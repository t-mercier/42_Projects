/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:29:43 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/04 14:29:43 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	process_args(int argc, char **argv, t_list *list)
{
	int		j;
	long	n;

	j = 0;
	while (++j < argc)
	{
		n = ft_strtol(argv[j]);
		if (errno == EINVAL || !is_integer(n))
			return (false);
		add_last(&list, create_node((int)n));
		if (is_duplicated(list, (int)n))
			return (false);
	}
	return (true);
}

bool	fill_stack(int argc, char **argv, t_list *list)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (ft_strlen(argv[1]) == 0)
		return (false);
	if (argc >= 2 && ((ft_isdigit(argv[1][0]) || argv[1][0] == '-') \
	|| argv[1][0] == '+'))
		return (process_args(argc, argv, list));
	else
		return (false);
}
