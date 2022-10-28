/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 10:41:17 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 10:41:17 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_position_and_cost_5(t_stack *stack)
{
	stack->pos.min = position_min(&stack->a);
	stack->pos.next_min = position_next_min(&stack->a);
	stack->pos.max = position_max(&stack->a);
	stack->pos.prev_max = position_prev_max(&stack->a);
	stack->cost.min = cost_move_list_5(stack->pos.min);
	stack->cost.max = cost_move_list_5(stack->pos.max);
	stack->cost.next_min = cost_move_list_5(stack->pos.next_min);
	stack->cost.prev_max = cost_move_list_5(stack->pos.prev_max);
}

void	init_position_and_cost_4(t_stack *stack)
{
	stack->pos.min = position_min(&stack->a);
	stack->pos.next_min = position_next_min(&stack->a);
	stack->pos.max = position_max(&stack->a);
	stack->pos.prev_max = position_prev_max(&stack->a);
	stack->cost.min = cost_move_list_4(stack->pos.min);
	stack->cost.max = cost_move_list_4(stack->pos.max);
	stack->cost.next_min = cost_move_list_4(stack->pos.next_min);
	stack->cost.prev_max = cost_move_list_4(stack->pos.prev_max);
}

bool	is_lower_cost(int cost, int size, const t_tab *tab)
{
	int	i;

	i = 0;
	while (size > 1)
	{
		if (cost > tab->cost[i])
			return (false);
		size--;
		i++;
	}
	return (true);
}

void	push_lower_cost(t_stack *stack, const t_tab *tab)
{
	init_position_and_cost_5(stack);
	if (is_lower_cost(stack->cost.max, 4, tab))
		push_closer_list_5(stack, stack->pos.max);
	else if (is_lower_cost(stack->cost.min, 4, tab))
		push_closer_list_5(stack, stack->pos.min);
	else if (is_lower_cost(stack->cost.prev_max, 4, tab))
		push_closer_list_5(stack, stack->pos.prev_max);
	else if (is_lower_cost(stack->cost.next_min, 4, tab))
		push_closer_list_5(stack, stack->pos.next_min);
}
