/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 11:58:55 by tmercier      #+#    #+#                 */
/*   Updated: 2022/05/10 13:11:23 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

bool	stack_is_sorted(t_list *list, int size)
{
	t_node	*tmp;
	int		i;

	i = 1;
	tmp = list->head;
	while (tmp && i++ < size)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	is_reverse_sorted(t_list *list, int size)
{
	t_node	*tmp;
	int		i;

	i = 1;
	tmp = list->head;
	while (tmp && i++ < size)
	{
		if (tmp->content < tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	both_stack_are_sorted(t_stack *stack)
{
	return (stack_is_sorted(&stack->a, stack->chunk.to_sort_a) && \
		is_reverse_sorted(&stack->b, stack->chunk.len_b));
}
