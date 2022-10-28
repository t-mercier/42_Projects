/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:24:28 by tmercier      #+#    #+#                 */
/*   Updated: 2022/09/15 17:24:28 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "storage_classes.h"

bool	sort_5_up(t_stack *stack)
{
	if (stack_is_sorted(&stack->a, list_size(&stack->a)))
		return (true);
	init_position_and_cost_5(stack);
	presort_up_5(stack);
	if (_1_(&stack->b) == stack->a.prev_max)
		push_closer_list_4(stack, position_max(&stack->a));
	else if (_1_(&stack->b) == stack->a.next_min)
		push_closer_list_4(stack, position_min(&stack->a));
	else
		presort_up_4(stack);
	if (!stack_is_sorted(&stack->a, list_size(&stack->a)))
		sort_3_up_a(stack);
	sort_last_2(stack);
	return (true);
}
