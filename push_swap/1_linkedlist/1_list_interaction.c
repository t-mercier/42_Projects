/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 14:11:24 by tmercier      #+#    #+#                 */
/*   Updated: 2022/08/01 14:11:24 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_previous_end(t_list *list)
{
	t_node	*tmp;

	tmp = head(list);
	while (tmp->next != tail(list))
		tmp = tmp->next;
	return (tmp);
}

int	list_size(t_list *list)
{
	int		i;
	t_node	*current;

	i = 1;
	if (!list)
		return (0);
	current = head(list);
	while (current != list->tail && i++)
		current = current->next;
	return (i);
}

__attribute__((unused)) void	print_list(t_list *list)
{
	t_node	*ptr;

	ptr = list->head;
	if (!list->head)
		return ;
	while (ptr != list->tail)
	{
		ft_printf("%d ", ptr->content);
		ptr = ptr->next;
	}
	ft_printf("%d\n", ptr->content);
}

void	print_instructions_list(t_list *list)
{
	t_node	*ptr;

	ptr = list->head;
	if (!list->head)
		return ;
	while (ptr != list->tail)
	{
		ft_printf("%s\n", ptr->move);
		ptr = ptr->next;
	}
	ft_printf("%s\n", ptr->move);
}
