/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/17 11:29:12 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/17 11:29:12 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_closer_list_4(t_stack *stack, int position)
{
	if (position == 4)
		multiple_actions(stack, "va pb", 1, 1);
	else if (position == 3)
		multiple_actions(stack, "ra pb", 2, 1);
	else if (position == 2)
		multiple_actions(stack, "ra pb", 1, 1);
	else if (position == 1)
		push_b(stack, &stack->silent);
}

int	cost_move_list_4(int position)
{
	int	cost;

	if (position == 4 || position == 2)
		cost = 1;
	else if (position == 3)
		cost = 2;
	else
		cost = 0;
	return (cost);
}

void	presort_up_4(t_stack *stack)
{
	init_position_and_cost_4(stack);
	if (stack->cost.max <= stack->cost.min)
		push_closer_list_4(stack, stack->pos.max);
	else
		push_closer_list_4(stack, stack->pos.min);
}
