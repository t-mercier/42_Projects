/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 11:27:49 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 11:27:49 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

void	sort_last_2(t_stack *stack)
{
	push_a(stack, &stack->silent);
	push_a(stack, &stack->silent);
	init_min_max_values_a(stack);
	if (_1_(&stack->a) == stack->a.max)
	{
		if (_2_(&stack->a) == stack->a.prev_max)
			multiple_actions(stack, "sa ra", 1, 2);
		else if (_2_(&stack->a) == stack->a.min)
			rotate(&stack->a, &stack->silent, 'a');
	}
	else if (_1_(&stack->a) == stack->a.min \
	&& _2_(&stack->a) == stack->a.max)
		multiple_actions(stack, "sa ra", 1, 1);
	else if (_1_(&stack->a) == stack->a.prev_max \
	&& _2_(&stack->a) == stack->a.max)
		multiple_actions(stack, "ra", 2);
	else if (_1_(&stack->a) == stack->a.next_min \
	&& _2_(&stack->a) == stack->a.min)
		swap(&stack->a, &stack->silent, 'a');
}

int	cost_move_list_5(int position)
{
	int	cost;

	cost = 0;
	if (position == 5 || position == 2)
		cost = 1;
	else if (position == 4 || position == 3)
		cost = 2;
	else if (position == 1)
		cost = 0;
	return (cost);
}

void	push_closer_list_5(t_stack *stack, int position)
{
	if (position == 5)
		multiple_actions(stack, "va pb", 1, 1);
	else if (position == 4)
		multiple_actions(stack, "va pb", 2, 1);
	else if (position == 3)
		multiple_actions(stack, "ra pb", 2, 1);
	else if (position == 2)
		multiple_actions(stack, "ra pb", 1, 1);
	else if (position == 1)
		push_b(stack, &stack->silent);
}

void	presort_up_5(t_stack *stack)
{
	const t_tab	tab = {.cost = {stack->cost.max, stack->cost.prev_max, \
	stack->cost.next_min, stack->cost.min}};

	push_lower_cost(stack, &tab);
}
//3 5 4 1 2